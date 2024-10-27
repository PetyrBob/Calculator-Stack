#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->point, &QPushButton::clicked, this, [=]() { addDigit('.'); });
    connect(ui->zero, &QPushButton::clicked, this, [=]() { addDigit(0); });
    connect(ui->one, &QPushButton::clicked, this, [=]() { addDigit(1); });
    connect(ui->two, &QPushButton::clicked, this, [=]() { addDigit(2); });
    connect(ui->three, &QPushButton::clicked, this, [=]() { addDigit(3); });
    connect(ui->four, &QPushButton::clicked, this, [=]() { addDigit(4); });
    connect(ui->five, &QPushButton::clicked, this, [=]() { addDigit(5); });
    connect(ui->six, &QPushButton::clicked, this, [=]() { addDigit(6); });
    connect(ui->seven, &QPushButton::clicked, this, [=]() { addDigit(7); });
    connect(ui->eight, &QPushButton::clicked, this, [=]() { addDigit(8); });
    connect(ui->nine, &QPushButton::clicked, this, [=]() { addDigit(9); });

    connect(ui->add, &QPushButton::clicked, this, [=]() { addOperator('+'); });
    connect(ui->minus, &QPushButton::clicked, this, [=]() { addOperator('-'); });
    connect(ui->multiply, &QPushButton::clicked, this, [=]() { addOperator('*'); });
    connect(ui->divide, &QPushButton::clicked, this, [=]() { addOperator('/'); });

    connect(ui->equal, &QPushButton::clicked, this, &MainWindow::evaluateExpression);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearExpression);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addDigit(int digit)
{
    QString currentText = ui->lineEdit->text();
    currentText += QString::number(digit); 
    ui->lineEdit->setText(currentText);

    numberStack.push(digit); 
}

void MainWindow::clearExpression()
{
    ui->lineEdit->clear();
}

void MainWindow::addOperator(QChar op)
{
    QString currentText = ui->lineEdit->text();
    currentText += op; 
    ui->lineEdit->setText(currentText);

    operatorStack.push(op); 
}

double MainWindow::performOperation(double a, double b, QChar op)
{
    switch (op.unicode()) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return (b != 0) ? a / b : 0; 
    default: return 0;
    }
}

void MainWindow::evaluateExpression()
{
    double result = 0;

    while (!operatorStack.isEmpty() && !numberStack.isEmpty()) {
        double b = numberStack.pop();
        double a = numberStack.pop();
        QChar op = operatorStack.pop();

        result = performOperation(a, b, op);
        numberStack.push(result); 
    }

    ui->lineEdit->setText(QString::number(result)); 
}
