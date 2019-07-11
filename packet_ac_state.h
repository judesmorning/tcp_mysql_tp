#ifndef PACKET_AC_STATE_H
#define PACKET_AC_STATE_H
#include "abspacket.h"

class Packet_AC_State : public AbsPacket
{
public:
    Packet_AC_State(void* data,int length);
    virtual ~Packet_AC_State();
    virtual void exec();
private:
    AC_State *m_s;
};

#endif // PACKET_AC_STATE_H
