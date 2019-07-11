#include <QCoreApplication>

#include "mytcp.h"
#include "parse.h"
#include <QThread>
#include "packet_antenna_feeder_subsystem_status.h"
#include "mymethod.h"
#if CLOSE_IF
void test(QString name)
{
    Mysqltool tool(name);
    QString sql = QString("insert into antenna_feeder_subsystem_two_side_fault (bid) values(%1)").arg(100);
    tool.exec(sql);
}
#endif

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#if OPEN_IF
    //线程对象,承载tcp和解析
    QThread tcpThread,parseThread;
    //全局对象
    Mytcp tcp;//开启tcp对象
    Parse parse;//解析对象
    //信号槽连接
    QObject::connect(&tcp,SIGNAL(getSourceDataSignal(QByteArray)),&parse,SLOT(getSoucreDataSlot(QByteArray)));
    //开启服务
    tcp.moveToThread(&tcpThread);
    tcpThread.start();//开启tcp运行线程
    tcp.connect(SERVER_IP,SERVER_PORT);//连接服务器
    parse.moveToThread(&parseThread);
    parseThread.start();//开启解析线程
    parse.init();//解析对象初始化
#endif

#if CLOSE_IF
    std::thread t1(test,"test1");
    std::thread t2(test,"test2");

    t1.detach();
    t2.detach();

#endif

#if CLOSE_IF
    {
        Antenna_feeder_subsystem_status* s = new Antenna_feeder_subsystem_status;
        memset(s,0,sizeof(Antenna_feeder_subsystem_status));
        s->header[0] = 0x11;
        Packet_Antenna_Feeder_Subsystem_Status p(s,0);
        p.setTime(Mymethod::getCurentTimeStr());
        p.exec();
    }
#endif
    return a.exec();
}
