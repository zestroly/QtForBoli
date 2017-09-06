#include "lockconctlserial.h"
#include "../log/qlog.h"
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>

char LockConctlSerial::XORcheck(char* pdata, int datalen )
{
    char result = 0;
    for(int i = 0; i < datalen; i++)
    {
        result ^= pdata[i];
    }
    return result;
}

LockConctlSerial::LockConctlSerial(const char *dev, BaudRateType Rate)
{
    //打开单个箱子
    Com = new Posix_QextSerialPort(QString(dev), QextSerialBase::Polling);
    if(Com->open(QIODevice::ReadWrite)){
        Dlog()<<"打开串口成功";
    }else{
        Dlog()<<"打开串口失败";
        return;
    }
    memset(devname, 0, sizeof(devname));
    memcpy(devname, dev, strlen(dev));
    //设置波特率
    Com->setBaudRate(Rate);
    //设置数据位
    Com->setDataBits(DATA_8);
    //设置校验
    Com->setParity(PAR_NONE);
    //设置停止位
    Com->setStopBits(STOP_1);

    Com->setFlowControl(FLOW_OFF);
    Com->setTimeout(1);

    Dlog()<<"构造串口数据发送器";
}

//箱号  板子地址   板控位置  存入数据库中
int LockConctlSerial::LockUpdateDBase(int Boxnum, int boardaddr, int boardkey)
{
    char sqlcmd[512];
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("lock.db");

    if(!db.open())
    {
        Dlog()<<"打开数据库失败";
        return -1;
    }else{
        Dlog()<<"打开数据库成功";

        QSqlQuery query;
        query.exec("create table if not exists lock(Boxnum INTEGER PRIMARY KEY ,boardaddr int, boardkey int)"); //id自动增加
        if (!query.isActive())
            Dlog()<<"数据库创建失败:"<<query.lastError().text();

        memset(sqlcmd, 0, sizeof(sqlcmd));
        Dlog()<<sizeof(sqlcmd);
        sprintf(sqlcmd,"select Boxnum, boardaddr, boardkey from lock where Boxnum=%d ", Boxnum);
        query.exec(sqlcmd);
        if (!query.isActive())
            Dlog()<<"数据库创建失败:"<<query.lastError().text();
        if(query.next())
        {//修改数据
            Dlog()<<"修改前"<<query.value(0).toString()<<"|"<<query.value(1).toString()<<"|"<<query.value(2).toString();
            memset(sqlcmd, 0 , sizeof(sqlcmd));
            sprintf(sqlcmd,"update lock set boardaddr=%d,boardkey=%d ", boardaddr, boardkey);
            query.exec(sqlcmd);
            if (!query.isActive())
                Dlog()<<"数据库插入失败:"<<query.lastError().text();

        }else{//插入数据
            query.prepare("insert into lock(Boxnum,boardaddr, boardkey) values(?,?,?)");
            query.bindValue(0, Boxnum);
            query.bindValue(1, boardaddr);
            query.bindValue(2, boardkey);
            query.exec();
            if (!query.isActive())
                Dlog()<<"数据库插入失败:"<<query.lastError().text();
        }

        memset(sqlcmd, 0 , sizeof(sqlcmd));
        sprintf(sqlcmd,"select Boxnum, boardaddr, boardkey from lock where Boxnum=%d ", Boxnum);
        query.exec(sqlcmd);
        if(query.next())
            Dlog()<<"保存后"<<query.value(0).toString()<<"|"<<query.value(1).toString()<<"|"<<query.value(2).toString();
    }
    db.close();
    return 0;
}


//地址个数
int LockConctlSerial::getBoardAddrNumber()
{
    char sqlcmd[512];
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("lock.db");
    int count = 0;
    if(!db.open())
    {
        Dlog()<<"打开数据库失败";
        return -1;
    }else{
        Dlog()<<"打开数据库成功";
        QSqlQuery query;

        memset(sqlcmd, 0, sizeof(sqlcmd));
        Dlog()<<sizeof(sqlcmd);
        sprintf(sqlcmd,"select distinct boardaddr from lock");
        query.exec(sqlcmd);
        if (!query.isActive())
        {
             Dlog()<<"数据库查询失败:"<<query.lastError().text();
             return -1;
        }

        while(query.next())
        {
            count++;
        }
    }
    db.close();
    return count;
}

