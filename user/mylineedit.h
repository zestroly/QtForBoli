#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H
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

class myLineEdit : public QLineEdit
{
        Q_OBJECT

 public:
       myLineEdit(QWidget *parent=0);
       ~myLineEdit();
 protected:
       virtual void focusInEvent(QFocusEvent *e);
       virtual void focusOutEvent(QFocusEvent *e);
       virtual void keyPressEvent(QKeyEvent *event);
       virtual void keyReleaseEvent(QKeyEvent *event);
};


#endif // MYLINEEDIT_H
