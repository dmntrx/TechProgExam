#include <QCoreApplication>
#include "filmdb.h"
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    FilmDB db;

    // Пример использования методов класса
    QStringList goodActionFilms = db.get_good_films_of_genre(8, "Action");
    qDebug() << "Хорошие фильмы жанра Action с рейтингом 8 и выше:" << (goodActionFilms.isEmpty() ? "Нет фильмов" : goodActionFilms.join(", "));

    QStringList shortDramas = db.get_films_of_genre_less_than(120, "Drama");
    qDebug() << "Драмы длительностью 120 минут и меньше:" << (shortDramas.isEmpty() ? "Нет фильмов" : shortDramas.join(", "));

    QStringList shortFilms = db.get_films_less_than(100);
    qDebug() << "Фильмы длительностью 100 минут и меньше:" << (shortFilms.isEmpty() ? "Нет фильмов" : shortFilms.join(", "));

    int countComedy = db.count_genre("Comedy");
    qDebug() << "Количество комедий в базе данных:" << countComedy;

    return a.exec();
}
