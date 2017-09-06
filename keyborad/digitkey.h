#ifndef DIGITKEY_H
#define DIGITKEY_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QToolButton>
#include <QDebug>
#include <QFocusEvent>

class DigitKey : public QDialog
{
    Q_OBJECT
public:
    explicit DigitKey(QWidget *parent = 0);
    ~DigitKey();
    
signals:
    void setvalue(const QString &);
public slots:
    void digit0Clicked();
    void digit1Clicked();
    void digit2Clicked();
    void digit3Clicked();
    void digit4Clicked();
    void digit5Clicked();
    void digit6Clicked();
    void digit7Clicked();
    void digit8Clicked();
    void digit9Clicked();
    void enterClicked();
    void pointClicked();
    void changeSignClicked();
    void backspaceClicked();
    void clear();
private:
    bool waitingForOperand;

    QLineEdit   *display;

    QToolButton *backspaceButton;
    QToolButton *changeSignButton;
    QToolButton *clearButton;

    QToolButton *enterButton;
    QToolButton *pointButton;
    QToolButton *toolButton_0;
    QToolButton *toolButton_1;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;





};

#endif // DIGITKEY_H
