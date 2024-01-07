#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#define TIME_OUT 1 * 1000

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void timerEvent(QTimerEvent *event);
    ~Widget();

private slots:
    void on_startBtn_clicked();

    void on_stopBtn_clicked();

private:
    Ui::Widget *ui;
    int myTimerID;
    int picID;
};
#endif // WIDGET_H
