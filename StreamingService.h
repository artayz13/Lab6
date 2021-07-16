#ifndef INC_2021_SUMMER_CSCI2421_STREAMINGSERVICE_H
#define INC_2021_SUMMER_CSCI2421_STREAMINGSERVICE_H

#include "string"
#include "memory"
#include "LinkedBag.h"
#include "BinarySearchTree.h"
#include "Movie.h"
#include "Actor.h"
#include "MovieComparator.h"

using namespace std;

class StreamingService {
private:
    unique_ptr<LinkedBag<shared_ptr<Movie>>> movies;
    unique_ptr<LinkedBag<shared_ptr<Actor>>> actors;
    unique_ptr<BinarySearchTree<shared_ptr<Movie>>> moviesIndex;


public:
    explicit StreamingService();

    virtual ~StreamingService();

    bool addMovie(const string &title, int year);

    bool addActor(const string &name);

    bool addActorToMovie(const string &title, const string &actorName);

    bool isMovieAvailable(const string &title);

    /**
     * Searchs for a movie with the exact same title as the given argument.
     * @param title
     * @return
     */
    shared_ptr<Movie> searchMovieExact(const string &title);

    /**
     * Search for all movies that have the patter in their title (case-insensitive)
     * @param titlePattern
     * @return
     */
    vector<shared_ptr<Movie>> searchMoviePattern(const string &titlePattern);

    /**
     * Search for the Actor with the exact given name.
     * @param actorName
     * @return
     */
    shared_ptr<Actor> searchActor(const string &actorName);

    friend std::ostream &operator<<(std::ostream &out, const StreamingService &service);

    /**
     * Visits the movies, sorted by title, calling the argument function for each one.
     * @param visit
     */
    void visitMoviesSorted(void visit(shared_ptr<Movie> &)) const;
};

#include "StreamingService.cpp"

#endif
