#include "checkdev.h"
#include "log/qlog.h"
#include <stdio.h>
#include "dev/idcardserial.h"
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include "dev/lockconctlserial.h"
CheckDev::CheckDev(QWidget *parent,int number) :
    QDialog(parent)
{

    this->resize(1366, 768);
    this->showFullScreen();
    QPalette palette;
    int wayID = 0;
    switch(number)
    {
    case 0:
        wayID = 0;
        break;
    case 1:
        wayID = 1;
        palette.setBrush(QPalette::Background,QBrush(QPixmap("images/11111111.jpg").scaled(this->size())));
        break;
    case 2:
        wayID = 2;
        palette.setBrush(QPalette::Background,QBrush(QPixmap("images/33333333.jpg").scaled(this->size())));
        break;
    case 3:
        wayID =3;
        palette.setBrush(QPalette::Background,QBrush(QPixmap("images/22222222.jpg").scaled(this->size())));
        break;
    default:
        break;
    }
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    progressBar = new QProgressBar(this);
    progressBar->setGeometry(280,240,811,71);
    progressBar->setValue(10);
    progressBar->show();

    Ensure = new QPushButton(this);
    Ensure->setGeometry(830,340,151,71);
    Ensure->setText(tr("确定"));
    Ensure->setEnabled(false);
    Ensure->show();

    Cancel = new QPushButton(this);
    Cancel->setGeometry(1000,340,151,71);
    Cancel->setText(tr("取消"));
    Cancel->show();

    lcdNumber = new QLCDNumber(2 ,this);
    lcdNumber->setGeometry(1360-141,0,141,131);
    lcdNumber->display(30);
    QPalette paletteRed;
    paletteRed.setColor(QPalette::Normal,QPalette::WindowText,Qt::blue);
    lcdNumber->setPalette(paletteRed);
    lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    lcdNumber->show();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this ,SLOT(timeDecCount()));
    timer->start(1000);

    connect(Ensure, SIGNAL(clicked()),this ,SLOT(on_Ensure_clicked()));
    connect(Cancel, SIGNAL(clicked()),this ,SLOT(on_Cancel_clicked()));

    //创建线程，对数据进行验证
    workthread = new CheckWorkThread();
    workthread->checkway = wayID;//这是检测方式
    workthread->start();

    connect(workthread,SIGNAL( ChangeProessBar(int)),this,SLOT(ThreadChangeProessBar(int)));
    connect(workthread,SIGNAL( SendResultWithCheck(int)),this,SLOT(ThreadSendResultWithCheck(int)));


    parentthis = dynamic_cast<VerificationMethod*>(parent);

    Dlog()<<tr("构造完成");
}





void CheckDev::timeDecCount()
{
    if (lcdNumber->value() > 1)
    {
        lcdNumber->display( lcdNumber->intValue() - 1);
    }else{//操作超时，退出此界面
        delete this;
    }
}

void CheckDev::on_Ensure_clicked()
{
    Dlog()<<tr("确定登陆");
}

void CheckDev::on_Cancel_clicked()
{

    Dlog()<<tr("取消登陆");
    delete this;
}

void CheckDev::ThreadChangeProessBar(int value)
{
    progressBar->setValue(value);
    Dlog()<<tr("当前读取进度") << value;
}

void CheckDev::ThreadSendResultWithCheck(int result)
{
    Dlog()<<tr("返回检测结果") << result;
    //势能去确定按钮
    Ensure->setEnabled(true);

}

CheckDev::~CheckDev()
{
    parentthis->checkdev = NULL;

    //超时操作退出程序,点进退出键
    workthread->terminate();
    workthread->wait();

    delete workthread;
    delete Cancel;
    delete Ensure;
    delete progressBar;
    delete lcdNumber;
    timer->stop();
    delete timer;

    Dlog()<<tr("执行虚构");
}


int CheckWorkThread::SeleteIDcardFromDB(QString str)
{
    int ret = 0;
    if(str.length() < 3)
    {
        Dlog()<<tr("id卡值太小");
        return -1;
    }


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("user.db");

    if(!db.open())
    {
        Dlog()<<"打开数据库失败";
        return -1;
    }else{
        Dlog()<<"打开数据库成功";

        QString sqlcmd ="";
        QSqlQuery query;

        //CREATE TABLE USER(ID INT PRIMARY KEY,IDCardNum TEXT,LockNum INT);
        //INSERT INTO USER(ID, IDCardNum, LockNum) VALUES(1, '0015697457', 45);
        //INSERT INTO USER(ID, IDCardNum, LockNum) VALUES(2, '0015697453', 41);
        //INSERT INTO USER(ID, IDCardNum, LockNum) VALUES(3, '0015697452', 42);
        //INSERT INTO USER(ID, IDCardNum, LockNum) VALUES(4, '0015697456', 43);


        sqlcmd.sprintf("select LockNum from USER where IDCardNum=");
        sqlcmd=sqlcmd + QString("'") + str + QString("'");
        Dlog()<<sqlcmd;

        query.exec(sqlcmd);
        if (!query.isActive())
            Dlog()<<"数据库创建失败:"<<query.lastError().text();

        if(query.next())
        {//修改数据
            Dlog()<<query.value(0).toString();
            ret = query.value(0).toInt();


        }else{//插入数据
            Dlog()<<"未找到该项数据";
            ret = 0;
        }

    }
    db.close();
    return ret;


}







void CheckWorkThread::run()
{
    switch(checkway)
    {
    case 1:
    {
        Dlog()<<tr("id卡验证");
        emit   ChangeProessBar(5);
        IDcardSerial ID("/dev/ttyUSB0", BAUD9600);
        QString result = ID.ReadID();
        emit   ChangeProessBar(40);
        int locknum = SeleteIDcardFromDB(result);
        emit   ChangeProessBar(80);
        if(locknum > 0)
        {
            LockConctlSerial co("/dev/ttyUSB0", BAUD57600);
            co.BoxNumChangeBoardMsg(locknum);
        }
        emit   ChangeProessBar(100);
        emit   SendResultWithCheck(100);
        break;
    }

    case 2:
        Dlog()<<tr("指纹验证");
        break;
    case 3:
        Dlog()<<tr("人脸识别");
        break;
    }

    int i = 0;

}




