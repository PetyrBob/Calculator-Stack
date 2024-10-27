#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addDigit(int digit);
    void addOperator(QChar op);
    void evaluateExpression();
    void clearExpression();

private:
    Ui::MainWindow *ui;
    QStack<double> numberStack;
    QStack<QChar> operatorStack;

    double performOperation(double a, double b, QChar op);
};

#endif // MAINWINDOW_H
