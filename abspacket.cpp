#include "abspacket.h"

AbsPacket::AbsPacket(void* data,int length)
{
    this->pData = data;
    this->length = length;
}

AbsPacket::~AbsPacket()
{
    pData = nullptr;
}


PacketConfig* PacketConfig::instance = nullptr;
PacketConfig* PacketConfig::getInstace()
{
    if(instance == nullptr)
    {
        instance = new PacketConfig;
    }
    return instance;
}
/*****************************************************************/
//作者:朱小勇
//函数名称:获取整个报文头88aa
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
QByteArray PacketConfig::getAllHead()
{
    QByteArray ALL_HEAD;
    ALL_HEAD.resize(2);
    ALL_HEAD[0] = 0x88;ALL_HEAD[1] = 0xAA;
    return ALL_HEAD;
}

/*****************************************************************/
//作者:朱小勇
//函数名称:获取所有报文头集合
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
std::vector<QByteArray> PacketConfig::getHeads()
{
    
    return vcHead;
}
