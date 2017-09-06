#ifndef USERMSG_H
#define USERMSG_H

#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>


class UserMSG
{
public:
    UserMSG();

    int addUser(char* name,char* telephone,char* company,char* idcardtype,
                char* password,char* fingerprinttype,char* facetype,
                char* ismanager,char* group,char* conctllock);  //添加用户
    int addAdmini(); //添加管理员
    int deleteUser(); //删除用户
    int deleteAdmini(); //删除管理员
    int changeUser(); //修改用户信息
    int chaageAdmini(); //修改管理员信息
    int PasswordMatch(char *userName, char *password);  //用户密码登陆
    int IDcardMatch(char *idmsg);  //ID 登陆
    int FaceMatch(char *facemsg);  //人脸失败
    int FingerMatch(char *fingermsg); //指纹登陆
    ~UserMSG();

private:

    QSqlDatabase db;
};

#endif // USERMSG_H
