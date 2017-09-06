#include "mainwindow.h"
#include <QTimer>

#include "system/systemmanager.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //板子(1366*768)
    // this->menuBar();
    this->resize(1366,768);

    this->showFullScreen();


    x = this->size().width();
    y = this->size().height();
    qDebug()<<this->size();
    //标题栏设置
    //   this->setWindowIcon(QIcon("images/home-icon.png"));
    // this->setWindowTitle("主界面");
    //设置界面大小，背景

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("images/14140977_010120504386_2.jpg").scaled(this->size())));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    PutInPacketage = new QPushButton(this);
    PutInPacketage->setIcon(QIcon("images/1462889051_585885.png"));
    PutInPacketage->setIconSize(QSize(150,150));
    PutInPacketage->setFlat(false);
    PutInPacketage->adjustSize();
    PutInPacketage->move(  200 , this->height() / 2 - 75   );
    PutInPacketage->setFocusPolicy(Qt::NoFocus);
    PutInPacketage->show();

    TakeOutPacketage = new QPushButton(this);
    TakeOutPacketage->setIcon(QIcon("images/1462889077_275841.png"));
    TakeOutPacketage->setIconSize(QSize(150,150));
    TakeOutPacketage->setFlat(false);
    TakeOutPacketage->adjustSize();
    TakeOutPacketage->move(  500 , this->height() / 2 - 75   );
    TakeOutPacketage->setFocusPolicy(Qt::NoFocus);
    TakeOutPacketage->show();


    AdminiLogin = new QPushButton(this);
    AdminiLogin->setIcon(QIcon("images/568766.png"));
    AdminiLogin->setIconSize(QSize(100,100));
    AdminiLogin->setFlat(true);
    AdminiLogin->adjustSize();
    AdminiLogin->move(this->width() - AdminiLogin->width() - 50 , this->height() - AdminiLogin->width() - 20);
    AdminiLogin->setFocusPolicy(Qt::NoFocus);
    AdminiLogin->show();

    ExitButton = new QPushButton(this);
    ExitButton->setText("退出");
    ExitButton->setFont(QFont("wenquanyi",  35, QFont::Light, false));
    ExitButton->setFlat(false);
    ExitButton->adjustSize();
    ExitButton->move(  width() - ExitButton->width() -30 , this->height()/2);
    ExitButton->setFocusPolicy(Qt::NoFocus);
    ExitButton->show();


    timelabel = new QLCDNumber(19, this);
    timelabel->resize(400,49);
    timelabel->move(width()-timelabel->width(), 5);
    timelabel->setSegmentStyle(QLCDNumber::Flat);

    //调色板
    QPalette lcdpat = timelabel->palette();
    /*设置颜色，整体背景颜色 颜色蓝色,此函数的第一个参数可以设置多种。如文本、按钮按钮文字、多种*/
    lcdpat.setColor(QPalette::Normal,QPalette::WindowText,Qt::blue);
    //设置当前窗口的调色板
    timelabel->setPalette(lcdpat);
   // timelabel->setStyleSheet("background-color: blue");
    timelabel->show();

    RunMode = new QLabel(" 单机 ",this);
    RunMode->setFont(QFont("wenquanyi",  35, QFont::Light, false));
    RunMode->adjustSize();
    RunMode->move(timelabel->x() - RunMode->width() , 5 );
    RunMode->setStyleSheet("color: blue");
    RunMode->show();

    timeUpDate();


//    paletteRed.setColor(QPalette::Normal,QPalette::WindowText,Qt::blue);
//    lcdNumber->setPalette(paletteRed);
//    lcdNumber->setSegmentStyle(QLCDNumber::Flat);
//    lcdNumber->show();

    verificationMethon = NULL;

    connectPuttonSignal();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this ,SLOT(timeUpDate()));
    timer->start(1000);
}



void MainWindow::connectPuttonSignal()
{
    connect(PutInPacketage, SIGNAL(clicked()),this ,SLOT(on_PutInPacketage_clicked()));
    connect(TakeOutPacketage, SIGNAL(clicked()),this ,SLOT(on_TakeOutPacketage_clicked()));
    connect(AdminiLogin, SIGNAL(clicked()),this ,SLOT(on_AdminiLogin_clicked()));
    connect(ExitButton, SIGNAL(clicked()),this ,SLOT(on_RunModeChange_clicked()));
}

void MainWindow::disconnectPuttonSignal()
{
    disconnect(PutInPacketage, SIGNAL(clicked()),this ,SLOT(on_PutInPacketage_clicked()));
    disconnect(TakeOutPacketage, SIGNAL(clicked()),this ,SLOT(on_TakeOutPacketage_clicked()));
    disconnect(AdminiLogin, SIGNAL(clicked()),this ,SLOT(on_AdminiLogin_clicked()));
    disconnect(ExitButton, SIGNAL(clicked()),this ,SLOT(on_RunModeChange_clicked()));
}

void MainWindow::SignalFromChildren(QString childrenwindows)
{

}

void MainWindow::timeUpDate()
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");//设置系统时间显示格式
    timelabel->display(str);//在标签上显示时间
   // timelabel->adjustSize();
}


MainWindow::~MainWindow()
{
    delete timelabel;
    delete PutInPacketage;
    //delete ui;
}

void MainWindow::on_PutInPacketage_clicked()
{
    qDebug()<<"++++++++++++++++++++++++++++++++++++++++++++++"<<__FILE__ <<__FUNCTION__;
    if(verificationMethon == NULL)
    {
        qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("home:放包裹,重新创建verificationMethon");
        verificationMethon = new  VerificationMethod(this);
        verificationMethon->show();
    }else{
        qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("home:放包裹,显示verificationMethon");
        verificationMethon->show();
    }


}

void MainWindow::on_TakeOutPacketage_clicked()
{
    qDebug()<<"++++++++++++++++++++++++++++++++++++++++++++++"<<__FILE__ <<__FUNCTION__;
    // disconnectPuttonSignal();
    if(verificationMethon == NULL)
    {
        qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("home:放包裹,重新创建verificationMethon");
        verificationMethon = new  VerificationMethod(this);
        verificationMethon->show();
    }else{
        qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("home:放包裹,显示verificationMethon");
        verificationMethon->show();
    }
}

void MainWindow::on_RunModeChange_clicked()
{   
    this->close();
    qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("home:管理员");
}

void MainWindow::on_AdminiLogin_clicked()
{
    SystemManager *m = new SystemManager(this);
    m->show();
    qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("home:工作模式切换");
}
