#include "helpDialog.h"
#include "ui_helpDialog.h"

#include <QTextStream>
#include <QFile>
#include <QString>

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
}

HelpDialog::~HelpDialog()
{
    delete ui;
}

void HelpDialog::setContent(const QString &filePath)
{
    helpPath = filePath;
}

void HelpDialog::showEvent(QShowEvent *)
{
    QFile helpFile(helpPath);
    if(helpFile.open(QFile::ReadOnly | QFile::ExistingOnly)) {
        QTextStream data(&helpFile);
        ui->helpLabel->setText(data.readAll());
        helpFile.close();
    }
}
