#ifndef INCLUDES_H
#define INCLUDES_H

/*头文件*/
#include <iostream>
#include <QDebug>

/*预定义*/
#define OPEN_IF 1
#define CLOSE_IF 0
#define MY_CHAR_MAX 1024
#define TP_COUNT 5//线程池线程数量
#define TP_WAITE_TIME 50//线程池轮训间隔
#define PACKET_ALL_LENTH 499//报文长度
#define NOT_FOUND -1//未找到
#define NO_BID -1//无bid
#define MID_FROM_ZERO 0
#define SERVER_IP "192.168.1.126"//tcp服务器ip
#define SERVER_PORT 8080     //tcp服务器端口
#define DB_IP "192.168.1.126"    //数据库ip
#define DB_USER_NAME "root"  //数据库用户名
#define DB_PASSWORD "zhuxiaoyong1212"       //数据库密码
#define DB_DATABASE_NAME "source_data"      //数据库名
#define HEADER_LENTH_2 2 //长度为2的报文头
#define HEADER_LENTH_3 3 //长度为3的报文头
#define HEADER_LENTH_12 12 //长度为12的报文头
#define VALUE_ZERO 0
/*返回宏*/
#define PRINTF_LOCATION() std::cout<<"ret in:" << __FILE__ << " at:"<<__LINE__

#define RET_VALUE_IF_NOT_EAQU(a,b,c)  \
    do {  \
    if(a!=b) \
{        \
    PRINTF_LOCATION();\
    return c; \
}        \
    } while (false)

#define RET_VALUE_IF_EAQU(a,b,c)  \
    do {  \
    if(a==b) \
{        \
    PRINTF_LOCATION();\
    return c; \
}        \
    } while (false)

#define RET_IF_NOT_EAQU(a,b)  \
    do {  \
    if(a!=b) \
{        \
    PRINTF_LOCATION();\
    return; \
}        \
    } while (false)

#define RET_IF_EAQU(a,b)  \
    do {  \
    if(a==b) \
{        \
    PRINTF_LOCATION();\
    return; \
}        \
    } while (false)

typedef unsigned char uchar;
typedef unsigned short ushort;

/*结构体定义*/
#pragma pack(1)
/*****************************************************************/
//作者:朱小勇
//函数名称:NULL
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
typedef struct _Servo_Subsystem
{
    char header[2];		//报文头,小端模式0x88AA
    

    uchar check_sum;					 //校验和
} Servo_Subsystem, *pServo_Subsystem;

/*****************************************************************/
//作者:朱小勇
//函数名称:NULL
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:20190627朱小勇增加注释,修改部分bug,修改部分命名
/*****************************************************************/
typedef struct _Transmit_subsystem
{
    char header[2];		//报文头,小端模式0xAABB
    

    uchar check_sum;//校验和
}Transmit_subsystem, *pTransmit_subsystem;


/*****************************************************************/
//作者:朱小勇
//函数名称:所有报文
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:共13个子结构体,合计499字节
/*****************************************************************/
struct AllStruct
{
    Servo_Subsystem servo_Subsystem;			  //伺服分系统状态报文
    Transmit_subsystem transmit_subsystem;		  //发射分系统状态报文
};

#pragma pack()
#endif // INCLUDES_H
