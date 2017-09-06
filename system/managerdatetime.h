#ifndef MANAGERDATETIME_H
#define MANAGERDATETIME_H

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

class ManagerDateTime : public QWidget
{
    Q_OBJECT
public:
    explicit ManagerDateTime(QWidget *parent = 0);
    ~ManagerDateTime();
    
signals:
    void SendToParent();
    
public slots:
    void clicked_yearbutton();
    void clicked_datebutton();
    void clicked_timebutton();
    void clicked_GoBack();
    void clicked_SaveData();


private:
    QLabel *ItemName;
    QGridLayout *gridLayout;

    QLabel *yearLabel;
    QLabel *dateLabel;
    QLabel *timeLabel;

    QLineEdit *yearLine;
    QLineEdit *dateLine;
    QLineEdit *timeLine;

    QPushButton *yearbutton;
    QPushButton *datebutton;
    QPushButton *timebutton;
    QPushButton *GoBack;
    QPushButton *SaveData;
    
};

#endif // MANAGERDATETIME_H
