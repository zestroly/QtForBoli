#include "mylineedit.h"

myLineEdit::myLineEdit(QWidget *parent):QLineEdit(parent)
{

}

myLineEdit::~myLineEdit()
{

}

void myLineEdit::focusInEvent(QFocusEvent *e)
{
       QPalette p=QPalette();
       p.setColor(QPalette::Base,Qt::gray);    //QPalette::Base 对可编辑输入框有效，还有其他类型，具体的查看文档
       setPalette(p);
}

void myLineEdit::focusOutEvent(QFocusEvent *e)
{
       QPalette p1=QPalette();
       p1.setColor(QPalette::Base,Qt::white);
       setPalette(p1);
}

void myLineEdit::keyPressEvent(QKeyEvent *event)
{
  //  Dlog()<<event->text()<<"button press";
}

void myLineEdit::keyReleaseEvent(QKeyEvent *event)
{
  //  Dlog()<<"button Release";
}
