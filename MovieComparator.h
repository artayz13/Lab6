#ifndef CSCI2421_MOVIECOMPARATOR_H
#define CSCI2421_MOVIECOMPARATOR_H

#include "memory"
#include "Movie.h"
#include "Comparator.h"

using namespace std;

/**
 * TODO #2: Check the MovieComparator
 *
 * Compares to movies by title.
 *
 * This is a simple implementation of a comparator.
 * Note that a MovieComparator object is a specialization of the type Comparator< shared_ptr<Movie> >
 *
 * Having this implementation instead of overriding the operators allows us to have multiple comparisons,
 * say by title one, another by release year, and so on.
 *
 *
 * if you are interested in this, feel free to ask your instructor.
 */
class MovieComparator : public Comparator<shared_ptr<Movie>> {
public:
    /**
     * @param lhs
     * @param rhs
     * @return  true when lhs.title < rhs.title. False otherwise.
     */
    bool lessThan(const shared_ptr<Movie> &lhs, const shared_ptr<Movie> &rhs) noexcept(false) override {
        if (lhs == nullptr || rhs == nullptr)
            throw logic_error("Cant compare NULLPTR");

        return lhs->getTitle() < rhs->getTitle();
    };

    /**
     * @param lhs
     * @param rhs
     * @return  true when lhs.title > rhs.title. False otherwise.
     */
    bool greaterThan(const shared_ptr<Movie> &lhs, const shared_ptr<Movie> &rhs) noexcept(false) override {
        if (lhs == nullptr || rhs == nullptr)
            throw logic_error("Cant compare NULLPTR");

        return lhs->getTitle() > rhs->getTitle();
    };

    /**
     * @param lhs
     * @param rhs
     * @return  true when lhs.title == rhs.title. False otherwise.
     */
    bool equals(const shared_ptr<Movie> &lhs, const shared_ptr<Movie> &rhs) noexcept(false) override {
        if (lhs == nullptr || rhs == nullptr)
            throw logic_error("Cant compare NULLPTR");

        return lhs->getTitle() == rhs->getTitle();
    };
};


#endif
