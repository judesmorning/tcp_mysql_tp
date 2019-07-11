#include "packet_servo_subsystem.h"
#include "mysqltool.h"

/*****************************************************************/
//作者:朱小勇
//函数名称:构造函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
Packet_Servo_Subsystem::Packet_Servo_Subsystem(void* data,int length) : AbsPacket(data,length)
{
    m_s = (Servo_Subsystem*)this->pData;
}

/*****************************************************************/
//作者:朱小勇
//函数名称:析构函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
Packet_Servo_Subsystem::~Packet_Servo_Subsystem()
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
void Packet_Servo_Subsystem::exec()
{
    //std::cout << "Packet_Servo_Subsystem sum is:" << (int)m_s->check_sum << std::endl;
    Mymethod::record(QString(__FILE__));
    Mysqltool tool("Packet_Servo_Subsystem");
    QString sql = QString("insert into servo_subsystem(bid,date,running_mode,running_state,driver_loopback_mode,cmd_exec_state,self_remote_control,alarm_bell_state,drying_machine_state,slot_pull_arrive,slot_insert_arrive,environment_temperature,environment_humidity,slip_ring_temperature,slip_ring_humidity,wind_speed,a_bait_switch_state,b_bait_switch_state,antenna_direction_code)values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17','%18','%19')")
            .arg(bid)
            .arg(timeStr)
            .arg(m_s->running_mode)
            .arg(m_s->running_state)
            .arg(m_s->m_Union_Byte_6.s.driver_loopback_mode)
            .arg(m_s->m_Union_Byte_6.s.cmd_exec_state)
            .arg(m_s->m_Union_Byte_7.s.self_remote_control)
            .arg(m_s->m_Union_Byte_7.s.alarm_bell_state)
            .arg(m_s->m_Union_Byte_7.s.drying_machine_state)
            .arg(m_s->m_Union_Byte_7.s.slot_pull_arrive)
            .arg(m_s->m_Union_Byte_7.s.slot_insert_arrive)
            .arg((m_s->environment_temperature_hight<<8)+m_s->environment_temperature_low)
            .arg((m_s->environment_humidity_hight<<8)+m_s->environment_humidity_low)
            .arg((m_s->slip_ring_temperature_hight<<8)+m_s->slip_ring_temperature_low)
            .arg((m_s->slip_ring_humidity_hight<<8)+m_s->slip_ring_humidity_low)
            .arg((m_s->wind_speed_hight<<8)+m_s->wind_speed_low)
            .arg(m_s->m_Union_Byte_18.s.a_bait_switch_state)
            .arg(m_s->m_Union_Byte_18.s.b_bait_switch_state)
            .arg((m_s->antenna_direction_code_hight<<8)+m_s->antenna_direction_code_low);
    tool.exec(sql);
}

/*****************************************************************/
//作者:朱小勇
//函数名称:执行函数,可返回bid
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
int Packet_Servo_Subsystem::exec_id()
{
    int ret = NO_BID;
    this->exec();

    return ret;
}
