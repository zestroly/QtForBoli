#ifndef MANAGERUSER_H
#define MANAGERUSER_H

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
#include <QLineEdit>
#include "../user/mylineedit.h"

class myQuser {
public:
    myQuser(QWidget *parent = 0, int width = 0, int heith = 0);
    ~myQuser();
private:
    QLineEdit   *lineEdit;
    QPushButton *changeButton;
    QPushButton *eraseButton;
};


//***********ManagerTable
class ManagerTable:public QWidget
{
    Q_OBJECT
public:
    explicit ManagerTable(QWidget *parent = 0);
    ~ManagerTable();
signals:
    void SendToParent(QString SelfName);

public slots:
    void clicked_SaveData();
    void clicked_Goback();

private:
    QList<QLabel*> labels;
    QList<myLineEdit*> lineEdits;
    QList<QPushButton*> pushButtons;


};




//***********ManagerUser
class ManagerUser:public QWidget
{
    Q_OBJECT
public:
    explicit ManagerUser(QWidget *parent = 0);

    ~ManagerUser();

signals:
    void SendToParent(QString SelfName);

public slots:
    void clicked_NewUser();
    void clicked_Goback();
    void digitClicked();
    void RecvFromChild(QString ChildrenName);

private:
    ManagerTable * MTable;
    QWidget     *displayWidget;
    QList<myQuser*> p_myQuser;
    QList<QPushButton*> PushButtons;
    QScrollArea *scrollArea;
    QPushButton *GoBack;
    QPushButton *NewUser;


};







#endif // MANAGERUSER_H
