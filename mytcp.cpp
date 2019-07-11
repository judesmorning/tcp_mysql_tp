#include "mytcp.h"
#include "includes.h"
#include "mymethod.h"

Mytcp::Mytcp(QObject *parent) : QObject(parent)
{
    socket = NULL;
    QObject::connect(this,SIGNAL(connectSignal(QString,uint)),this,SLOT(connectSlot(QString,uint)));//连接服务器信号槽
    Mymethod::record("tcp客户端类初始化");
}

/*****************************************************************/
//作者:朱小勇
//函数名称:外部调用函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
void Mytcp::connect(QString ip, uint port)
{
    emit connectSignal(ip,port);
    Mymethod::record("准备连接服务器");
}

/*****************************************************************/
//作者:曹泽文
//函数名称:连接函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
void Mytcp::connectSlot(QString ip, uint port)
{
    if(NULL==socket)
    {
        socket = new QTcpSocket;
        QObject::connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(tcpStateChangeSlot(QAbstractSocket::SocketState)));//状态变化信号槽
        Mymethod::record("为tcp客户端对象分配空间");
    }
    QObject::connect(socket,SIGNAL(readyRead()),this,SLOT(recSlot()));
    socket->connectToHost(ip,port);//连接服务器
    Mymethod::record("连接服务器");
}

/*****************************************************************/
//作者:曹泽文
//函数名称:接收函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
void Mytcp::recSlot()
{
    RET_IF_EAQU(socket,nullptr);//如果为空则返回
    QByteArray ba = socket->readAll();
    emit getSourceDataSignal(ba);
}

/*****************************************************************/
//作者:朱小勇
//函数名称:状态变化槽函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
void Mytcp::tcpStateChangeSlot(QAbstractSocket::SocketState socketState)
{
    if (QAbstractSocket::ConnectedState == socketState)
    {
       Mymethod::record("成功连接至服务器...");
    }
    else if (QAbstractSocket::ConnectingState == socketState)
    {
        Mymethod::record("正在寻找服务器...");
    }
    else if (QAbstractSocket::UnconnectedState == socketState)
    {
        Mymethod::record("断开连接!!!");
    }
}
