#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <QtGui/QWidget>
#include <QBrush>
#include <QTextCodec>
#include <QDebug>
#include <QDateTime>
#include <QPushButton>
#include <QLabel>
#include <QAction>
#include <QToolBar>
#include <QPalette>
#include <QLabel>
#include <QFrame>
#include <QGraphicsView>
#include "verificationmethod.h"
#include <QTime>
#include <QLCDNumber>

class VerificationMethod;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   VerificationMethod* verificationMethon;
    
private slots:
    void on_PutInPacketage_clicked();
    void on_TakeOutPacketage_clicked();
    void on_RunModeChange_clicked();
    void on_AdminiLogin_clicked();
    void timeUpDate();
    void connectPuttonSignal();
    void disconnectPuttonSignal();

    void SignalFromChildren(QString childrenwindows);

private:
 //   Ui::MainWindow *ui;
    QPushButton* PutInPacketage;
    QPushButton* TakeOutPacketage;
    QPushButton *AdminiLogin;
    QPushButton *ExitButton;

    QTimer *timer;
    QLCDNumber *timelabel;
    QLabel *RunMode;

    int x;
    int y;

};

#endif // MAINWINDOW_H
