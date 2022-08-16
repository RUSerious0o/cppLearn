#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QObject>
#include <QWidget>
#include <QFileSystemModel>
#include <QBoxLayout>
#include <QLineEdit>
#include <QTreeView>

class FileExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit FileExplorer(QWidget *parent = nullptr);

signals:
    void itemSelected(const QString& filePath);

private slots:
    void onItemSelected(const QModelIndex& index);

private:
    QFileSystemModel *model;
    QVBoxLayout *mainLayout;
    QLineEdit *lineEdit;
    QTreeView *treeView;

    void expandCurrentDirectory();
};

#endif // FILEEXPLORER_H
