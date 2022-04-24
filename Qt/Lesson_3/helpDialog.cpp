#include "helpDialog.h"
#include "ui_helpDialog.h"

#include <QTextStream>
#include <QFile>

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);

    QFile helpFile(HELP_DIALOG_TEXT_PATH);
    if(helpFile.open(QFile::ReadOnly | QFile::ExistingOnly)) {
        QTextStream data(&helpFile);
        ui->helpLabel->setText(data.readAll());
        helpFile.close();
    }
}

HelpDialog::~HelpDialog()
{
    delete ui;
}
