#ifndef MYLOG_H
#define MYLOG_H

#include <string.h>
#include <time.h>
#include <stdio.h>
#include <mutex>
#include <QString>
#include "includes.h"


enum INFO_TYPE
{
    INFO_TYPE_NORMAL = 1,
    INFO_TYPE_WARNING,
    INFO_TYPE_ERROR
};

class Mylog
{
private:
    Mylog();
    virtual ~Mylog();

public:
    static Mylog *getInstace();

    void writeData(QString m_filepath,QString s);
    void writeData(QString m_filepath,QString s,int infoType);
    void writeData(QString m_filepath,QString s,int infoType,QString sourStr,int lineCount);

private:
    FILE *fp;
    QString filepath;
    std::mutex m_mutex;
    static Mylog *instance;
};

#endif // MYLOG_H
