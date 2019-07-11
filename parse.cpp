#include "parse.h"

Parse::Parse(QObject *parent) : QObject(parent)
{

}


/*****************************************************************/
//作者:朱小勇
//函数名称:初始化
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
void Parse::init()
{
    std::thread execPcketThread(&Parse::doExec,this);
    execPcketThread.detach();
}

/*****************************************************************/
//作者:朱小勇
//函数名称:获取原始数据槽函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
void Parse::getSoucreDataSlot(const QByteArray &ba)
{
    {
        std::lock_guard<std::mutex> lck(m_data_mutex);
        allData.append(ba);
        Mymethod::record("rcvData:"+ba.toHex().toUpper());
        Mymethod::record("allData:"+allData.toHex().toUpper());
    }
    std::thread getPacketThread(&Parse::getPacket,this);
    getPacketThread.detach();
}
/***********************************************/
// z 函数名称:allData->allPacket
// h 函数作用:NULL
// u 函数参数:NULL
// x 函数返回值:NULL
// y 备注:先插入第一个结构体,其id作为其他结构体的bid
/***********************************************/
void Parse::getPacket()
{
    Mymethod::record("进入解析线程");
    std::lock_guard<std::mutex> lck(m_data_mutex);//给当前线程加锁
    int head = allData.indexOf(PacketConfig::getInstace()->getAllHead());//报文头的位置
    QByteArray currentBa;
    while (NOT_FOUND != head)
    {
        allData = allData.mid(head);//去掉报头之前的,此处应该加锁
        if (allData.size() >= PACKET_ALL_LENTH)//长度够,进行解析
        {
            currentBa = allData.mid(MID_FROM_ZERO, PACKET_ALL_LENTH);//获取当前完成包
            if(Mymethod::getPacketType(currentBa))//如果是正常包
            {
                /*开始一次大包解析*/
                //存入队列
                AllStruct allStruct;
                memset(&allStruct,MID_FROM_ZERO,sizeof(AllStruct));
                memcpy(&allStruct,currentBa.data(),sizeof(AllStruct));



                /*存主表,并获取bid*/
                //伺服分系统状态报文
                QString timeStr = Mymethod::getCurentTimeStr();
                Servo_Subsystem *s = new Servo_Subsystem;
                memcpy(s,&(allStruct.servo_Subsystem),sizeof(Servo_Subsystem));
                Packet_Servo_Subsystem* packet_Servo_Subsystem = new Packet_Servo_Subsystem(s,sizeof(Servo_Subsystem));
                packet_Servo_Subsystem->setTime(timeStr);
				packet_Servo_Subsystem->setPacketName("伺服分系统状态报文");//设置报文类型
                /*初始化其他报文类*/
                //发射分系统状态报文
                Transmit_subsystem* transmit_subsystem = new Transmit_subsystem;
                memcpy(transmit_subsystem,&(allStruct.transmit_subsystem),sizeof(Transmit_subsystem));
                Packet_Transmit_Subsystem* packet_Transmit_Subsystem = new Packet_Transmit_Subsystem(transmit_subsystem,sizeof(Transmit_subsystem));
                packet_Transmit_Subsystem->setBid(0);//设置bid
                packet_Transmit_Subsystem->setPacketName("发射分系统状态报文");//设置报文类型
                packet_Transmit_Subsystem->setTime(timeStr);
                
                /*存入队列*/
                {
                    std::lock_guard<std::mutex> lck(m_queue_mutex);
                    allPacket.push(packet_Transmit_Subsystem);
                }
                /*结束一次大包解析*/
                //去掉头以做下次循环
                allData = allData.mid(PacketConfig::getInstace()->getAllHead().size());
            }
            else
            {
                break;
            }
            head = allData.indexOf(PacketConfig::getInstace()->getAllHead());//刷新报文头的位置
        }
    }
    Mymethod::record("退出解析线程");
}

/*****************************************************************/
//作者:朱小勇
//函数名称:线程池调度
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
void Parse::doExec()
{
    //线程池
    Mymethod::record("进入线程池调度线程");
    QThreadPool tp;
    tp.setMaxThreadCount(TP_COUNT);
    while(true)
    {
        if(!allPacket.empty())
        {
            {
                std::lock_guard<std::mutex> lck(m_queue_mutex);
                AbsPacket* p = allPacket.front();
                tp.start(new Myrun(p));
                allPacket.pop();
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(TP_WAITE_TIME));
    }
    Mymethod::record("退出线程池调度线程");
}
