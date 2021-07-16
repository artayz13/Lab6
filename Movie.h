#ifndef INC_2021_SUMMER_CSCI2421_MOVIE_H
#define INC_2021_SUMMER_CSCI2421_MOVIE_H

#include "string"
#include "memory"
#include "LinkedBag.h"
#include "Actor.h"

using namespace std;

class Movie {
private:
    string title;
    int releaseYear;
    LinkedBag<shared_ptr<Actor>> actors;

public:
    explicit Movie();

    explicit Movie(const string &aTitle, int year);

    ~Movie();

    string getTitle() const;

    void setTitle(const string &aTitle);

    int getReleaseYear() const;

    void setReleaseYear(int year);

    friend ostream &operator<<(ostream &out, const Movie &aMovie);

    bool addActor(const shared_ptr<Actor> &anActor);

    bool removeActor(const shared_ptr<Actor> &anActor);

    vector<shared_ptr<Actor>> getActors() const;
};

#include "Movie.cpp"


#endif //INC_2021_SUMMER_CSCI2421_MOVIE_H
