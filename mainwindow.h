#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick();
    void calculateTotal();

private:
    QLineEdit *lineEdit;    // LineEdit for input
    QLineEdit *lineEdit_2;  // LineEdit for displaying the total
    QString currentInput;    // Store current input for calculations
};

#endif // MAINWINDOW_H
