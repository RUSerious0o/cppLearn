#include <QtTest>
#include <QCoreApplication>
#include <QDate>
#include <QString>
#include <QStandardItem>

#include "../../mainwindow.h"

// add necessary includes here

class Organizer_UT : public QObject
{
    Q_OBJECT

public:
    Organizer_UT();
    ~Organizer_UT();

private slots:
    void initTestCase();
    void cleanupTestCase();    
    void test_case_1();


private:
    MainWindow* w;
};

Organizer_UT::Organizer_UT()
{

}

Organizer_UT::~Organizer_UT()
{

}

void Organizer_UT::initTestCase()
{

}

void Organizer_UT::cleanupTestCase()
{

}

void Organizer_UT::test_case_1()
{
    MainWindow w;
    w.show();
    w.setTaskName("Test task");
    w.setTaskDeadline(QDate(2010,10,10));
    w.setTaskProgress(9);
    w.onAddTaskRequested();

    auto task = w.takeTask(w.getTasksCount() - 1);
    QString s = QString("%1 %2 %3")
            .arg(task.at(0)->text())
            .arg(task.at(1)->text())
            .arg(task.at(2)->text());

    QCOMPARE(s, "Test task 10.10.2010 9");
}

QTEST_MAIN(Organizer_UT)

#include "tst_organizer_ut.moc"
