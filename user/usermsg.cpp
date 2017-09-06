#include "usermsg.h"
#include "../log/qlog.h"
UserMSG::UserMSG()
{

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("user.db");

    if(!db.open())
    {
        Dlog()<<"打开数据库失败";
    }else{
        Dlog()<<"打开数据库成功";


    }
}



int UserMSG::addUser(char* name,
                     char* telephone,
                     char* company,
                     char* idcardtype,
                     char* password,
                     char* fingerprinttype,
                     char* facetype,
                     char* ismanager,
                     char* group,
                     char* conctllock
                     )  //添加用户
{

    QSqlQuery query;
    query.exec("create table if not exists user(\
              ID   INTEGER PRIMARY KEY  NOT NULL,\
              NAME                TEXT  NOT NULL,\
              TELEPHONE           TEXT,\
              COMPANY             TEXT,\
              IDCARDTYPE          TEXT,\
              PASSWORD            TEXT,\
              FINGERPRINTTYPE     TEXT,\
              FACETYPE            TEXT,\
              ISMANAGER           BLOB,\
              GROUP               TEXT,\
              CONCTLLOCK          INT,\
              )"); //id自动增加
    if (!query.isActive()){
        Dlog()<<"数据库创建失败:"<<query.lastError().text();
    }
    query.prepare("insert into user(\
                  NAME,\
                  TELEPHONE, \
                  COMPANY,\
                  IDCARDTYPE ,\
                  PASSWORD , \
                  FINGERPRINTTYPE,\
                  FACETYPE ,\
                  ISMANAGER ,\
                  GROUP , \
                  CONCTLLOCK\
                  ) values(?,?,?,?,?,?,?,?,?,?)");
    query.bindValue(0, name);
    query.bindValue(1, telephone);
    query.bindValue(2, company);
    query.exec();
    if (!query.isActive())
        Dlog()<<"数据库插入失败:"<<query.lastError().text();
    return 0;
}

int UserMSG::addAdmini() //添加管理员
{

}

int UserMSG::deleteUser() //删除用户
{

}

int UserMSG::deleteAdmini() //删除管理员
{

}

int UserMSG::changeUser() //修改用户信息
{

}

int UserMSG::chaageAdmini() //修改管理员信息
{

}

int UserMSG::PasswordMatch(char *userName, char *password)  //用户密码登陆
{
    QSqlQuery query;
    QString sqlcmd;

    sqlcmd.sprintf("select PASSWORD from user where NAME=%s", userName);
    query.exec(sqlcmd);
    if (!query.isActive())
    {
         Dlog()<<"数据库查询失败:"<<query.lastError().text();
         return -1;
    }

    if(query.next())
    {
        query.value(0).toInt();
    }else{
        return -1;
    }

}

int UserMSG::IDcardMatch(char *idmsg)  //ID 登陆
{

}

int UserMSG::FaceMatch(char *facemsg)  //人脸失败
{

}

int UserMSG::FingerMatch(char *fingermsg) //指纹登陆
{

}

UserMSG::~UserMSG()
{
    db.close();
}
