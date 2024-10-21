#ifndef FILMDB_H
#define FILMDB_H

#include <QObject>
#include <QString>
#include <QList>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

// Определяем имя и расположение файла базы данных
#define DATABASE_NAME "films.db"

class FilmDB : public QObject {
    Q_OBJECT

public:
    FilmDB(QObject* parent = nullptr);
    ~FilmDB();

    QStringList get_good_films_of_genre(int rating, const QString& genre);
    QStringList get_films_of_genre_less_than(int time, const QString& genre);
    QStringList get_films_less_than(int time);
    int count_genre(const QString& genre);

private:
    QSqlDatabase db;

    void initDatabase();
    bool openDatabase();
    void closeDatabase();
    QStringList executeQuery(const QString& queryStr, const QVariantList& args, const QStringList& paramNames);

};

#endif // FILMDB_H
