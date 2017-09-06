#ifndef CHECKDEV_H
#define CHECKDEV_H
#include <QProgressBar>
#include <QDialog>
#include <QPushButton>
#include <QLCDNumber>
#include <QTimer>
#include <QThread>

#include "verificationmethod.h"
class VerificationMethod;
class CheckWorkThread:public QThread
{
    Q_OBJECT
private:
    void run();
signals:
    void willdeleteself();
    void ChangeProessBar(int value);
    void SendResultWithCheck(int result);

public:
    int checkway;
    int SeleteIDcardFromDB(QString str); // <=0 出错和未找到，  找到返回锁号



};


class CheckDev : public QDialog
{
    Q_OBJECT   
public:
    explicit CheckDev(QWidget *parent = 0,int number = 0);

    ~CheckDev();
signals:
    void willdeleteself();
private slots:
    //触摸屏设备会可能会产生多次信号
    void on_Ensure_clicked();
    void on_Cancel_clicked();
    void timeDecCount();
    void ThreadChangeProessBar(int value);
    void ThreadSendResultWithCheck(int result);

private:
    QProgressBar *progressBar;
    QPushButton  *Ensure;
    QPushButton  *Cancel;
    QLCDNumber   *lcdNumber;
    QTimer       *timer;
    CheckWorkThread *workthread;
    VerificationMethod *parentthis;


};

#endif // CHECKDEV_H
