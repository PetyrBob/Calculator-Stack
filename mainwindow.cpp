#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), currentInput("") {

    // Set up central widget and layout
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QGridLayout *layout = new QGridLayout(centralWidget);

    // Create line edits
    lineEdit = new QLineEdit(this);
    lineEdit_2 = new QLineEdit(this);
    lineEdit_2->setReadOnly(true);

    layout->addWidget(lineEdit, 0, 0, 1, 4);
    layout->addWidget(lineEdit_2, 1, 0, 1, 4);

    // Create buttons
    QStringList buttonLabels = { "7", "8", "9", "/",
                                "4", "5", "6", "*",
                                "1", "2", "3", "-",
                                "C", "0", "=", "+" };

    int pos = 2;
    for (const QString &label : buttonLabels) {
        QPushButton *button = new QPushButton(label, this);
        layout->addWidget(button, pos / 4 + 2, pos % 4);
        connect(button, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
        pos++;
    }

    setWindowTitle("Calculator");
}

MainWindow::~MainWindow() {}

void MainWindow::handleButtonClick() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString buttonText = button->text();
        if (buttonText == "=") {
            calculateTotal();
        } else if (buttonText == "C") {
            currentInput.clear();
            lineEdit->clear();
            lineEdit_2->clear();
        } else {
            currentInput += buttonText;
            lineEdit->setText(currentInput);
        }
    }
}

void MainWindow::calculateTotal() {
    // Here you can use QScriptEngine or a simple parser to evaluate the expression.
    // For simplicity, we will show a message box instead.
    // You should implement a proper calculation method.

    // Example implementation: Just displaying the input for now.
    lineEdit_2->setText(currentInput); // Replace this with actual calculation
}
