#include "managernetworkset.h"
#include "../log/qlog.h"
#include "../keyborad/digitkey.h"
//************网络管理页面*********************************************


ManagerNetworkSet::ManagerNetworkSet(QWidget *parent):QWidget(parent)
{
    this->resize(1366,768);
    this->setFocusPolicy(Qt::NoFocus);
    QFont wenquanyi30("wenquanyi",  35, QFont::Normal, false);

    LocalIpaddrName      = new QLabel("IP地址：",this);
    LocalGatewayName     = new QLabel("网关：",this);
    LocalSubnetMaskName  = new QLabel("子网掩码：",this);
    LocalDNSName         = new QLabel("DNS：",this);
    LocalPhysicaladdrName= new QLabel("MAC：",this);
    ServerIpName         = new QLabel("服务器IP：",this);
    ServerPortName       = new QLabel("服务器端口：",this);

    LocalIpaddrName->setFont(wenquanyi30);
    LocalGatewayName->setFont(wenquanyi30);
    LocalSubnetMaskName->setFont(wenquanyi30);
    LocalDNSName->setFont(wenquanyi30);
    LocalPhysicaladdrName->setFont(wenquanyi30);
    ServerIpName->setFont(wenquanyi30);
    ServerPortName->setFont(wenquanyi30);

    LocalIpaddrName->setFocusPolicy(Qt::NoFocus);
    LocalGatewayName->setFocusPolicy(Qt::NoFocus);
    LocalSubnetMaskName->setFocusPolicy(Qt::NoFocus);
    LocalDNSName->setFocusPolicy(Qt::NoFocus);
    LocalPhysicaladdrName->setFocusPolicy(Qt::NoFocus);
    ServerIpName->setFocusPolicy(Qt::NoFocus);
    ServerPortName->setFocusPolicy(Qt::NoFocus);

    LocalIpaddr         = new myLineEdit(this);
      LocalIpaddr->setFocus();
    LocalGateway        = new myLineEdit(this);
    LocalSubnetMask     = new myLineEdit(this);
    LocalDNS            = new myLineEdit(this);
    LocalPhysicaladdr   = new myLineEdit(this);
    ServerIp            = new myLineEdit(this);
    ServerPort          = new myLineEdit(this);

    LocalIpaddr->setText("192.168.100.33");
    LocalGateway->setText("192.168.100.1");
    LocalSubnetMask->setText("255.255.255.0");
    LocalDNS->setText("192.168.100.1");
    LocalPhysicaladdr->setText("08:90:00:B0:02:10");
    ServerIp->setText("192.168.100.152");
    ServerPort->setText("4001");

    LocalIpaddr->setFont(QFont("utf-8", 35, QFont::Normal, false ));
    LocalGateway->setFont(QFont("utf-8", 35, QFont::Normal, false ));
    LocalSubnetMask->setFont(QFont("utf-8", 35, QFont::Normal, false ));
    LocalDNS->setFont(QFont("utf-8", 35, QFont::Normal, false ));
    LocalPhysicaladdr->setFont(QFont("utf-8", 35, QFont::Normal, false ));
    ServerIp->setFont(QFont("utf-8", 35, QFont::Normal, false ));
    ServerPort->setFont(QFont("utf-8", 35, QFont::Normal, false ));

    LocalIpaddr->setFocusPolicy(Qt::ClickFocus);
    LocalGateway->setFocusPolicy(Qt::ClickFocus);
    LocalSubnetMask->setFocusPolicy(Qt::ClickFocus);
    LocalDNS->setFocusPolicy(Qt::ClickFocus);
    LocalPhysicaladdr->setFocusPolicy(Qt::ClickFocus);
    ServerIp->setFocusPolicy(Qt::ClickFocus);
    ServerPort->setFocusPolicy(Qt::ClickFocus);

    LocalIpaddr->setAlignment(Qt::AlignHCenter);
    LocalGateway->setAlignment(Qt::AlignHCenter);
    LocalSubnetMask->setAlignment(Qt::AlignHCenter);
    LocalDNS->setAlignment(Qt::AlignHCenter);
    LocalPhysicaladdr->setAlignment(Qt::AlignHCenter);
    ServerIp->setAlignment(Qt::AlignHCenter);
    ServerPort->setAlignment(Qt::AlignHCenter);

    QSize sizeItemName(300,50);
    QSize sizeItem(350,50);


    LocalIpaddrName->resize(sizeItemName);
    LocalGatewayName->resize(sizeItemName);
    LocalSubnetMaskName->resize(sizeItemName);
    LocalDNSName->resize(sizeItemName);
    LocalPhysicaladdrName->resize(sizeItemName);
    ServerIpName->resize(sizeItemName);
    ServerPortName->resize(sizeItemName);

    LocalIpaddr->resize(sizeItem);
    LocalGateway->resize(sizeItem);
    LocalSubnetMask->resize(sizeItem);
    LocalDNS->resize(sizeItem);
    LocalPhysicaladdr->resize(sizeItem);
    ServerIp->resize(sizeItem);
    ServerPort->resize(sizeItem);


    LocalIpaddrName->move(50, 80);
    LocalIpaddr->move(270, 80);

    LocalGatewayName->move(50,150);
    LocalGateway->move(270,150);

    LocalSubnetMaskName->move(50,220);
    LocalSubnetMask->move(270,220);

    LocalDNSName->move(50,290);
    LocalDNS->move(270,290);

    LocalPhysicaladdrName->move(50,360);
    LocalPhysicaladdr->move(270,360);

    ServerIpName->move(50,430);
    ServerIp->move(270,430);

    ServerPortName->move(50,500);
    ServerPort->move(270,500);

    SaveData = new QPushButton("保存",this);
    SaveData->setFont(wenquanyi30);
    SaveData->setFlat(false);
    SaveData->adjustSize();
    SaveData->move(300 , 560);
    SaveData->setFocusPolicy(Qt::NoFocus);

    GoBack = new QPushButton("返回",this);
    GoBack->setFont(wenquanyi30);
    GoBack->setFlat(false);
    GoBack->adjustSize();
    GoBack->move(400 , 560);
    GoBack->setFocusPolicy(Qt::NoFocus);

    //小键盘
    QString keyword("1234567890ABCDEF.");
    int start_x = this->width() / 2;
    int start_y = 80;

    QPushButton *pushbutton;
    for(int i = 0; i < keyword.length() ; i++)
    {
        pushbutton = new QPushButton(QString(keyword[i]), this);
        pushbutton->setFont(QFont("utf-8", 50, QFont::Bold, false ));

        pushbutton->move(start_x, start_y);
        if ( (i + 1) % 5 == 0)
        {
            start_y +=130;
            start_x =this->width() / 2;
        }else{
            start_x += 130;
        }
        pushbutton->resize(100,100);
        pushbutton->setFocusPolicy(Qt::NoFocus);
        connect(pushbutton ,SIGNAL(clicked()), this, SLOT(digitClicked()));
        PushButtons.append(pushbutton);
    }

    pushbutton = new QPushButton(QString("清理"), this);
    pushbutton->setFont(QFont("wenquanyi", 40, QFont::Bold, false ));
    pushbutton->move(start_x + 130, start_y);
    pushbutton->resize(100,100);
    pushbutton->setFocusPolicy(Qt::NoFocus);
    connect(pushbutton ,SIGNAL(clicked()), this, SLOT(digitClicked()));
    PushButtons.append(pushbutton);


    pushbutton = new QPushButton(QString("退格"), this);
    pushbutton->setFont(QFont("wenquanyi", 40, QFont::Bold, false ));
    pushbutton->move(start_x + 260, start_y);
    pushbutton->resize(100,100);
    pushbutton->setFocusPolicy(Qt::NoFocus);
    connect(pushbutton ,SIGNAL(clicked()), this, SLOT(digitClicked()));
    PushButtons.append(pushbutton);



    connect(GoBack,     SIGNAL(clicked()),this,SLOT(chicked_Goback()));
    connect(SaveData,   SIGNAL(clicked()),this,SLOT(chicked_Save()));
    // connect(this,   SIGNAL(SendToParent()),this->parent(),SLOT(display_main()));
    this->setAutoFillBackground(true);
    Dlog()<<"构造";

}

