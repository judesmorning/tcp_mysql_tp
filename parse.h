#ifndef PARSE_H
#define PARSE_H

#include <QObject>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <QThreadPool>
#include "packet_servo_subsystem.h"
#include "packet_transmit_subsystem.h"
#include "packet_receiving_subsystem.h"
#include "packet_receive_subsystem_status_message.h"
#include "packet_power_subsystem_status_message.h"
#include "packet_antenna_feeder_subsystem_status.h"
#include "packet_antenna_feeder_subsystem_status_2.h"
#include "packet_ac_state.h"
#include "packet_antenna_feeder_subsystem_asks_for_wave_controller_phase_value.h"
#include "packet_external_reference_extension_status.h"
#include "packet_communication_status.h"
#include "packet_test_area_mean_value.h"
#include "packet_work_area_mean_value.h"
#include "myrun.h"
#include "mymethod.h"

class Parse : public QObject
{
    Q_OBJECT
public:
    explicit Parse(QObject *parent = nullptr);

signals:

public slots:
    void init();//初始化,线程开启等操作
    void getSoucreDataSlot(const QByteArray& ba);//接收tcp数据

private:
     void getPacket();//原始数据解析出单个包存入队列
     void doExec();//线程池调度队列
private:
    QByteArray allData;//存储tcp接收的数据流
    std::queue<AbsPacket*> allPacket;//队列,存完整的报文对象
    std::mutex m_queue_mutex;//队列锁
    std::mutex m_data_mutex; //源数据队列锁
private:

};

#endif // PARSE_H
