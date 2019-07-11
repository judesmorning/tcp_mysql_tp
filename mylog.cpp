#include "mylog.h"

/*****************************************************************/
//作者:曹泽文
//函数名称:构造函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
Mylog::Mylog()
{
    fp=NULL;
    filepath = "";
}

Mylog::~Mylog()
{
    if(fp)
    {
        fclose(fp);
    }
    delete instance;
}
Mylog* Mylog::instance = nullptr;

Mylog* Mylog::getInstace()
{
    if(instance == nullptr)
    {
        instance = new Mylog;

    }
    return instance;
}

void Mylog::writeData(QString m_filepath,QString s)
{

    filepath += m_filepath;
    const char *str = filepath.toStdString().data();    //QString 转换为const char *

    const char *sstr = s.toStdString().data();

    time_t t = time(NULL);
    char ch[MY_CHAR_MAX] = {0};
    strftime(ch, sizeof(ch) - 1, "[%Y-%m-%d %H:%M:%S] ", localtime(&t));
    strcat(ch,sstr);
    strcat(ch,"\n");

    m_mutex.lock();
    fp = fopen(str,"a+");
    fprintf(fp,"%s",ch);
    fflush(fp);
    m_mutex.unlock();
}
#if 1
void Mylog::writeData(QString m_filepath, QString s, int infoType)
{
    filepath += m_filepath;
    const char *str = filepath.toStdString().data();    //QString 转换为const char *

    const char *sstr = s.toStdString().data();

    time_t t = time(NULL);
    char ch[MY_CHAR_MAX] = {0};
    strftime(ch, sizeof(ch) - 1, "[%Y-%m-%d %H:%M:%S] ", localtime(&t));

    switch (infoType) {
    case INFO_TYPE_NORMAL:
        strcat(ch,"Normal ");
        break;
    case INFO_TYPE_WARNING:
        strcat(ch,"Warning ");
    case INFO_TYPE_ERROR:
        strcat(ch,"ERROR ");
    default:
        break;
    }

    strcat(ch,sstr);
    strcat(ch,"\n");
    m_mutex.lock();
    fp = fopen(str,"a+");
    fprintf(fp,"%s",ch);
    fflush(fp);
    m_mutex.unlock();
}

void Mylog::writeData(QString m_filepath, QString s, int infoType, QString sourStr, int lineCount)
{
    filepath += m_filepath;
    const char *str = filepath.toStdString().data();    //QString 转换为const char *

    const char *sstr = s.toStdString().data();

    time_t t = time(NULL);
    char ch[MY_CHAR_MAX] = {0};
    strftime(ch, sizeof(ch) - 1, "[%Y-%m-%d %H:%M:%S] ", localtime(&t));

    switch (infoType) {
    case INFO_TYPE_NORMAL:
        strcat(ch,"Normal (");
        break;
    case INFO_TYPE_WARNING:
        strcat(ch,"Warning (");
    case INFO_TYPE_ERROR:
        strcat(ch,"ERROR (");
    default:
        break;
    }
    const char *ss = sourStr.toStdString().data();  //源目标
    strcat(ch,ss);
    strcat(ch,",");

    const char *buf=QString::number(lineCount).toStdString().data();    //所在行号
    strcat(ch,buf);
    strcat(ch,") ");

    strcat(ch,sstr);
    strcat(ch,"\n");

    m_mutex.lock();
    fp = fopen(str,"a+");
    fprintf(fp,"%s",ch);
    fflush(fp);
    m_mutex.unlock();
}
#endif
