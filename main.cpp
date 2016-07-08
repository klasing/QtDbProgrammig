#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString serverName = "(localdb)\\Projects";
    QString dbName = "test";

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();

    //QString dsn = QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(serverName).arg(dbName);
    // this works, but only when opening master
    //QString dsn = QString("Driver={SQL Server Native Client 11.0};Server=(localdb)\\Projects;Database=master;Uid=odbc;Pwd=odbc;");
    // this works, when altering user mappings with SQL Server Management Studio
    QString dsn = QString("Driver={SQL Server Native Client 11.0};Server=(localdb)\\Projects;Database=test;Uid=odbc;Pwd=odbc;");
    db.setDatabaseName(dsn);

    if (db.open()) {
        qDebug() << "Opened!";
        db.close();
    } else {
        qDebug() << "Error: " << db.lastError();
    }

    return a.exec();
}
