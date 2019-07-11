#include "packet_transmit_subsystem.h"
#include "mysqltool.h"

/*****************************************************************/
//作者:朱小勇
//函数名称:构造函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
Packet_Transmit_Subsystem::Packet_Transmit_Subsystem(void* data,int length) : AbsPacket(data,length)
{
    m_s = (Transmit_subsystem*)this->pData;
}

/*****************************************************************/
//作者:朱小勇
//函数名称:析构函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
Packet_Transmit_Subsystem::~Packet_Transmit_Subsystem()
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
void Packet_Transmit_Subsystem::exec()
{
    //    std::cout << "Packet_Transmit_Subsystem sum is:" << (int)m_s->check_sum << std::endl;
    Mymethod::record(QString(__FILE__));
    int module_num = 1;
    Mysqltool tool("Packet_Transmit_Subsystem");
    QString str="";
    QString sql = QString("insert into transmit_subsystem_power_module_state(bid,date,module_num,wave_failure,power_failure,total_failure,radio_frequency,temperature)values").arg(str);
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_4.s.power_module_1_wave_failure)
            .arg(m_s->m_Union_Byte_4.s.power_module_1_power_failure)
            .arg(m_s->m_Union_Byte_4.s.power_module_1_total_failure)
            .arg(m_s->m_Union_Byte_4.s.power_module_1_radio_frequency)
            .arg(m_s->power_module_1_temperature);
    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_7.s.power_module_2_wave_failure)
            .arg(m_s->m_Union_Byte_7.s.power_module_2_power_failure)
            .arg(m_s->m_Union_Byte_7.s.power_module_2_total_failure)
            .arg(m_s->m_Union_Byte_7.s.power_module_2_radio_frequency)
            .arg(m_s->power_module_2_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_10.s.power_module_3_wave_failure)
            .arg(m_s->m_Union_Byte_10.s.power_module_3_power_failure)
            .arg(m_s->m_Union_Byte_10.s.power_module_3_total_failure)
            .arg(m_s->m_Union_Byte_10.s.power_module_3_radio_frequency)
            .arg(m_s->power_module_3_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_13.s.power_module_4_wave_failure)
            .arg(m_s->m_Union_Byte_13.s.power_module_4_power_failure)
            .arg(m_s->m_Union_Byte_13.s.power_module_4_total_failure)
            .arg(m_s->m_Union_Byte_13.s.power_module_4_radio_frequency)
            .arg(m_s->power_module_4_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_16.s.power_module_5_wave_failure)
            .arg(m_s->m_Union_Byte_16.s.power_module_5_power_failure)
            .arg(m_s->m_Union_Byte_16.s.power_module_5_total_failure)
            .arg(m_s->m_Union_Byte_16.s.power_module_5_radio_frequency)
            .arg(m_s->power_module_5_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_19.s.power_module_6_wave_failure)
            .arg(m_s->m_Union_Byte_19.s.power_module_6_power_failure)
            .arg(m_s->m_Union_Byte_19.s.power_module_6_total_failure)
            .arg(m_s->m_Union_Byte_19.s.power_module_6_radio_frequency)
            .arg(m_s->power_module_6_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_22.s.power_module_7_wave_failure)
            .arg(m_s->m_Union_Byte_22.s.power_module_7_power_failure)
            .arg(m_s->m_Union_Byte_22.s.power_module_7_total_failure)
            .arg(m_s->m_Union_Byte_22.s.power_module_7_radio_frequency)
            .arg(m_s->power_module_7_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_25.s.power_module_8_wave_failure)
            .arg(m_s->m_Union_Byte_25.s.power_module_8_power_failure)
            .arg(m_s->m_Union_Byte_25.s.power_module_8_total_failure)
            .arg(m_s->m_Union_Byte_25.s.power_module_8_radio_frequency)
            .arg(m_s->power_module_8_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_28.s.power_module_9_wave_failure)
            .arg(m_s->m_Union_Byte_28.s.power_module_9_power_failure)
            .arg(m_s->m_Union_Byte_28.s.power_module_9_total_failure)
            .arg(m_s->m_Union_Byte_28.s.power_module_9_radio_frequency)
            .arg(m_s->power_module_9_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_31.s.power_module_10_wave_failure)
            .arg(m_s->m_Union_Byte_31.s.power_module_10_power_failure)
            .arg(m_s->m_Union_Byte_31.s.power_module_10_total_failure)
            .arg(m_s->m_Union_Byte_31.s.power_module_10_radio_frequency)
            .arg(m_s->power_module_10_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_34.s.power_module_11_wave_failure)
            .arg(m_s->m_Union_Byte_34.s.power_module_11_power_failure)
            .arg(m_s->m_Union_Byte_34.s.power_module_11_total_failure)
            .arg(m_s->m_Union_Byte_34.s.power_module_11_radio_frequency)
            .arg(m_s->power_module_11_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_37.s.power_module_12_wave_failure)
            .arg(m_s->m_Union_Byte_37.s.power_module_12_power_failure)
            .arg(m_s->m_Union_Byte_37.s.power_module_12_total_failure)
            .arg(m_s->m_Union_Byte_37.s.power_module_12_radio_frequency)
            .arg(m_s->power_module_12_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_40.s.power_module_13_wave_failure)
            .arg(m_s->m_Union_Byte_40.s.power_module_13_power_failure)
            .arg(m_s->m_Union_Byte_40.s.power_module_13_total_failure)
            .arg(m_s->m_Union_Byte_40.s.power_module_13_radio_frequency)
            .arg(m_s->power_module_13_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_43.s.power_module_14_wave_failure)
            .arg(m_s->m_Union_Byte_43.s.power_module_14_power_failure)
            .arg(m_s->m_Union_Byte_43.s.power_module_14_total_failure)
            .arg(m_s->m_Union_Byte_43.s.power_module_14_radio_frequency)
            .arg(m_s->power_module_14_temperature);

    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8'),")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_46.s.power_module_15_wave_failure)
            .arg(m_s->m_Union_Byte_46.s.power_module_15_power_failure)
            .arg(m_s->m_Union_Byte_46.s.power_module_15_total_failure)
            .arg(m_s->m_Union_Byte_46.s.power_module_15_radio_frequency)
            .arg(m_s->power_module_15_temperature);


    sql += str;
    str = QString("('%1','%2','%3','%4','%5','%6','%7','%8')")
            .arg(bid)
            .arg(timeStr)
            .arg(module_num++)
            .arg(m_s->m_Union_Byte_49.s.power_module_16_wave_failure)
            .arg(m_s->m_Union_Byte_49.s.power_module_16_power_failure)
            .arg(m_s->m_Union_Byte_49.s.power_module_16_total_failure)
            .arg(m_s->m_Union_Byte_49.s.power_module_16_radio_frequency)
            .arg(m_s->power_module_16_temperature);
    sql += str;
    tool.exec(sql);

    sql = QString("insert into transmit_subsystem_monitor(bid,date,loopback_close_motivate_cmd,loopback_open_motivate_cmd,b_frequency_band_power,b_frequency_band_transmitter_wave,indoor_temperature,setting_temperature,ac_switch,ac_compressor_state,ac_electrical_heating_state,ac_low_wind_state,ac_hight_wind_state,ac_total_failure,standing_wave_protect,component_communicate_reache_3_way,rf_indicat_failure_greater_than_3)values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17')")
            .arg(bid)
            .arg(timeStr)
            .arg(m_s->m_Union_Byte_52.s.loopback_close_motivate_cmd)
            .arg(m_s->m_Union_Byte_52.s.loopback_open_motivate_cmd)
            .arg(m_s->b_frequency_band_power)
            .arg(m_s->b_frequency_band_transmitter_wave)
            .arg(m_s->indoor_temperature)
            .arg(m_s->setting_temperature)
            .arg(m_s->m_Union_Byte_57.s.ac_switch)
            .arg(m_s->m_Union_Byte_57.s.ac_compressor_state)
            .arg(m_s->m_Union_Byte_57.s.ac_electrical_heating_state)
            .arg(m_s->m_Union_Byte_58.s.ac_low_wind_state)
            .arg(m_s->m_Union_Byte_58.s.ac_hight_wind_state)
            .arg(m_s->m_Union_Byte_58.s.ac_total_failure)
            .arg(m_s->m_Union_Byte_59.s.standing_wave_protect)
            .arg(m_s->m_Union_Byte_59.s.component_communicate_reache_3_way)
            .arg(m_s->m_Union_Byte_59.s.rf_indicat_failure_greater_than_3);
    tool.exec(sql);

    int power_num = 1;
    QString temp="";
    sql = QString("insert into transmit_subsystem_power_state(bid,date,power_num,power_state,power_work_state,power_remote_self_control_state,power_switch_state,power_communicate_link_state,power_voltage,power_electric)values").arg(temp);
    temp = QString("('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')")
            .arg(bid)
            .arg(timeStr)
            .arg(power_num++)
            .arg(m_s->m_Union_Byte_60.s.power_1_state)
            .arg(m_s->m_Union_Byte_60.s.power_1_work_state)
            .arg(m_s->m_Union_Byte_60.s.power_1_remote_self_control_state)
            .arg(m_s->m_Union_Byte_60.s.power_1_switch_state)
            .arg(m_s->m_Union_Byte_60.s.power_1_communicate_link_state)
            .arg(m_s->power_1_voltage)
            .arg(m_s->power_1_electric);
    sql += temp;
    temp = QString("('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')")
            .arg(bid)
            .arg(timeStr)
            .arg(power_num++)
            .arg(m_s->m_Union_Byte_65.s.power_2_state)
            .arg(m_s->m_Union_Byte_65.s.power_2_work_state)
            .arg(m_s->m_Union_Byte_65.s.power_2_remote_self_control_state)
            .arg(m_s->m_Union_Byte_65.s.power_2_switch_state)
            .arg(m_s->m_Union_Byte_65.s.power_2_communicate_link_state)
            .arg(m_s->power_2_voltage)
            .arg(m_s->power_2_electric);



    sql += temp;
    temp = QString("('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')")
            .arg(bid)
            .arg(timeStr)
            .arg(power_num++)
            .arg(m_s->m_Union_Byte_70.s.power_3_state)
            .arg(m_s->m_Union_Byte_70.s.power_3_work_state)
            .arg(m_s->m_Union_Byte_70.s.power_3_remote_self_control_state)
            .arg(m_s->m_Union_Byte_70.s.power_3_switch_state)
            .arg(m_s->m_Union_Byte_70.s.power_3_communicate_link_state)
            .arg(m_s->power_3_voltage)
            .arg(m_s->power_3_electric);

    sql += temp;
    temp = QString("('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')")
            .arg(bid)
            .arg(timeStr)
            .arg(power_num++)
            .arg(m_s->m_Union_Byte_75.s.power_4_state)
            .arg(m_s->m_Union_Byte_75.s.power_4_work_state)
            .arg(m_s->m_Union_Byte_75.s.power_4_remote_self_control_state)
            .arg(m_s->m_Union_Byte_75.s.power_4_switch_state)
            .arg(m_s->m_Union_Byte_75.s.power_4_communicate_link_state)
            .arg(m_s->power_4_voltage)
            .arg(m_s->power_4_electric);


    sql += temp;
    temp = QString("('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')")
            .arg(bid)
            .arg(timeStr)
            .arg(power_num++)
            .arg(m_s->m_Union_Byte_80.s.power_5_state)
            .arg(m_s->m_Union_Byte_80.s.power_5_work_state)
            .arg(m_s->m_Union_Byte_80.s.power_5_remote_self_control_state)
            .arg(m_s->m_Union_Byte_80.s.power_5_switch_state)
            .arg(m_s->m_Union_Byte_80.s.power_5_communicate_link_state)
            .arg(m_s->power_5_voltage)
            .arg(m_s->power_5_electric);


    sql += temp;
    temp = QString("('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')")
            .arg(bid)
            .arg(timeStr)
            .arg(power_num++)
            .arg(m_s->m_Union_Byte_85.s.power_6_state)
            .arg(m_s->m_Union_Byte_85.s.power_6_work_state)
            .arg(m_s->m_Union_Byte_85.s.power_6_remote_self_control_state)
            .arg(m_s->m_Union_Byte_85.s.power_6_switch_state)
            .arg(m_s->m_Union_Byte_85.s.power_6_communicate_link_state)
            .arg(m_s->power_6_voltage)
            .arg(m_s->power_6_electric);

    sql += temp;
    temp = QString("('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')")
            .arg(bid)
            .arg(timeStr)
            .arg(power_num++)
            .arg(m_s->m_Union_Byte_90.s.power_7_state)
            .arg(m_s->m_Union_Byte_90.s.power_7_work_state)
            .arg(m_s->m_Union_Byte_90.s.power_7_remote_self_control_state)
            .arg(m_s->m_Union_Byte_90.s.power_7_switch_state)
            .arg(m_s->m_Union_Byte_90.s.power_7_communicate_link_state)
            .arg(m_s->power_7_voltage)
            .arg(m_s->power_7_electric);

    sql += temp;
    temp = QString("('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')")
            .arg(bid)
            .arg(timeStr)
            .arg(power_num++)
            .arg(m_s->m_Union_Byte_95.s.power_8_state)
            .arg(m_s->m_Union_Byte_95.s.power_8_work_state)
            .arg(m_s->m_Union_Byte_95.s.power_8_remote_self_control_state)
            .arg(m_s->m_Union_Byte_95.s.power_8_switch_state)
            .arg(m_s->m_Union_Byte_95.s.power_8_communicate_link_state)
            .arg(m_s->power_8_voltage)
            .arg(m_s->power_8_electric);
    sql += temp;
    tool.exec(sql);

}
