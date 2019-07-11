#ifndef MYSQLTOOL_H
#define MYSQLTOOL_H
#include <QSqlDatabase>
#include "includes.h"
#include <QSqlQuery>
#include <mutex>
class Mysqltool
{
public:
    Mysqltool(QString dataBaseName);
    virtual ~Mysqltool();
public:
    bool exec(QString sql);//插入、删除、更新
    bool select(QString sql,QSqlQuery& rsltQuery);//查询
private:
    QSqlDatabase* pDb;
    QString dataBaseName;

};
extern std::mutex m_mutext_opensql;
#endif // MYSQLTOOL_H
