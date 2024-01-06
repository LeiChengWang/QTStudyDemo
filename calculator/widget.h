#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStack>

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
    ~Widget();

    double calculateExpression(const QString &expression);

private slots:

    void on_leftBtn_clicked();

    void on_zerobtn_clicked();

    void on_rightBtn_clicked();

    void on_oneBtn_clicked();

    void on_twoBtn_clicked();

    void on_threeBtn_clicked();

    void on_fourBtn_clicked();

    void on_fiveBtn_clicked();

    void on_sixBtn_clicked();

    void on_sevenBtn_clicked();

    void on_eightBtn_clicked();

    void on_nineBtn_clicked();

    void on_addBtn_clicked();

    void on_subBtn_clicked();

    void on_mulBtn_clicked();

    void on_divBtn_clicked();

    void on_clearBtn_clicked();

    void on_delBtn_clicked();

    void on_equalBtn_clicked();

private:
    Ui::Widget *ui;
    QString expression; //记录表达式
};
#endif // WIDGET_H
