#ifndef FILESEARCHDIALOG_H
#define FILESEARCHDIALOG_H

#include <QDialog>
#include <QString>
#include <QStandardItemModel>
#include <QDir>
#include <QThread>

namespace Ui {
class FileSearchDialog;
}

class FileSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileSearchDialog(QWidget *parent = nullptr);
    ~FileSearchDialog();

    void setSearchPath(const QString &path);

private slots:
    void onSearchClicked();
    void onTargetFound(const QFileInfo &fileInfo);

signals:
    void targetFound(const QFileInfo &fileInfo);

private:
    Ui::FileSearchDialog *ui;
    QStandardItemModel *model;
    QThread *searchThread;

    const QString DEFAULT_SEARCH_DIRECTORY = "/";
    const QString SEARCH_BUTTON_ICON_PATH = ":/icons/search_icon.png";

    void setupResultView();
};

#endif // FILESEARCHDIALOG_H
