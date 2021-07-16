
#include "iostream"
#include "string"
#include "regex"

/**********************************************************************************************************************/
#include "LinkedBag.h"

StreamingService::StreamingService(): movies(make_unique<LinkedBag<shared_ptr<Movie>>>()),
                                      actors(make_unique<LinkedBag<shared_ptr<Actor>>>()){

    shared_ptr<Comparator<shared_ptr<Movie>>> aMovieComparator = make_shared<MovieComparator>();
    moviesIndex = make_unique<BinarySearchTree<shared_ptr<Movie>>>(aMovieComparator);
}
/**********************************************************************************************************************/
StreamingService::~StreamingService() {
    vector<shared_ptr<Movie>> vecMovies = movies->toVector();
    vector<shared_ptr<Actor>> vecActors = actors->toVector();

    for (const shared_ptr<Movie>& aMovie: vecMovies){
        movies->remove(aMovie);
    }
    for (const shared_ptr<Actor>& anActor: vecActors){
        actors->remove(anActor);
    }
}

/**********************************************************************************************************************/
bool StreamingService::addMovie(const string& title, int year){

    /**
     * TODO #8: addMovie
     * When adding a movie, you add to the bag and if successfull you add to the Tree.
     */

    bool added ;
    shared_ptr<Movie> aMovie = make_shared<Movie>(title, year);
    /**
     * YOUR CODE HERE.
     */
    added = movies->add(aMovie);
    if(added)
        moviesIndex->add(aMovie);

    return added;
}

/**********************************************************************************************************************/
bool StreamingService::addActor(const string& name){
    shared_ptr<Actor> anActor = make_shared<Actor>(name);
    return this->actors->add(anActor);
}

/**********************************************************************************************************************/
bool StreamingService::addActorToMovie(const string& title, const string& actorName){
    shared_ptr<Movie> aMovie;
    shared_ptr<Actor> anActor;
    aMovie = searchMovieExact(title);
    anActor = searchActor(actorName);
    if (aMovie != nullptr && anActor != nullptr)
        return aMovie->addActor(anActor);
    else
        return false;
}

/**********************************************************************************************************************/
bool StreamingService::isMovieAvailable(const string& title){
    return (searchMovieExact(title) != nullptr);
}

/**********************************************************************************************************************/
shared_ptr<Movie> StreamingService::searchMovieExact(const string& title){
    for (const shared_ptr<Movie>& aMovie:this->movies->toVector())
        if (aMovie->getTitle() == title)
            return aMovie;
    return nullptr;
}

/**********************************************************************************************************************/
vector<shared_ptr<Movie>> StreamingService::searchMoviePattern(const string& titlePattern){
    /**
     * TODO #9: searchMoviePattern
     *
     * Returns a vector of pointers to movies.
     *
     * Using the regular expression module, search for all the movies that contain the titlePattern in their titles.
     * This should be case-insensitive.
     * Hint: the pattern ".*HELLO.*" searches for the word HELLO in the string. any chain of characters can exist before
     *       or after the word.
     * To transform a string variable aString to uppercase you can use:
     *      transform(aString.begin(), aString.end(), aString.begin(), ::toupper);
     *
     * Check out regex and regex_match:  https://en.cppreference.com/w/cpp/regex/regex_match
     *
     */

    vector<shared_ptr<Movie>> foundMovies;
    string titleUpper;
    transform(titlePattern.begin(), titlePattern.end(), ::back_inserter(titleUpper), ::toupper); /** Making searchString toupper*/
    titleUpper = ".*" + titleUpper + ".*";
    regex check(titleUpper); /** Changing to regex type */
    for (const shared_ptr<Movie>& aMovie:this->movies->toVector()){
        string temp = aMovie->getTitle(); /** Current movie title */
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (regex_match(temp, check)){ /** Checking if the target string*/
            foundMovies.push_back(aMovie);
        }

    }


    /**
     * YOUR CODE HERE
     */
    return foundMovies;
}

/**********************************************************************************************************************/
shared_ptr<Actor> StreamingService::searchActor(const string& actorName){
    for (const shared_ptr<Actor>& anActor: this->actors->toVector())
        if (anActor->getName() == actorName)
            return anActor;
    return nullptr;
}


/**********************************************************************************************************************/
std::ostream& operator<<(std::ostream& out, const StreamingService& service) {
    out << std::endl;
    out << "Movies in the Streaming Service: " << std::endl;
    for(const shared_ptr<Movie>& aMovie : service.movies->toVector())
        out<< *aMovie << std::endl;
    out<< "--------------------------------------------"<<std::endl;

    return out;
}



/*********************************************************************************************************************/
void StreamingService::visitMoviesSorted(void visit(shared_ptr<Movie> &)) const {
    this->moviesIndex->inorderTraverse(visit);
}
