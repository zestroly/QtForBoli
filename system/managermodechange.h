#ifndef MANAGERMODECHANGE_H
#define MANAGERMODECHANGE_H


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

#include <QWidget>

class ManagerModechange : public QWidget
{
    Q_OBJECT
public:
    explicit ManagerModechange(QWidget *parent = 0);
    ~ManagerModechange();
    
public slots:
    void chicked_Goback();
    void chicked_NetWorkMode();
    void chicked_LoacalWorkMode();

signals:
     void SendToParent();

private:
    QLabel *ItemName;

    QVBoxLayout *vboxlayout;
    QPushButton *NetWorkMode;
    QPushButton *LoacalWorkMode;
    QPushButton *GoBack;
    
};

#endif // MANAGERMODECHANGE_H
