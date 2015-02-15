#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QMessageBox>
class MyMessageBox : public QMessageBox
{
public:
    MyMessageBox();
   protected:
      void showEvent(QShowEvent* event)
  {
     QMessageBox::showEvent(event);
     setFixedSize(640, 480);
   }
};
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
private slots:
    void calu();
private:
    QString Tf(QString name,int id);
    QPushButton *calbt;
    QPushButton *quitbt;
    QTextEdit *text;
};

#endif // WIDGET_H
