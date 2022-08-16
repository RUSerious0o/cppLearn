#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <QLineEdit>
#include <QString>
#include <QTextStream>
#include <QtMath>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calcButton_1_released()
{
    if(ui->aLineInput->text().toDouble() == 0) {
        double x = ui->cLineInput->text().toDouble() / ui->bLineInput->text().toDouble();
        ui->resultLabel->setText(QString("%1").arg(x));
        return;
    }

    double D = calcD();
    if(D < 0) {
        ui->resultLabel->setText("Действительных корней нет");
    } else if (D == 0) {
        QString result;
        double x = - ui->bLineInput->text().toDouble() / (2 * ui->aLineInput->text().toDouble());
        result.setNum(x);
        ui->resultLabel->setText(result);
    } else {
        QTextStream ss;

        double b = ui->bLineInput->text().toDouble();
        double a = ui->aLineInput->text().toDouble();
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);

        ss << "x1 = " << x1 << "\n" << "x2 = " << x2;

        ui->resultLabel->setText(QString("x1 = %1\nx2 = %2").arg(x1).arg(x2));

    }
}

double MainWindow::calcD() {
    for(QLineEdit* lineEdit : std::vector<QLineEdit*>{ui->aLineInput, ui->bLineInput, ui->cLineInput}) {
        convertInputValue(lineEdit);
    }

    int a = ui->aLineInput->text().toDouble();
    int b = ui->bLineInput->text().toDouble();
    int c = ui->cLineInput->text().toDouble();

    return b * b - 4 * a * c;
}

void MainWindow::convertInputValue(QLineEdit* lineEdit) {
    QString newString;
    newString.setNum(lineEdit->text().toDouble());
    lineEdit->setText(newString);
}

void MainWindow::on_calcButton_2_released()
{
    ui->triangleResultLabel->setText(QString("%1").arg(calculateTriangleSide()));
}

double MainWindow::calculateTriangleSide() {
    for(QLineEdit* lineEdit : std::vector<QLineEdit*>{
        ui->aSideLineEdit, ui->bSideLineEdit, ui->angleLineEdit}) {
            convertInputValue(lineEdit);
    }

    double a = ui->aSideLineEdit->text().toDouble();
    double b = ui->bSideLineEdit->text().toDouble();
    double angle = ui->angleLineEdit->text().toDouble();
    if(ui->dergeeRadio->isChecked()) angle = angle * 3.14159265358979323846 / 180;

    return sqrt(a*a + b*b - 2 * a * b * cos(angle));
}

void MainWindow::on_mergeTextButton_released()
{
    ui->rightText->setText(QString("%1%2%3").
                           arg(ui->rightText->toPlainText()).
                           arg("\n").
                           arg(ui->leftText->toPlainText()));
}


void MainWindow::on_perlaceTextButton_released()
{
    ui->leftText->setText(QString("%1").arg(ui->rightText->toPlainText()));
}


void MainWindow::on_htmlButton_released()
{
    ui->leftText->setText("<b><i>Some html text</b></i>");
}

