#ifndef PACKET_SERVO_SUBSYSTEM_H
#define PACKET_SERVO_SUBSYSTEM_H
#include "abspacket.h"

class Packet_Servo_Subsystem : public AbsPacket
{
public:
    Packet_Servo_Subsystem(void* data,int length);
    virtual ~Packet_Servo_Subsystem();
    virtual void exec();
    int exec_id();
private:
    Servo_Subsystem *m_s;
};

#endif // PACKET_SERVO_SUBSYSTEM_H
