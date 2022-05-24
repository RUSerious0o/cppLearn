#include "fileexplorer.h"

#include <QObject>
#include <QFileSystemModel>
#include <QTreeView>
#include <QWidget>
#include <QBoxLayout>
#include <QLineEdit>
#include <QTreeView>
#include <QString>

FileExplorer::FileExplorer(QWidget *parent) : QWidget(parent),
    model(new QFileSystemModel),
    mainLayout(new QVBoxLayout(this)),
    lineEdit(new QLineEdit(this)),
    treeView(new QTreeView(this))
{
    this->setLayout(mainLayout);
    treeView->setModel(model);

    mainLayout->addWidget(lineEdit);
    mainLayout->addWidget(treeView);
    mainLayout->setMargin(0);

    lineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    model->setRootPath(QDir::currentPath());
    model->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Drives);
    model->setNameFilters({ "*.txt" });
    model->setNameFilterDisables(false);

    for(int i = 1; i < model->columnCount(); ++i) {
        treeView->hideColumn(i);
    }
    treeView->setHeaderHidden(true);

    expandCurrentDirectory();

    connect(treeView, &QTreeView::clicked, this, &FileExplorer::onItemSelected);
}

void FileExplorer::onItemSelected(const QModelIndex &index)
{
    lineEdit->setText(model->filePath(index));
    emit itemSelected(model->filePath(index));
}

void FileExplorer::expandCurrentDirectory()
{
    QStringList parts = QDir::currentPath().split("/");

    if(parts.size() > 0) {

        for(int i = 0; i < parts.size(); ++i) {
            QString currentPath;
            for(int j = 0; j <= i; ++j) {
                currentPath.append(parts.at(j)).append("/");
            }
            treeView->expand(model->index(currentPath));
        }
    }
}
