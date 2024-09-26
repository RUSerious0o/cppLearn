#include "fileexplorer.h"

#include <QObject>
#include <QFileSystemModel>
#include <QTreeView>
#include <QWidget>
#include <QBoxLayout>
#include <QLineEdit>
#include <QTreeView>
#include <QString>
#include <QPushButton>

#include "filesearchdialog.h"

FileExplorer::FileExplorer(QWidget *parent) : QWidget(parent),
    model(new QFileSystemModel),    
    mainLayout(new QGridLayout(this)),
    lineEdit(new QLineEdit(this)),
    treeView(new QTreeView(this)),
    searchButton(new QPushButton(this)),
    fileSearchDialog(new FileSearchDialog(this))
{
    this->setLayout(mainLayout);
    treeView->setModel(model);

    mainLayout->addWidget(lineEdit, 0, 0);
    mainLayout->addWidget(searchButton, 0, 1);
    mainLayout->addWidget(treeView, 1, 0, 1, 2);
    mainLayout->setMargin(0);

    lineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    lineEdit->setReadOnly(true);

    searchButton->setIcon(QIcon(SEARCH_BUTTON_ICON_PATH));
    connect(searchButton, &QPushButton::clicked, this, &FileExplorer::onSearchClicked);

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

void FileExplorer::onSearchClicked()
{
    fileSearchDialog->show();
    if(lineEdit->text() != "") {
        fileSearchDialog->setSearchPath(lineEdit->text());
    }
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
