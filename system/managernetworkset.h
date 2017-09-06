#ifndef MANAGERNETWORKSET_H
#define MANAGERNETWORKSET_H

#include <QWidget>
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
#include <QToolButton>
#include "../user/mylineedit.h"
#include <QList>

//************网络管理页面*********************************************
class ManagerNetworkSet:public QWidget
{
    Q_OBJECT
public:
    ManagerNetworkSet(QWidget *parent = 0);
    ~ManagerNetworkSet();

signals:
     void SendToParent();

public slots:
    void chicked_Save();
    void chicked_Goback();

    void digitClicked();

private:
    QList<QPushButton*> PushButtons;

    QLabel *LocalIpaddrName;
    QLabel *LocalGatewayName;
    QLabel *LocalSubnetMaskName;
    QLabel *LocalDNSName;
    QLabel *LocalPhysicaladdrName;
    QLabel *ServerIpName;
    QLabel *ServerPortName;

    myLineEdit *LocalIpaddr;
    myLineEdit *LocalGateway;
    myLineEdit *LocalSubnetMask;
    myLineEdit *LocalDNS;
    myLineEdit *LocalPhysicaladdr;
    myLineEdit *ServerIp;
    myLineEdit *ServerPort;


    QPushButton *SaveData;
    QPushButton *GoBack;
};

#endif // MANAGERNETWORKSET_H
