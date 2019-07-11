#ifndef PACKET_TRANSMIT_SUBSYSTEM_H
#define PACKET_TRANSMIT_SUBSYSTEM_H
#include "abspacket.h"

class Packet_Transmit_Subsystem : public AbsPacket
{
public:
    Packet_Transmit_Subsystem(void* data,int length);
    virtual ~Packet_Transmit_Subsystem();
    virtual void exec();
private:
    Transmit_subsystem *m_s;
};

#endif // PACKET_TRANSMIT_SUBSYSTEM_H
