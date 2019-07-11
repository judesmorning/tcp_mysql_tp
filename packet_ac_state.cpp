#include "packet_ac_state.h"

/*****************************************************************/
//作者:朱小勇
//函数名称:构造函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
Packet_AC_State::Packet_AC_State(void* data,int length) : AbsPacket(data,length)
{
    m_s = (AC_State*)this->pData;
}

/*****************************************************************/
//作者:朱小勇
//函数名称:析构函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
Packet_AC_State::~Packet_AC_State()
{
    //只能在子类中析构,delete void*指针并不能触发析构函数
    std::cout << "destroy packet object" << std::endl;
    delete m_s;//或者delet (Servo_Subsystem*)pData;
    m_s = nullptr;
}

/*****************************************************************/
//作者:朱小勇
//函数名称:执行函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
void Packet_AC_State::exec()
{
//    std::cout << "sum is:" << (int)m_s->check_sum << std::endl;
    Mymethod::record(QString(__FILE__));
}
