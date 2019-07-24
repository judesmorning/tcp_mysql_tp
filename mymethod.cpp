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
