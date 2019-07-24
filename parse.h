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
#include "myrun.h"
#include "mymethod.h"

class Parse : public QObject
{
    Q_OBJECT
public:
    explicit Parse(QObject *parent = nullptr);
    virtual ~Parse();
signals:

public slots:
    void init();//初始化,线程开启等操作
    void getSoucreDataSlot(const QByteArray& ba);//接收tcp数据

private:
     void getPacket();//原始数据解析出单个包存入队列
     void doExec();//线程池调度队列
     volatile bool TP_FLAG_RUN = true;
private:
    QByteArray tcpData;//存储tcp接收的数据流
    std::queue<AbsPacket*> allPacket;//队列,存完整的报文对象
    std::queue<AllStruct*> allData;
    std::mutex m_queue_mutex;//队列锁
    std::mutex m_data_mutex; //源数据队列锁
    std::condition_variable m_cv_packet;//packet条件变量
    std::condition_variable m_cv_data;//data条件变量
private:

};

#endif // PARSE_H
