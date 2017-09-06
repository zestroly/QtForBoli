#include "verificationmethod.h"
#include "log/qlog.h"

VerificationMethod::VerificationMethod(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("验证窗口");
   this->showFullScreen();
    //设置界面大小，背景
    this->resize(1366, 768);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("images/3e42ef8d9a89ec03e015da23ca89f1c0.jpg").scaled(this->size())));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    QToolButton *toolbutton;
    toolbutton = new QToolButton(this);
    toolbutton->setIcon(QIcon("images/20130417033231881.jpg"));
    toolbutton->setIconSize(QSize(32,32));
    toolbutton->setGeometry(70, 65, 62, 62);;
    toolbutton->adjustSize();
    toolbutton->setText("2");
    toolbutton->setFocusPolicy(Qt::NoFocus);
    toolbutton->show();



    toolbutton = new QToolButton(this);
    toolbutton->setIcon(QIcon("images/0f059834730fe0137127e715658cac5f.jpg"));
    toolbutton->setIconSize(QSize(32,32));
    toolbutton->move(20,30);
  //  toolbutton->setGeometry(70, 65, 62, 62);
    toolbutton->setText("2");
    toolbutton->setFocusPolicy(Qt::NoFocus);
     toolbutton->show();

    toolbutton = new QToolButton(this);
    toolbutton->setIcon(QIcon("images/0e4375787f3e0db919f1b871d3f652c8.jpg"));
    toolbutton->setIconSize(QSize(200,32));
  //  toolbutton->setGeometry(70, 65, 62, 62);
    toolbutton->setText("2");
    toolbutton->setFocusPolicy(Qt::NoFocus);
     toolbutton->show();


    toolbutton = new QToolButton(this);
    toolbutton->setIcon(QIcon("images/4bb4ec57f76160e6ec377587b59fba9d.jpg"));
    toolbutton->setIconSize(QSize(400,32));
  //  toolbutton->setGeometry(70, 65, 62, 62);
    toolbutton->setText("2");
    toolbutton->setFocusPolicy(Qt::NoFocus);
     toolbutton->show();



    PassWorkCheck = new QPushButton(tr("密码验证"),this);
    PassWorkCheck->setFont(QFont("wenquanyi",  35, QFont::Light, false) );
    PassWorkCheck->setFlat(false);
    PassWorkCheck->adjustSize();
    PassWorkCheck->move(  this->width()/4*1, this->height() / 2 - 100   );
    PassWorkCheck->setFocusPolicy(Qt::NoFocus);
    PassWorkCheck->show();

    IDcardCheck = new QPushButton(tr("ID卡验证"),this);
    IDcardCheck->setFont(QFont("wenquanyi",  35, QFont::Light, false) );
    IDcardCheck->setFlat(false);
    IDcardCheck->adjustSize();
    IDcardCheck->move(  this->width()/4*3-200, this->height() / 2 - 100   );
    IDcardCheck->setFocusPolicy(Qt::NoFocus);
    IDcardCheck->show();

    FaceCheck = new QPushButton(tr("人脸识别"),this);
    FaceCheck->setFont(QFont("wenquanyi",  35, QFont::Light, false) );
    FaceCheck->setFlat(false);
    FaceCheck->adjustSize();
    FaceCheck->move(  this->width()/4*1, this->height() / 2 + 100   );
    FaceCheck->setFocusPolicy(Qt::NoFocus);
    FaceCheck->show();

    DactylogramCheck = new QPushButton(tr("指纹验证"),this);
    DactylogramCheck->setFont(QFont("wenquanyi",  35, QFont::Light, false) );
    DactylogramCheck->setFlat(false);
    DactylogramCheck->adjustSize();
    DactylogramCheck->move(  this->width()/4*3-200, this->height() / 2 + 100   );
    DactylogramCheck->setFocusPolicy(Qt::NoFocus);
    DactylogramCheck->show();


    BackToUpper = new QPushButton(tr("返回"),this);
    BackToUpper->setFont(QFont("wenquanyi",  35, QFont::Light, false) );
    BackToUpper->setFlat(false);
    BackToUpper->adjustSize();
    BackToUpper->move(  this->width()/4*3 +100, this->height() / 2 +200   );
    BackToUpper->setFocusPolicy(Qt::NoFocus);
    BackToUpper->show();


    parentName = dynamic_cast<MainWindow*>(parent);
    checkdev = NULL;
    connectPuttonSignal();
}

void VerificationMethod::connectPuttonSignal()
{
    connect(PassWorkCheck, SIGNAL(clicked()),this ,SLOT(on_PassWorkCheck_clicked()));
    connect(IDcardCheck, SIGNAL(clicked()),this ,SLOT(on_IDcardCheck_clicked()));
    connect(FaceCheck, SIGNAL(clicked()),this ,SLOT(on_FaceCheck_clicked()));
    connect(DactylogramCheck, SIGNAL(clicked()),this ,SLOT(on_DactylogramCheck_clicked()));
    connect(BackToUpper, SIGNAL(clicked()),this ,SLOT(on_BackToUpper_clicked()));
}

void VerificationMethod::disconnectPuttonSignal()
{
    disconnect(PassWorkCheck, SIGNAL(clicked()),this ,SLOT(on_PassWorkCheck_clicked()));
    disconnect(IDcardCheck, SIGNAL(clicked()),this ,SLOT(on_IDcardCheck_clicked()));
    disconnect(FaceCheck, SIGNAL(clicked()),this ,SLOT(on_FaceCheck_clicked()));
    disconnect(DactylogramCheck, SIGNAL(clicked()),this ,SLOT(on_DactylogramCheck_clicked()));
    disconnect(BackToUpper, SIGNAL(clicked()),this ,SLOT(on_BackToUpper_clicked()));
}





VerificationMethod::~VerificationMethod()
{
    qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("VerificationMethond:执行虚构函数");
}

void VerificationMethod::on_PassWorkCheck_clicked()
{
    if (checkdev == NULL)
    {
        checkdev = new CheckDev(this,0);
    }
    checkdev->show();
    qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("VerificationMethond:密码验证");
}

void VerificationMethod::on_IDcardCheck_clicked()
{
    if (checkdev == NULL)
    {
        checkdev = new CheckDev(this,1);
    }
    checkdev->show();
    qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("VerificationMethond:ID卡验证");

}

void VerificationMethod::on_DactylogramCheck_clicked()
{
    if (checkdev == NULL)
    {
        checkdev = new CheckDev(this,2);
    }
    checkdev->show();
    qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("VerificationMethond:指纹按钮");
}

void VerificationMethod::on_FaceCheck_clicked()
{
    if (checkdev == NULL)
    {
        checkdev = new CheckDev(this,3);
    }
    checkdev->show();
    qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("VerificationMethond:人脸识别");
}

void VerificationMethod::on_BackToUpper_clicked()
{
    this->parentName->verificationMethon = NULL;
    qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << tr("VerificationMethond:ID卡验证");
    delete this;
}

void VerificationMethod::on_clearPointe()
{
    checkdev = NULL;
}
