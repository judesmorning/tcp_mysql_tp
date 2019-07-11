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
    std::vector<QByteArray> vcHead;
    QByteArray HEAD;
    HEAD.resize(2);
    HEAD[0] = 0x88;
    HEAD[1] = 0xAA;
    vcHead.push_back(HEAD);

    HEAD[0] = 0xAA;
    HEAD[1] = 0xBB;
    vcHead.push_back(HEAD);


    HEAD[0] = 0x99;
    HEAD[1] = 0xAA;
    vcHead.push_back(HEAD);

    HEAD[0] = 0x10;
    HEAD[1] = 0xAA;
    vcHead.push_back(HEAD);

    HEAD[0] = 0xDD;
    HEAD[1] = 0x88;
    vcHead.push_back(HEAD);

    HEAD[0] = 0x11;
    HEAD[1] = 0xAA;
    vcHead.push_back(HEAD);

    HEAD[0] = 0x22;
    HEAD[1] = 0xAA;
    vcHead.push_back(HEAD);

    HEAD[0] = 0x33;
    HEAD[1] = 0xAA;
    vcHead.push_back(HEAD);

    HEAD[0] = 0x44;
    HEAD[1] = 0xAA;
    vcHead.push_back(HEAD);

    HEAD[0] = 0x55;
    HEAD[1] = 0xAA;
    vcHead.push_back(HEAD);

    HEAD[0] = 0x66;
    HEAD[1] = 0xAA;
    vcHead.push_back(HEAD);

    HEAD[0] = 0x77;
    HEAD[1] = 0xAA;
    vcHead.push_back(HEAD);

    HEAD[0] = 0xBB;
    HEAD[1] = 0xCC;
    vcHead.push_back(HEAD);

    HEAD[0] = 0x11;
    HEAD[1] = 0xCC;
    vcHead.push_back(HEAD);

    HEAD[0] = 0x66;
    HEAD[1] = 0xBB;
    vcHead.push_back(HEAD);

    HEAD[0] = 0x11;
    HEAD[1] = 0xBB;
    vcHead.push_back(HEAD);

    HEAD.resize(3);
    HEAD[0] = 0xBB;
    HEAD[1] = 0x99;
    HEAD[2] = 0x09;
    vcHead.push_back(HEAD);

    HEAD.resize(12);uchar tmp[12] = {0x67,0x89,0x56,0x78,0x45,0x67,0x34,0x56,0x23,0x45,0x12,0x34};
    memcpy(HEAD.data(),tmp,12);
    vcHead.push_back(HEAD);

    HEAD.resize(12);uchar tmp1[12] = {0x43,0x21,0x54,0x32,0x65,0x43,0x76,0x54,0x87,0x65,0x98,0x76};
    memcpy(HEAD.data(),tmp1,12);
    vcHead.push_back(HEAD);

    return vcHead;
}
