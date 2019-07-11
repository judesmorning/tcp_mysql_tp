#ifndef ABSPACKET_H
#define ABSPACKET_H
#include <string>
#include "includes.h"
#include <QString>
#include "mymethod.h"
#include "mysqltool.h"
class AbsPacket
{
public:
    AbsPacket(void* data,int length);
    virtual ~AbsPacket();
    virtual void exec() = 0;
    void setPacketName(QString packetName){m_name = packetName;}
    QString getPacketName() const{return m_name;}
    int getLength() const{return length;}
    void setBid(int bid){this->bid = bid;}
    void setTime(QString str){this->timeStr = str;}
protected:
    QString m_name;       //报文名字
    void *pData = nullptr;//指向结构体的指针
    int length;           //结构体长度
    QString timeStr;      //当前时间
    int bid = NO_BID;
};


class PacketConfig
{
private:
    static PacketConfig *instance;
    PacketConfig()=default;
//    std::vector<QByteArray> vcHead;
//    QByteArray ALL_HEAD;
public:
    static PacketConfig* getInstace();
    QByteArray getAllHead();
    std::vector<QByteArray> getHeads();
};






#endif // ABSPACKET_H
