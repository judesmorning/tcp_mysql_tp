#ifndef MYMETHOD_H
#define MYMETHOD_H
#include <QString>

class Mymethod
{
public:
    Mymethod();
    static bool getPacketType(const QByteArray& ba);
    static bool getSum(const QByteArray& temp);
    static QString getCurentTimeStr();
    static void record(QString info);
};
#endif // MYMETHOD_H