void ManagerNetworkSet::digitClicked()
{
    QPushButton *pushButton = dynamic_cast<QPushButton*>(sender());
    if(pushButton == 0){
        Dlog()<<"键盘出错";
        return;
    }
    pushButton->setEnabled(false);
    disconnect(pushButton,SIGNAL(clicked()), this, SLOT(digitClicked()));

    QWidget *current_focus_widget;
    current_focus_widget = this->focusWidget();

    if (current_focus_widget->inherits("QLineEdit"))
    {
        QLineEdit *le= qobject_cast<QLineEdit*>(current_focus_widget);

        if( pushButton->text() == QString("清理"))
        {
            le->setText(QString(""));
        }else if( pushButton->text() == QString("退格"))
        {
            QString str = le->text();
            if(str.length() > 0)
                le->setText( str.left(str.length()-1) );
        }else{
            QString str = le->text();
            le->setText(str+pushButton->text());
        }

    }

    connect(pushButton,SIGNAL(clicked()), this, SLOT(digitClicked()));
    pushButton->setEnabled(true);
}




ManagerNetworkSet::~ManagerNetworkSet()
{
    QPushButton *pushButton;
    foreach( pushButton , PushButtons)
    {
        disconnect(pushButton ,SIGNAL(clicked()), this, SLOT(digitClicked()));
        delete pushButton;
    }
    delete LocalIpaddrName;
    delete LocalGatewayName;
    delete LocalSubnetMaskName;
    delete LocalDNSName;
    delete LocalPhysicaladdrName;
    delete ServerIpName;
    delete ServerPortName;

    delete LocalIpaddr;
    delete LocalGateway;
    delete LocalSubnetMask;
    delete LocalDNS;
    delete LocalPhysicaladdr;
    delete ServerIp;
    delete ServerPort;


    delete SaveData;
    delete GoBack;

        Dlog()<<tr("虚构");


}





void ManagerNetworkSet::chicked_Goback()
{
    delete this;
   // emit SendToParent();
}
void ManagerNetworkSet::chicked_Save()
{

}