//该锁板号的锁控个数
int LockConctlSerial::getBoardKeyNumber(int addr)
{
    char sqlcmd[512];
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("lock.db");
    int count = 0;
    if(!db.open())
    {
        Dlog()<<"打开数据库失败";
        return -1;
    }else{
        Dlog()<<"打开数据库成功";
        QSqlQuery query;

        memset(sqlcmd, 0, sizeof(sqlcmd));
        Dlog()<<sizeof(sqlcmd);
        sprintf(sqlcmd,"select count(boardkey) from lock where boardaddr=%d ", addr);
        query.exec(sqlcmd);
        if (!query.isActive())
        {
             Dlog()<<"数据库查询失败:"<<query.lastError().text();
             return -1;
        }

        if(query.next())
        {
            count = query.value(0).toInt();
        }
    }
    db.close();
    return count;
}

//总共个数
int LockConctlSerial::getBoxNumber()
{
    char sqlcmd[512];
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("lock.db");
    int count = 0;
    if(!db.open())
    {
        Dlog()<<"打开数据库失败";
        return -1;
    }else{
        Dlog()<<"打开数据库成功";
        QSqlQuery query;

        memset(sqlcmd, 0, sizeof(sqlcmd));
        Dlog()<<sizeof(sqlcmd);
        sprintf(sqlcmd,"select count(Boxnum) from lock");
        query.exec(sqlcmd);
        if (!query.isActive())
        {
             Dlog()<<"数据库查询失败:"<<query.lastError().text();
             return -1;
        }

        if(query.next())
        {
            count = query.value(0).toInt();
        }
    }
    db.close();
    return count;

}




int LockConctlSerial::BoxNumChangeBoardMsg(int BoxNum)
{
    char sqlcmd[512];
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("lock.db");

    if(!db.open())
    {
        Dlog()<<"打开数据库失败";
        return -1;
    }else{
        Dlog()<<"打开数据库成功";
        QSqlQuery query;

        memset(sqlcmd, 0, sizeof(sqlcmd));
        Dlog()<<sizeof(sqlcmd);
        sprintf(sqlcmd,"select Boxnum, boardaddr, boardkey from lock where Boxnum=%d ", BoxNum);
        query.exec(sqlcmd);
        if (!query.isActive())
        {
             Dlog()<<"数据库查询失败:"<<query.lastError().text();
             return -1;
        }

        if(query.next())
        {
            Dlog()<<"箱号"<< query.value(0).toString()<<"板子地址"<<query.value(1).toString()<<"板子锁号"<<query.value(2).toString();
            int lockaddr = query.value(1).toInt();
            int locknum = query.value(2).toInt();
            OpenSingelBox(lockaddr, locknum);
        }else{
            Dlog()<<"未找到("<<BoxNum<<")箱号对应的板块";
        }
    }
    db.close();
    return 0;
}

 void LockConctlSerial::ClearDBtable() //清理表的数据
 {

     char sqlcmd[512];
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

     db.setDatabaseName("lock.db");
     if(!db.open())
     {
         Dlog()<<"打开数据库失败";
         return;
     }else{
         Dlog()<<"打开数据库成功";
         QSqlQuery query;
         memset(sqlcmd, 0, sizeof(sqlcmd));
         sprintf(sqlcmd,"drop table lock");
         query.exec(sqlcmd);
         if (!query.isActive())
         {
              Dlog()<<"数据库删除表失败:"<<query.lastError().text();
              return;
         }
     }
     db.close();
 }

