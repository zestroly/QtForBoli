#include "managerdatetime.h"
#include "../log/qlog.h"

ManagerDateTime::ManagerDateTime(QWidget *parent) :
    QWidget(parent)
{  
    this->resize(700,350);
    this->setAutoFillBackground(false);
    this->setFocusPolicy(Qt::NoFocus);

    ItemName = new QLabel("时间设置");
    ItemName->setFont(QFont("quanwenyi", 30 ,QFont::Light, false));
    ItemName->setAlignment(Qt::AlignHCenter);
    ItemName->setFocusPolicy(Qt::NoFocus);

    gridLayout = new QGridLayout(this);


    yearLabel  = new QLabel("年份");
    dateLabel  = new QLabel("日期");
    timeLabel  = new QLabel("时间");
    yearLabel->setFont(QFont("wenquanyi",  25, QFont::Light, false));
    dateLabel->setFont(QFont("wenquanyi",  25, QFont::Light, false));
    timeLabel->setFont(QFont("wenquanyi",  25, QFont::Light, false));
    yearLabel->setFocusPolicy(Qt::NoFocus);
    dateLabel->setFocusPolicy(Qt::NoFocus);
    timeLabel->setFocusPolicy(Qt::NoFocus);


    yearLine = new QLineEdit("2016");
    dateLine = new QLineEdit("04/27");
    timeLine = new QLineEdit("15:09");
    yearLine->setFocusPolicy(Qt::NoFocus);
    dateLine->setFocusPolicy(Qt::NoFocus);
    timeLine->setFocusPolicy(Qt::NoFocus);
    yearLine->setFont(QFont("quanwenyi",  25, QFont::Light, false));
    dateLine->setFont(QFont("quanwenyi",  25, QFont::Light, false));
    timeLine->setFont(QFont("quanwenyi",  25, QFont::Light, false));

    yearLine->setFocusPolicy(Qt::NoFocus);
    dateLine->setFocusPolicy(Qt::NoFocus);
    timeLine->setFocusPolicy(Qt::NoFocus);
    yearLine->setAlignment(Qt::AlignCenter);
    dateLine->setAlignment(Qt::AlignCenter);
    timeLine->setAlignment(Qt::AlignCenter);

    yearbutton = new QPushButton("修改");
    datebutton = new QPushButton("修改");
    timebutton = new QPushButton("修改");
    yearbutton->setFocusPolicy(Qt::NoFocus);
    datebutton->setFocusPolicy(Qt::NoFocus);
    timebutton->setFocusPolicy(Qt::NoFocus);
    yearbutton->setFont(QFont("quanwenyi",  25, QFont::Light, false));
    datebutton->setFont(QFont("quanwenyi",  25, QFont::Light, false));
    timebutton->setFont(QFont("quanwenyi",  25, QFont::Light, false));

    SaveData   = new QPushButton("保存");
    GoBack     = new QPushButton("返回");
    SaveData->setFocusPolicy(Qt::NoFocus);
    GoBack->setFocusPolicy(Qt::NoFocus);

    GoBack->setFont(QFont("quanwenyi",  25, QFont::Light, false));
    SaveData->setFont(QFont("quanwenyi",  25, QFont::Light, false));

    gridLayout->addWidget(ItemName   , 0 , 0 ,1, 9);

    gridLayout->addWidget(yearLabel   , 1 , 0 , 1 , 1);
    gridLayout->addWidget(yearLine, 1 , 1 , 1 , 7);
    gridLayout->addWidget(yearbutton  , 1 , 8 , 1 , 1 );

    gridLayout->addWidget(dateLabel,   2 , 0 , 1 , 1);
    gridLayout->addWidget(dateLine,2 , 1 , 1 , 7);
    gridLayout->addWidget(datebutton,  2 , 8 , 1 , 1);

    gridLayout->addWidget(timeLabel,   3 , 0 , 1 , 1);
    gridLayout->addWidget(timeLine,3 , 1 , 1 , 7);
    gridLayout->addWidget(timebutton,  3 , 8 , 1 , 1);

    gridLayout->addWidget(SaveData,   6 , 5 , 1 , 1);
    gridLayout->addWidget(GoBack, 6 , 7 , 1 , 1);


    this->setLayout(gridLayout);

    connect(GoBack,     SIGNAL(clicked()),this,SLOT(clicked_GoBack()));
    connect(SaveData,   SIGNAL(clicked()),this,SLOT(clicked_SaveData()));
    connect(this,   SIGNAL(SendToParent()),this->parent(),SLOT(display_main()));


    //    ItemName    = new QLabel(frame);
    //    ItemName->setGeometry(0,0,320,61);
    //    ItemName->setAlignment(Qt::AlignHCenter);
    //    ItemName->setText(tr("时间设置"));
    //    ItemName->setFont(QFont("quanwenyi", 35 ,QFont::Normal, false));
    //    ItemName->show();

    //    display_6_Save = new QPushButton(this);
    //    display_6_Save->setGeometry(880,520,141,51);
    //    display_6_Save->setText(tr("保存"));
    //    display_6_Save->setFont(QFont("quanwenyi",  30, QFont::Light, false));
    //    display_6_Save->show();

    //    display_6_Goback = new QPushButton(this);
    //    display_6_Goback->setGeometry(880,620,141,51);
    //    display_6_Goback->setText(tr("返回"));
    //    display_6_Goback->setFont(QFont("quanwenyi",  30, QFont::Light, false));
    //    display_6_Goback->show();

    //    connect(this->display_6_Goback,     SIGNAL(clicked()),this,SLOT(display_6_chicked_Goback()));
    //    connect(this->display_6_Save,       SIGNAL(clicked()),this,SLOT(display_6_chicked_Save()));


    //    datetimeEdit = new QDateTimeEdit(QDateTime::currentDateTime(),this);
    //    datetimeEdit->setDisplayFormat("yyyy-MM-dd  hh:mm:ss");
    //    datetimeEdit->setFont(QFont("quanwenyi",  30, QFont::Light, false) );
    //    datetimeEdit->setGeometry(400,220,500,60);
    //    datetimeEdit->show();
}


ManagerDateTime::~ManagerDateTime()
{

    delete ItemName;
    delete gridLayout;

    delete yearLabel;
    delete dateLabel;
    delete timeLabel;

    delete yearLine;
    delete dateLine;
    delete timeLine;

    delete yearbutton;
    delete datebutton;
    delete timebutton;
    delete GoBack;
    delete SaveData;
}


void ManagerDateTime::clicked_yearbutton()
{

}

void ManagerDateTime::clicked_datebutton()
{

}

void ManagerDateTime::clicked_timebutton()
{

}

void ManagerDateTime::clicked_GoBack()
{
    this->close();
    Dlog()<<"关闭窗口";
    emit SendToParent();
}

void ManagerDateTime::clicked_SaveData()
{

}
