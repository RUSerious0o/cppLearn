#include "filesearchdialog.h"
#include "ui_filesearchdialog.h"

#include <QIcon>
#include <QStandardItemModel>
#include <QString>
#include <QDir>
#include <QStandardItem>
#include <QList>
#include <QDirIterator>
#include <QFileInfo>
#include <QThread>
#include <QSize>

FileSearchDialog::FileSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileSearchDialog),
    searchThread(nullptr)
{
    ui->setupUi(this);
    setupResultView();

    ui->searchButton->setIcon(QIcon(SEARCH_BUTTON_ICON_PATH));

    this->resize(800,600);

    ui->selectedDirectoryLabel->setText(DEFAULT_SEARCH_DIRECTORY);
    ui->requestLineEdit->setText(".txt");

    connect(this, &FileSearchDialog::targetFound, this, &FileSearchDialog::onTargetFound);
}

FileSearchDialog::~FileSearchDialog()
{
    delete ui;
    delete model;
}

void FileSearchDialog::setSearchPath(const QString &path)
{
    ui->selectedDirectoryLabel->setText(path);
}

void FileSearchDialog::onSearchClicked()
{
    if(ui->requestLineEdit->text() == "") return;

    model->removeRows(0, model->rowCount());

    if(searchThread != nullptr) {
        searchThread->terminate();
    }

    searchThread = QThread::create([this](){
        QDirIterator it(ui->selectedDirectoryLabel->text(), QDirIterator::Subdirectories);
        while(it.hasNext()) {
            QFileInfo info(QFile(it.next()));
            if(info.isFile() || info.isDir()) {
                if(info.fileName().contains(ui->requestLineEdit->text(), Qt::CaseInsensitive)) {
                    emit targetFound(info);
                }
            }
        }
    });

    searchThread->start();
}

void FileSearchDialog::onTargetFound(const QFileInfo &fileInfo)
{
    model->appendRow({
                         new QStandardItem(fileInfo.fileName()),
                         new QStandardItem(fileInfo.absoluteFilePath())
                     });
}

void FileSearchDialog::setupResultView()
{
    model = new QStandardItemModel(this);
    ui->searchResultView->setModel(model);

    model->setColumnCount(2);
    model->setHeaderData(0, Qt::Horizontal, "Название");
    model->setHeaderData(1, Qt::Horizontal, "Путь");    

    ui->searchResultView->setColumnWidth(1, 600);

    connect(ui->searchButton, &QPushButton::clicked, this, &FileSearchDialog::onSearchClicked);
}

