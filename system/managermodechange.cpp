#include "managermodechange.h"

ManagerModechange::ManagerModechange(QWidget *parent) :
    QWidget(parent)
{
    this->resize(700,500);
    this->setAutoFillBackground(false);
    this->setFocusPolicy(Qt::NoFocus);


    ItemName = new QLabel("模式设置");
    ItemName->setFont(QFont("quanwenyi", 30 ,QFont::Light, false));
    ItemName->setAlignment(Qt::AlignCenter);
    ItemName->setFocusPolicy(Qt::NoFocus);


    vboxlayout = new QVBoxLayout(this);



    NetWorkMode               = new QPushButton("网络模式");
    LoacalWorkMode            = new QPushButton("单机模式");
    GoBack                    = new QPushButton("返回");
    NetWorkMode->setFocusPolicy(Qt::NoFocus);
    LoacalWorkMode->setFocusPolicy(Qt::NoFocus);
    GoBack->setFocusPolicy(Qt::NoFocus);

    GoBack->setFont(QFont("quanwenyi",  30, QFont::Light, false));
    NetWorkMode->setFont(QFont("quanwenyi",  30, QFont::Light, false));
    LoacalWorkMode->setFont(QFont("quanwenyi",  30, QFont::Light, false));

    vboxlayout->addWidget(ItemName       ,0);
    vboxlayout->addWidget(NetWorkMode    ,1);
    vboxlayout->addWidget(LoacalWorkMode ,2);
    vboxlayout->addWidget(GoBack ,3);

    this->setLayout(vboxlayout);


    connect(GoBack,         SIGNAL(clicked()),this,SLOT(chicked_Goback()));
    connect(NetWorkMode,    SIGNAL(clicked()),this,SLOT(chicked_NetWorkMode()));
    connect(LoacalWorkMode, SIGNAL(clicked()),this,SLOT(chicked_LoacalWorkMode()));
    connect(this,   SIGNAL(SendToParent()),this->parent(),SLOT(display_main()));

}

ManagerModechange::~ManagerModechange()
{

    delete ItemName;
    delete vboxlayout;
    delete NetWorkMode;
    delete LoacalWorkMode;
    delete GoBack;
}



void ManagerModechange::chicked_Goback()
{
    this->close();
     emit SendToParent();
}

void ManagerModechange::chicked_NetWorkMode()
{

}

void ManagerModechange::chicked_LoacalWorkMode()
{

}


