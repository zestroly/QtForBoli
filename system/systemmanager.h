#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QWidget>
#include <QDateTimeEdit>
#include <QScrollArea>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QGridLayout>
#include <QDateTimeEdit>
#include <QScrollArea>
#include <QTextEdit>
#include <QPainter>
#include "managernetworkset.h"
#include "manageruser.h"
#include "managermodechange.h"
#include "managerlockcontrol.h"
#include "managerdatetime.h"

//主页面类

class SystemManager : public QWidget
{
    Q_OBJECT
public:
    explicit SystemManager(QWidget *parent = 0);
    ~SystemManager();
signals:

private:
    QPushButton *Modeset;
    QPushButton *UserManager;
    QPushButton *IpConfig;
    QPushButton *BoxManager;
    QPushButton *SystemTimeSet;
    QPushButton *Goback;

    ManagerUser *Muser;
public slots:
    void chicked_Modeset();
    void chicked_UserManager();
    void chicked_IpConfig();
    void chicked_SystemTimeSet();
    void chicked_Goback();
    void display_main();
    void chicked_BoxManager();

    void RecvFromChild(QString ChildrenName);


};

#endif // SYSTEMMANAGER_H