int LockConctlSerial::FindBoardToDB()
{
    char data[200];
    int locknum = 0;
    ClearDBtable(); //清空数据库表数据
    for(int i = 1;  ;i++)
    {
        memset(data, 0 ,sizeof(data));
        if( CheckBoxStatus(i , data) == 0)
        {
            if(i >1)
            {
                Dlog()<< "查询到板子("<<i-1<<")个";
            }
            break;
        }else{
            int lockstatus = (data[6]&0xff) | ((data[7]&0xff)<<8) | ((data[8]&0xff)<<16);
            Dlog()<<"板子地址(dec):"<< (int)data[3];
            for(int j = 0; j < 18 ; j++)
            {
                if( ( (lockstatus >>j) & 0x01 ) == 0x00)
                {
                    locknum++; //锁号++
                    LockUpdateDBase(locknum,(int)data[3],j+1);
                }
            }
        }
    }
}

void LockConctlSerial::OpenAllBox()
{
    char sqlcmd[512];
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("lock.db");
    if(!db.open())
    {
        Dlog()<<"打开数据库失败";
        return;
    }else{
        Dlog()<<"打开数据库成功";
        QSqlQuery query;

        memset(sqlcmd, 0, sizeof(sqlcmd));
        Dlog()<<sizeof(sqlcmd);
        sprintf(sqlcmd,"select * from lock group by Boxnum");
        query.exec(sqlcmd);
        if (!query.isActive())
        {
             Dlog()<<"数据库查询失败:"<<query.lastError().text();
             return;
        }
        while(query.next())
        {
            OpenSingelBox(query.value(1).toInt() , query.value(2).toInt());
            usleep(300*1000);
        }
    }
    db.close();
    return;
}



//发送 板子查询指令
int LockConctlSerial::CheckBoxStatus(int addr, char *buff)
{
    char str[10] = {0x5c, 0xc5 ,0x05, 0x01, 0xD2, 0x01, 0x00, 0x00 ,0x00};
    str[0] = 0x5c;  //起始包 2byte
    str[1] = 0xc5;  //
    str[2] = 0x05;  //包长短
    str[3] = addr & 0xFF; //板子地址
    str[4] = 0xD2; //指令  0xD1 开锁   , 0xD2 查询
    str[5] = 0x01 & 0xFF; //锁的号码

    str[6] = 0x00; //数据位暂时不用 ，为0x00
    str[7] = 0x00;
    str[8] = XORcheck(&str[2], 6);

    int count  = Com->writeData(str, 9);
    Com->flush();

    char msgbuff[1024] = {0};
    sprintf(msgbuff, "发送数据到%s(%d): ", devname, count);
    for(int i = 0; i< count; i++)
    {
        sprintf(msgbuff, "%s %02x",msgbuff, str[i]&0xff);
    }
    Dlog()<<msgbuff;
    usleep(200*1000);
    count = Com->readData(buff, 20);

    memset(msgbuff, 0 , sizeof(msgbuff));
    sprintf(msgbuff, "从%s接受数据(%d)",devname, count);
    for(int i = 0; i< count; i++)
    {
        sprintf(msgbuff, "%s %02x",msgbuff, buff[i]&0xff);
    }
    Dlog()<<msgbuff;
    return count;
}


void LockConctlSerial::OpenSingelBox(int addr, int keynum)
{
    char str[10] = {0x5c, 0xc5 ,0x05, 0x01, 0xD1, 0x01, 0x00, 0x00 ,0x00};
    str[0] = 0x5c;  //起始包 2byte
    str[1] = 0xc5;  //
    str[2] = 0x05;  //包长短
    str[3] = addr & 0xFF; //板子地址
    str[4] = 0xD1; //指令  0xD1 开锁   , 0xD2 查询
    str[5] = keynum & 0xFF; //锁的号码

    str[6] = 0x00; //数据位暂时不用 ，为0x00
    str[7] = 0x00;
    str[8] = XORcheck(&str[2], 6);

    int count = Com->writeData(str, 9);
    Com->flush();

    char msgbuff[1024] = {0};
    sprintf(msgbuff, "发送数据到%s(%d): ", devname, count);
    for(int i = 0; i< count; i++)
    {
        sprintf(msgbuff, "%s %02x",msgbuff, str[i]&0xff);
    }
    Dlog()<<msgbuff;
}


LockConctlSerial::~LockConctlSerial()
{
    Com->flush();
    Com->close();

    delete Com;
    Dlog()<<"虚构串口数据发送器";
}





