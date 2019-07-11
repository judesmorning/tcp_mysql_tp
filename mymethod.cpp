#include "mymethod.h"
#include "abspacket.h"
#include "includes.h"
#include <QDateTime>
/*****************************************************************/
//作者:朱小勇
//函数名称:构造函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
Mymethod::Mymethod()
{

}

/*****************************************************************/
//作者:曹泽文
//函数名称:NULL
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:朱小勇修改部分代码
/*****************************************************************/
bool Mymethod::getPacketType(const QByteArray &ba)
{
    bool ret = true;

    QByteArray data = ba;
    RET_VALUE_IF_NOT_EAQU((int)data.length(),PACKET_ALL_LENTH,false);
    std::vector<QByteArray> heads = PacketConfig::getInstace()->getHeads();
    AllStruct allStruct;
    QByteArray checkSumBa;
    int headCount = 0;
    memset(&allStruct,0,sizeof(PACKET_ALL_LENTH));
    memcpy(&allStruct,ba.data(),PACKET_ALL_LENTH);
    /*伺服分系统状态报文*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.servo_Subsystem.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//报文头
    RET_VALUE_IF_NOT_EAQU(allStruct.servo_Subsystem.packet_length,sizeof(Servo_Subsystem),false);//报文长度
    checkSumBa.resize(sizeof(Servo_Subsystem));
    memcpy(checkSumBa.data(),&allStruct.servo_Subsystem,sizeof(Servo_Subsystem));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*发射分系统状态报文*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.transmit_subsystem.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//报文头
    RET_VALUE_IF_NOT_EAQU(allStruct.transmit_subsystem.packet_length,sizeof(Transmit_subsystem),false);//报文长度
    checkSumBa.resize(sizeof(Transmit_subsystem));
    memcpy(checkSumBa.data(),&allStruct.transmit_subsystem,sizeof(Transmit_subsystem));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*接收分系统状态报文1*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.receiving_subsystem.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//报文头
    RET_VALUE_IF_NOT_EAQU(allStruct.receiving_subsystem.packet_length,sizeof(Receiving_subsystem),false);//报文长度
    checkSumBa.resize(sizeof(Receiving_subsystem));
    memcpy(checkSumBa.data(),&allStruct.receiving_subsystem,sizeof(Receiving_subsystem));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*接收分系统状态报文2*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.receive_subsystem_status_message.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//报文头
    RET_VALUE_IF_NOT_EAQU(allStruct.receive_subsystem_status_message.packet_length,sizeof(Receive_subsystem_status_message),false);//报文长度
    checkSumBa.resize(sizeof(Receive_subsystem_status_message));
    memcpy(checkSumBa.data(),&allStruct.receive_subsystem_status_message,sizeof(Receive_subsystem_status_message));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*电源分系统状态报文*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.power_subsystem_status_message.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//报文头
    RET_VALUE_IF_NOT_EAQU(allStruct.power_subsystem_status_message.packet_length,sizeof(Power_subsystem_status_message),false);//报文长度
    checkSumBa.resize(sizeof(Power_subsystem_status_message));
    memcpy(checkSumBa.data(),&allStruct.power_subsystem_status_message,sizeof(Power_subsystem_status_message));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*天馈分系统状态1*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.antenna_feeder_subsystem_status.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//报文头
    RET_VALUE_IF_NOT_EAQU(allStruct.antenna_feeder_subsystem_status.packet_length,sizeof(Antenna_feeder_subsystem_status),false);//报文长度
    checkSumBa.resize(sizeof(Antenna_feeder_subsystem_status));
    memcpy(checkSumBa.data(),&allStruct.antenna_feeder_subsystem_status,sizeof(Antenna_feeder_subsystem_status));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*天馈分系统状态2*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.antenna_feeder_subsystem_status_2.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//报文头
    RET_VALUE_IF_NOT_EAQU(allStruct.antenna_feeder_subsystem_status_2.packet_length,sizeof(Antenna_feeder_subsystem_status_2),false);//报文长度
    checkSumBa.resize(sizeof(Antenna_feeder_subsystem_status_2));
    memcpy(checkSumBa.data(),&allStruct.antenna_feeder_subsystem_status_2,sizeof(Antenna_feeder_subsystem_status_2));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*空调状态*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.ac_state.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//报文头
    RET_VALUE_IF_NOT_EAQU(allStruct.ac_state.packet_length,sizeof(AC_State),false);//报文长度
    checkSumBa.resize(sizeof(AC_State));
    memcpy(checkSumBa.data(),&allStruct.ac_state,sizeof(AC_State));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*天馈分系统询问波控器相位值*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.antenna_feeder_subsystem_asks_for_wave_controller_phase_value.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//报文头
    RET_VALUE_IF_NOT_EAQU(allStruct.antenna_feeder_subsystem_asks_for_wave_controller_phase_value.packet_length,sizeof(Antenna_feeder_subsystem_asks_for_wave_controller_phase_value),false);//报文长度
    checkSumBa.resize(sizeof(Antenna_feeder_subsystem_asks_for_wave_controller_phase_value));
    memcpy(checkSumBa.data(),&allStruct.antenna_feeder_subsystem_asks_for_wave_controller_phase_value,sizeof(Antenna_feeder_subsystem_asks_for_wave_controller_phase_value));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*外参考机状态*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.external_reference_extension_status.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//报文头
    RET_VALUE_IF_NOT_EAQU(allStruct.external_reference_extension_status.packet_length,sizeof(External_reference_extension_status),false);//报文长度
    checkSumBa.resize(sizeof(External_reference_extension_status));
    memcpy(checkSumBa.data(),&allStruct.external_reference_extension_status,sizeof(External_reference_extension_status));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*通讯状态*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.communication_status.header,heads[headCount++].data(),HEADER_LENTH_3),VALUE_ZERO,false);//报文头
    checkSumBa.resize(sizeof(Communication_status));
    memcpy(checkSumBa.data(),&allStruct.communication_status,sizeof(Communication_status));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*测试区均值*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.test_area_mean_value.frame_head,heads[headCount++].data(),HEADER_LENTH_12),VALUE_ZERO,false);//报文头
    /*工作区均值*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.work_area_mean_value.frame_head,heads[headCount].data(),HEADER_LENTH_12),VALUE_ZERO,false);//报文头
#if CLOSE_IF
    std::vector<QByteArray> heads = PacketConfig::getInstace()->getHeads();
    for(int j=0;j<(int)heads.size()-3;j++)
    {
        int lenth = (int)data[ret+2];
        if(data[ret]==heads[j][0]&&data[ret+1]==heads[j][1])
        {
            uchar Sum = 0;
            for(int k = ret+2;k<lenth-1;k++)
            {
                Sum += data[k];
            }
            if(Sum == data[lenth])
            {
                ok = true;
                return ok;
            }
            else
            {
                ok = false;
                return ok;
            }
        }
        else
        {
            ok = false;
            return ok;
        }
        data.remove(ret,lenth);
    }
    int j=(int)heads.size()-3;
    int le = 7;
    if(data[ret]==heads[j][0]&&data[ret+1]==heads[j][1]&&data[ret+2]==heads[j][2])
    {
        uchar sSum = 0;
        for(int k = ret+3;k<le-1;k++)
        {
            sSum += data[k];
        }
        if(sSum == data[le])
        {
            ok = true;
            return ok;
        }
        else
        {

            ok = false;
            return ok;
        }

    }
    else
    {
        ok = false;
        return ok;
    }
    data.remove(ret,le);
    int lens = 68;
    if(data.length()==2*lens)
    {
        for(int j = (int)heads.size()-2;j<(int)heads.size();j++)
        {
            if(data[ret]==heads[j][0]&&data[ret+1]==heads[j][1]&&data[ret+2]==heads[j][2]&&data[ret+3]==heads[j][3]&&data[ret+4]==heads[j][4]&&data[ret+5]==heads[j][5]&&data[ret+6]==heads[j][6]&&data[ret+7]==heads[j][7]&&data[ret+8]==heads[j][8]&&data[ret+9]==heads[j][9]&&data[ret+10]==heads[j][10]&&data[ret+11]==heads[j][11])
            {
                ok = true;
                return ok;
            }
            else
            {
                ok = false;
                return ok;
            }
            data.remove(ret,lens);
        }
    }
    else
    {
        ok = false;
        return ok;
    }

#endif
    return ret;

}

/*****************************************************************/
//作者:曹泽文
//函数名称:判断一个qbytearray校验是否正确
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
bool Mymethod::getSum(const QByteArray& temp)
{
    bool ret = true;
#if CLOSE_IF//打桩,暂时不知道校验和计算方式
    uchar mySum = 0;
    int lenth = temp.length();
    for(int i=2;i<lenth-1;i++)
    {
        mySum += (uchar)temp[i];
    }
    if(mySum != temp[lenth-1])
    {
        ret =false;
    }
#endif
    return ret;
}

/*****************************************************************/
//作者:朱小勇
//函数名称:NULL
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
QString Mymethod::getCurentTimeStr()
{
    QString ret;
    QDateTime dt = QDateTime::currentDateTime();
    ret = dt.toString("yy-MM-dd hh:mm::ss");
    return ret;
}

/*****************************************************************/
//作者:朱小勇
//函数名称:record
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
void Mymethod::record(QString info)
{
    qDebug()<<info;
}
