#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(QWidget *parent = nullptr);
    ~HelpDialog();

    void setContent(const QString &filePath);

    void showEvent(QShowEvent *event) override;
private:
    Ui::HelpDialog *ui;

    QString helpPath;
};

#endif // HELPDIALOG_H
