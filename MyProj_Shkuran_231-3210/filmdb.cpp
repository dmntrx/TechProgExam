#include "filmdb.h"
#include <QDebug>

// Конструктор
FilmDB::FilmDB(QObject* parent) : QObject(parent) {
    initDatabase();
}

// Деструктор
FilmDB::~FilmDB() {
    closeDatabase();
}

// Инициализация базы данных
void FilmDB::initDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Users\\marys\\Desktop\\MyProj_Shkuran_231-3210\\films.db");

    if (!openDatabase()) {
        qWarning() << "Не удалось открыть базу данных!";
    } else {
        qDebug() << "База данных успешно открыта.";
    }
}

// Открытие базы данных
bool FilmDB::openDatabase() {
    if (!db.open()) {
        qWarning() << "Ошибка открытия базы данных:" << db.lastError().text();
        return false;
    }
    return true;
}

// Закрытие базы данных
void FilmDB::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}

// Метод для выполнения SQL-запросов и получения списка строк
QStringList FilmDB::executeQuery(const QString& queryStr, const QVariantList& args, const QStringList& paramNames) {
    QStringList resultList;
    QSqlQuery query(db);

    query.prepare(queryStr);

    // Привязываем параметры к запросу по именам
    for (int i = 0; i < args.size(); ++i) {
        query.bindValue(paramNames[i], args[i]);
    }

    // Выполняем запрос
    if (query.exec()) {
        while (query.next()) {
            resultList.append(query.value(0).toString());
        }
    } else {
        qWarning() << "Ошибка выполнения запроса:" << query.lastError().text();
    }

    return resultList;
}


// Возвращает список фильмов заданного жанра с рейтингом не ниже заданного
QStringList FilmDB::get_good_films_of_genre(int rating, const QString& genre) {
    QString queryStr = "SELECT title FROM films WHERE rating >= :rating AND genre = :genre";
    return executeQuery(queryStr, {rating, genre}, {":rating", ":genre"});
}

// Возвращает список фильмов заданного жанра, чья длительность меньше или равна заданному времени
QStringList FilmDB::get_films_of_genre_less_than(int time, const QString& genre) {
    QString queryStr = "SELECT title FROM films WHERE duration <= :time AND genre = :genre";
    return executeQuery(queryStr, {time, genre}, {":time", ":genre"});
}

// Возвращает список всех фильмов, чья длительность меньше или равна заданному времени
QStringList FilmDB::get_films_less_than(int time) {
    QString queryStr = "SELECT title FROM films WHERE duration <= :time";
    return executeQuery(queryStr, {time}, {":time"});
}

// Возвращает количество фильмов заданного жанра
int FilmDB::count_genre(const QString& genre) {
    QString queryStr = "SELECT COUNT(*) FROM films WHERE genre = :genre";
    QStringList result = executeQuery(queryStr, {genre}, {":genre"});
    return result.isEmpty() ? 0 : result.first().toInt();
}

