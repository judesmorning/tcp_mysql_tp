#include "myrun.h"

Myrun::Myrun(AbsPacket* packet,QObject *parent) : QObject(parent)
{
    this->packet = packet;
}


void Myrun::run()
{
    if(nullptr != packet)
    {
        //try
        {
            packet->exec();
            delete packet;
            packet = nullptr;
        }
    }
}
