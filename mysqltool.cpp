#include "mysqltool.h"
#include "mymethod.h"
#include <QSqlError>
std::mutex m_mutext_opensql;
/*****************************************************************/
//作者:朱小勇
//函数名称:构造函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
Mysqltool::Mysqltool(QString dataBaseName)
{
    pDb = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL", dataBaseName));
    pDb->setHostName(DB_IP);             //ip
    pDb->setUserName(DB_USER_NAME);      //登陆MYSQL的用户名
    pDb->setPassword(DB_PASSWORD);       //登陆的密码
    pDb->setDatabaseName(DB_DATABASE_NAME);  //数据库的名称
    m_mutext_opensql.lock();
    if(!pDb->open())
    {
        Mymethod::record("数据库打开失败:");
        //        QSqlError tempErr = db.lastError();
        //        qDebug()<<tempErr;
    }
    m_mutext_opensql.unlock();
    this->dataBaseName = dataBaseName;
}

/*****************************************************************/
//作者:朱小勇
//函数名称:析构函数
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
Mysqltool::~Mysqltool()
{
    pDb->close();
    delete pDb;
    pDb = nullptr;
    QSqlDatabase::removeDatabase(dataBaseName);
}

/*****************************************************************/
//作者:朱小勇
//函数名称:增删改
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:NULL
/*****************************************************************/
bool Mysqltool::exec(QString sql)
{
    bool ret = true;
    RET_VALUE_IF_EAQU(pDb->isOpen(),false,false);
    QSqlQuery query(*pDb);
    RET_VALUE_IF_EAQU(query.exec(sql),false,false);
    return ret;
}

/*****************************************************************/
//作者:朱小勇
//函数名称:查
//函数参数:NULL
//函数返回值:NULL
//函数作用:NULL
//备注:如果有问题可以将查询结果放在堆上
/*****************************************************************/
bool Mysqltool::select(QString sql,QSqlQuery& rsltQuery)
{
    bool ret = true;
    QSqlQuery query(*pDb);
    RET_VALUE_IF_EAQU(query.exec(sql),false,false);
    rsltQuery = query;
    return ret;
}
