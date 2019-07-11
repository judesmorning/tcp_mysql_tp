#include "mymethod.h"
#include "abspacket.h"
#include "includes.h"
#include <QDateTime>
/*****************************************************************/
//����:��С��
//��������:���캯��
//��������:NULL
//��������ֵ:NULL
//��������:NULL
//��ע:NULL
/*****************************************************************/
Mymethod::Mymethod()
{

}

/*****************************************************************/
//����:������
//��������:NULL
//��������:NULL
//��������ֵ:NULL
//��������:NULL
//��ע:��С���޸Ĳ��ִ���
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
    /*�ŷ���ϵͳ״̬����*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.servo_Subsystem.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//����ͷ
    RET_VALUE_IF_NOT_EAQU(allStruct.servo_Subsystem.packet_length,sizeof(Servo_Subsystem),false);//���ĳ���
    checkSumBa.resize(sizeof(Servo_Subsystem));
    memcpy(checkSumBa.data(),&allStruct.servo_Subsystem,sizeof(Servo_Subsystem));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*�����ϵͳ״̬����*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.transmit_subsystem.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//����ͷ
    RET_VALUE_IF_NOT_EAQU(allStruct.transmit_subsystem.packet_length,sizeof(Transmit_subsystem),false);//���ĳ���
    checkSumBa.resize(sizeof(Transmit_subsystem));
    memcpy(checkSumBa.data(),&allStruct.transmit_subsystem,sizeof(Transmit_subsystem));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*���շ�ϵͳ״̬����1*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.receiving_subsystem.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//����ͷ
    RET_VALUE_IF_NOT_EAQU(allStruct.receiving_subsystem.packet_length,sizeof(Receiving_subsystem),false);//���ĳ���
    checkSumBa.resize(sizeof(Receiving_subsystem));
    memcpy(checkSumBa.data(),&allStruct.receiving_subsystem,sizeof(Receiving_subsystem));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*���շ�ϵͳ״̬����2*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.receive_subsystem_status_message.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//����ͷ
    RET_VALUE_IF_NOT_EAQU(allStruct.receive_subsystem_status_message.packet_length,sizeof(Receive_subsystem_status_message),false);//���ĳ���
    checkSumBa.resize(sizeof(Receive_subsystem_status_message));
    memcpy(checkSumBa.data(),&allStruct.receive_subsystem_status_message,sizeof(Receive_subsystem_status_message));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*��Դ��ϵͳ״̬����*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.power_subsystem_status_message.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//����ͷ
    RET_VALUE_IF_NOT_EAQU(allStruct.power_subsystem_status_message.packet_length,sizeof(Power_subsystem_status_message),false);//���ĳ���
    checkSumBa.resize(sizeof(Power_subsystem_status_message));
    memcpy(checkSumBa.data(),&allStruct.power_subsystem_status_message,sizeof(Power_subsystem_status_message));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*������ϵͳ״̬1*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.antenna_feeder_subsystem_status.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//����ͷ
    RET_VALUE_IF_NOT_EAQU(allStruct.antenna_feeder_subsystem_status.packet_length,sizeof(Antenna_feeder_subsystem_status),false);//���ĳ���
    checkSumBa.resize(sizeof(Antenna_feeder_subsystem_status));
    memcpy(checkSumBa.data(),&allStruct.antenna_feeder_subsystem_status,sizeof(Antenna_feeder_subsystem_status));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*������ϵͳ״̬2*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.antenna_feeder_subsystem_status_2.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//����ͷ
    RET_VALUE_IF_NOT_EAQU(allStruct.antenna_feeder_subsystem_status_2.packet_length,sizeof(Antenna_feeder_subsystem_status_2),false);//���ĳ���
    checkSumBa.resize(sizeof(Antenna_feeder_subsystem_status_2));
    memcpy(checkSumBa.data(),&allStruct.antenna_feeder_subsystem_status_2,sizeof(Antenna_feeder_subsystem_status_2));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*�յ�״̬*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.ac_state.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//����ͷ
    RET_VALUE_IF_NOT_EAQU(allStruct.ac_state.packet_length,sizeof(AC_State),false);//���ĳ���
    checkSumBa.resize(sizeof(AC_State));
    memcpy(checkSumBa.data(),&allStruct.ac_state,sizeof(AC_State));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*������ϵͳѯ�ʲ�������λֵ*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.antenna_feeder_subsystem_asks_for_wave_controller_phase_value.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//����ͷ
    RET_VALUE_IF_NOT_EAQU(allStruct.antenna_feeder_subsystem_asks_for_wave_controller_phase_value.packet_length,sizeof(Antenna_feeder_subsystem_asks_for_wave_controller_phase_value),false);//���ĳ���
    checkSumBa.resize(sizeof(Antenna_feeder_subsystem_asks_for_wave_controller_phase_value));
    memcpy(checkSumBa.data(),&allStruct.antenna_feeder_subsystem_asks_for_wave_controller_phase_value,sizeof(Antenna_feeder_subsystem_asks_for_wave_controller_phase_value));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*��ο���״̬*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.external_reference_extension_status.header,heads[headCount++].data(),HEADER_LENTH_2),VALUE_ZERO,false);//����ͷ
    RET_VALUE_IF_NOT_EAQU(allStruct.external_reference_extension_status.packet_length,sizeof(External_reference_extension_status),false);//���ĳ���
    checkSumBa.resize(sizeof(External_reference_extension_status));
    memcpy(checkSumBa.data(),&allStruct.external_reference_extension_status,sizeof(External_reference_extension_status));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*ͨѶ״̬*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.communication_status.header,heads[headCount++].data(),HEADER_LENTH_3),VALUE_ZERO,false);//����ͷ
    checkSumBa.resize(sizeof(Communication_status));
    memcpy(checkSumBa.data(),&allStruct.communication_status,sizeof(Communication_status));
    RET_VALUE_IF_EAQU(getSum(checkSumBa),false,false);
    /*��������ֵ*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.test_area_mean_value.frame_head,heads[headCount++].data(),HEADER_LENTH_12),VALUE_ZERO,false);//����ͷ
    /*��������ֵ*/
    RET_VALUE_IF_NOT_EAQU(memcmp(allStruct.work_area_mean_value.frame_head,heads[headCount].data(),HEADER_LENTH_12),VALUE_ZERO,false);//����ͷ
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
//����:������
//��������:�ж�һ��qbytearrayУ���Ƿ���ȷ
//��������:NULL
//��������ֵ:NULL
//��������:NULL
//��ע:NULL
/*****************************************************************/
bool Mymethod::getSum(const QByteArray& temp)
{
    bool ret = true;
#if CLOSE_IF//��׮,��ʱ��֪��У��ͼ��㷽ʽ
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
//����:��С��
//��������:NULL
//��������:NULL
//��������ֵ:NULL
//��������:NULL
//��ע:NULL
/*****************************************************************/
QString Mymethod::getCurentTimeStr()
{
    QString ret;
    QDateTime dt = QDateTime::currentDateTime();
    ret = dt.toString("yy-MM-dd hh:mm::ss");
    return ret;
}

/*****************************************************************/
//����:��С��
//��������:record
//��������:NULL
//��������ֵ:NULL
//��������:NULL
//��ע:NULL
/*****************************************************************/
void Mymethod::record(QString info)
{
    qDebug()<<info;
}
