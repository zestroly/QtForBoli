#ifndef MANAGERLOCKCONTROL_H
#define MANAGERLOCKCONTROL_H

#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QWidget>
#include <QDateTimeEdit>
#include <QScrollArea>
#include <QToolButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QGridLayout>
#include <QDateTimeEdit>
#include <QScrollArea>
#include <QTextEdit>

#include <QWidget>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> //文件控制定义
#include <termios.h>//终端控制定义
#include <errno.h>

#include "../dev/posix_qextserialport.h"

#include "../user/mylineedit.h"




class ManagerLockControl : public QWidget
{
    Q_OBJECT
public:
    explicit ManagerLockControl(QWidget *parent = 0);
    ~ManagerLockControl();   
signals:
     void SendToParent();
    
public slots:
    void chicked_Goback();
    void chicked_SaveData();
    void chicked_OpenSingle();
    void chicked_OpenAll();
    void chicked_Calibration();

    void digitClicked();

private:

    QList<QToolButton*> toolButtons;
    QPushButton *OpenAll;
    QPushButton *OpenSingle;
    QPushButton *GoBack;
    QPushButton *SaveData;
    QPushButton *Calibration;

    QLabel    *LabelBoardNum;
    myLineEdit *LineEditBoardNum;

    QLabel    *LabelBoardLockNum;
    myLineEdit *LineEditBoardLockNum;

    QLabel    *LabelAllNum;
    myLineEdit *LineEditAllNum;

    QLabel    *LabelOpenNum;
    myLineEdit *LineEditOpenNum;

};

#endif // MANAGERLOCKCONTROL_H
