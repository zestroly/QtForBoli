#include "systemmanager.h"
#include "../log/qlog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QGridLayout>
#include <QDateTimeEdit>
#include <QScrollArea>
#include <QTextEdit>
#include "../keyborad/digitkey.h"


SystemManager::SystemManager(QWidget *parent):QWidget(parent)
{
    //基本框架设置
    this->resize(1366,768);
    //this->showFullScreen();
    QPalette palettebackground;
    palettebackground.setBrush(QPalette::Background,QBrush(QPixmap("images/3d8010817b8aa2d9191d4060f7576fe6.jpg").scaled(this->size())));
    this->setPalette(palettebackground);

    UserManager = new QPushButton("用户管理",this);
    UserManager->setFont(QFont("wenquanyi",  40, QFont::Bold, false));
    UserManager->setFlat(false);
    UserManager->adjustSize();
    UserManager->move(this->width()/8 , this->height()/4*1);
    UserManager->setFocusPolicy(Qt::NoFocus);


    IpConfig = new QPushButton("网络设置",this);
    IpConfig->setFont(QFont("wenquanyi",  40, QFont::Bold, false));
    IpConfig->setFlat(false);
    IpConfig->adjustSize();
    IpConfig->move(this->width()/8*3 , this->height()/4*1);
    IpConfig->setFocusPolicy(Qt::NoFocus);


    BoxManager = new QPushButton("柜体管理",this);
    BoxManager->setFont(QFont("wenquanyi",  40, QFont::Bold, false));
    BoxManager->setFlat(false);
    BoxManager->adjustSize();
    BoxManager->move(this->width()/8*5 , this->height()/4*1);
    BoxManager->setFocusPolicy(Qt::NoFocus);


    Modeset = new QPushButton("模式设置",this);
    Modeset->setFont(QFont("wenquanyi",  40, QFont::Bold, false));
    Modeset->setFlat(false);
    Modeset->adjustSize();
    Modeset->move(this->width()/8*1 , this->height()/4*2);
    Modeset->setFocusPolicy(Qt::NoFocus);

    SystemTimeSet = new QPushButton("时间日期",this);
    SystemTimeSet->setFont(QFont("wenquanyi",  40, QFont::Bold, false));
    SystemTimeSet->setFlat(false);
    SystemTimeSet->adjustSize();
    SystemTimeSet->move(this->width()/8*3 , this->height()/4*2);
    SystemTimeSet->setFocusPolicy(Qt::NoFocus);

    Goback = new QPushButton(" 返    回 ",this);
    Goback->setFont(QFont("wenquanyi",  40, QFont::Bold, false));
    Goback->setFlat(false);
    Goback->adjustSize();
    Goback->move(this->width()/8*5 , this->height()/4*2);
    Goback->setFocusPolicy(Qt::NoFocus);


    connect(this->Modeset,      SIGNAL(clicked()),this,SLOT(chicked_Modeset()));
    connect(this->UserManager,  SIGNAL(clicked()),this,SLOT(chicked_UserManager()));
    connect(this->IpConfig,     SIGNAL(clicked()),this,SLOT(chicked_IpConfig()));
    connect(this->BoxManager,   SIGNAL(clicked()),this,SLOT(chicked_BoxManager()));
    connect(this->SystemTimeSet,SIGNAL(clicked()),this,SLOT(chicked_SystemTimeSet()));
    connect(this->Goback,       SIGNAL(clicked()),this,SLOT(chicked_Goback()));

    Dlog()<<tr("构造");
    this->setAutoFillBackground(true);
}

void SystemManager::RecvFromChild(QString ChildrenName)
{
    Dlog()<<ChildrenName;
    if(ChildrenName == QString("ManagerUser"))
    {
        delete Muser;
        Muser = NULL;
    }
}




void SystemManager::chicked_Modeset()
{

    Dlog()<<tr("模式设置");
}
void SystemManager::chicked_UserManager()
{
    Muser = new ManagerUser(this);
    Muser->show();

    Dlog()<<tr("用户管理");
}
void SystemManager::chicked_IpConfig()
{
    ManagerNetworkSet *w = new ManagerNetworkSet(this);
    w->show();
    Dlog()<<tr("网络设置");
}
void SystemManager::chicked_BoxManager()
{
    ManagerLockControl *w = new ManagerLockControl(this);
    w->show();
    Dlog()<<tr("柜体管理");
}
void SystemManager::chicked_SystemTimeSet()
{
    Dlog()<<tr("时间日期");
}
void SystemManager::chicked_Goback()
{
    Dlog()<<tr("返回");
    delete this;
}

void SystemManager::display_main()
{

}


void clear_obj(QObjectList objlist)
{

    foreach(QObject* obj, objlist)
    {
        if(!obj->children().isEmpty())
        {
            clear_obj(obj->children());
            Dlog()<<obj->children().count();
        } else{
            Dlog()<<"111111111";

            if(obj->inherits("QPushButton"))
            {
                delete obj;
            }else if(obj->inherits("QLineEdit"))
            {
                delete obj;
            }else if(obj->inherits("QLabel"))
            {
                delete obj;
            }else if(obj->inherits("QScrollArea"))
            {
                delete obj;
            }else if (obj->inherits("QWidget"))
            {
                // delete obj;
            }
        }
    }

}


SystemManager::~SystemManager()
{
    disconnect(this->Modeset,      SIGNAL(clicked()),this,SLOT(chicked_Modeset()));
    disconnect(this->UserManager,  SIGNAL(clicked()),this,SLOT(chicked_UserManager()));
    disconnect(this->IpConfig,     SIGNAL(clicked()),this,SLOT(chicked_IpConfig()));
    disconnect(this->BoxManager,   SIGNAL(clicked()),this,SLOT(chicked_BoxManager()));
    disconnect(this->SystemTimeSet,SIGNAL(clicked()),this,SLOT(chicked_SystemTimeSet()));
    disconnect(this->Goback,       SIGNAL(clicked()),this,SLOT(chicked_Goback()));
    delete Modeset;
    delete UserManager;
    delete IpConfig;
    delete BoxManager;
    delete SystemTimeSet;
    delete Goback;
    Dlog()<<tr("虚构");
}





































