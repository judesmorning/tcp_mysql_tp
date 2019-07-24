#include "parse.h"

Parse::Parse(QObject *parent) : QObject(parent)
{

}

Parse::~Parse()
{
    TP_FLAG_RUN = false;
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

    std::thread getPcketThread(&Parse::getPacket,this);
    getPcketThread.detach();
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
    Mymethod::record("接收数据:"+ba.toHex().toUpper());
    tcpData.append(ba);
    int head = tcpData.indexOf(PacketConfig::getInstace()->getAllHead());//报文头的位置
    QByteArray currentBa;
    while (NOT_FOUND != head)
    {
        tcpData = tcpData.mid(head);//去掉报头之前的,此处应该加锁
        if (tcpData.size() >= PACKET_ALL_LENTH)//长度够,进行解析
        {
            currentBa = tcpData.mid(MID_FROM_ZERO, PACKET_ALL_LENTH);//获取当前完整包
            if(Mymethod::getPacketType(currentBa))//如果是正常包
            {
                AllStruct* allStruct = new AllStruct;
                memcpy(allStruct,currentBa.data(),PACKET_ALL_LENTH);
                {
                    std::unique_lock<std::mutex> lck(m_data_mutex);
                    allData.push(allStruct);
                    Mymethod::record("在数据流中解析到一个完整包");
                }
                m_cv_data.notify_one();
                tcpData = tcpData.mid(PacketConfig::getInstace()->getAllHead().size());
            }
        }
        else
        {
            break;//长度不够,退出
        }
        head = tcpData.indexOf(PacketConfig::getInstace()->getAllHead());//刷新报文头的位置
    }
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
    AllStruct allStruct;
    while (TP_FLAG_RUN)
    {
        memset(&allStruct,VALUE_ZERO,sizeof(AllStruct));
        {
            std::unique_lock<std::mutex> lck(m_data_mutex);
            while(allData.empty())
            {
                m_cv_data.wait(lck);
            }
            AllStruct* pAllStruct = allData.front();
            allData.pop();
            memcpy(&allStruct,pAllStruct,PACKET_ALL_LENTH);
            delete pAllStruct;
            pAllStruct = nullptr;
        }
        /*存主表,并获取bid*/
        //伺服分系统状态报文
        QString timeStr = Mymethod::getCurentTimeStr();
        Servo_Subsystem *s = new Servo_Subsystem;
        memcpy(s,&(allStruct.servo_Subsystem),sizeof(Servo_Subsystem));
        Packet_Servo_Subsystem* packet_Servo_Subsystem = new Packet_Servo_Subsystem(s,sizeof(Servo_Subsystem));
        packet_Servo_Subsystem->setTime(timeStr);
        int id = packet_Servo_Subsystem->exec_id();
        delete packet_Servo_Subsystem;
        packet_Servo_Subsystem = nullptr;
        /*初始化其他报文类*/

        //发射分系统状态报文
        Transmit_subsystem* transmit_subsystem = new Transmit_subsystem;
        memcpy(transmit_subsystem,&(allStruct.transmit_subsystem),sizeof(Transmit_subsystem));
        Packet_Transmit_Subsystem* packet_Transmit_Subsystem = new Packet_Transmit_Subsystem(transmit_subsystem,sizeof(Transmit_subsystem));
        packet_Transmit_Subsystem->setBid(id);//设置bid
        packet_Transmit_Subsystem->setPacketName("发射分系统状态报文");//设置报文类型
        packet_Transmit_Subsystem->setTime(timeStr);
        /*存入队列*/
        {
            {
                std::unique_lock<std::mutex> lck(m_queue_mutex);
                allPacket.push(packet_Transmit_Subsystem);
            }
            m_cv_packet.notify_one();
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
    while(TP_FLAG_RUN)
    {
        {
            std::unique_lock<std::mutex> lck(m_queue_mutex);
            while(allPacket.empty())
            {
                m_cv_packet.wait(lck);
            }
            AbsPacket* p = allPacket.front();
            tp.start(new Myrun(p));
            allPacket.pop();
        }
    }
    Mymethod::record("退出线程池调度线程");
}
