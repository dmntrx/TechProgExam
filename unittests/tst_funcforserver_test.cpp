#include <QtTest>
#include "../MyProj_Shkuran_231-3210/filmdb.h"
#include <QCoreApplication>

// add necessary includes here

class FuncForServer_Test : public QObject
{
    Q_OBJECT

public:
    FuncForServer_Test();
    ~FuncForServer_Test();
private:
    QCoreApplication a();
private slots:
    void test_case1();

};

FuncForServer_Test::FuncForServer_Test()
{
}

FuncForServer_Test::~FuncForServer_Test()
{

}

void FuncForServer_Test::test_case1()
{
    FilmDB db;

    QStringList firstTest {};

    QVERIFY(db.count_genre("Action") != 2); // неверное колво
    QVERIFY(db.count_genre("Drama") == 1); // верное колво
    QVERIFY(db.count_genre("Criminal") == 0); // несуществующий жанр

    QVERIFY(db.get_films_of_genre_less_than(100, "Action").isEmpty()); // пустота
    QVERIFY(db.get_films_of_genre_less_than(100, "Comedy").join("") == QString("Toy Story")); // пустота

    QVERIFY(db.get_good_films_of_genre(9,"Action").join("") == QStringList("Inception").join("")); // верное утверждение
    QVERIFY(db.get_good_films_of_genre(9,"Comedy").join("") == QStringList().join("")); // такого фильма нет

    QVERIFY(db.get_films_less_than(100).join("") == QStringList("Toy Story").join("")); // 1 фильм
    QVERIFY(db.get_films_less_than(150).join("") == QString("InceptionToy Story")); // 2 фильма

    QVERIFY(db.get_films_less_than(1500).join("") == QString("InceptionTitanicToy Story")); // 2 фильма

}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);  // создание объекта QCoreApplication

    FuncForServer_Test test;
    return QTest::qExec(&test, argc, argv);  // запуск теста
}

// QTEST_APPLESS_MAIN(FuncForServer_Test)

#include "tst_funcforserver_test.moc"
