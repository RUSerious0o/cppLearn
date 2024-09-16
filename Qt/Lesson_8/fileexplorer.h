#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QObject>
#include <QWidget>
#include <QFileSystemModel>
#include <QBoxLayout>
#include <QLineEdit>
#include <QTreeView>
#include <QPushButton>

class FileSearchDialog;

class FileExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit FileExplorer(QWidget *parent = nullptr);

signals:
    void itemSelected(const QString& filePath);

private slots:
    void onItemSelected(const QModelIndex& index);
    void onSearchClicked();

private:
    QFileSystemModel *model;    
    QGridLayout *mainLayout;
    QLineEdit *lineEdit;
    QTreeView *treeView;
    QPushButton *searchButton;
    FileSearchDialog *fileSearchDialog;

    const QString SEARCH_BUTTON_ICON_PATH = ":/icons/search_icon.png";

    void expandCurrentDirectory();
};

#endif // FILEEXPLORER_H
