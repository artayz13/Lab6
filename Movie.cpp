
#include "iostream"
/**********************************************************************************************************************/
Movie::Movie() : Movie("", 0) {}

/**********************************************************************************************************************/
Movie::Movie(const string &aTitle, int year): title(aTitle), releaseYear(year), actors(LinkedBag<shared_ptr<Actor>>()) {}

/**********************************************************************************************************************/
Movie::~Movie() {
    vector<shared_ptr<Actor>> vecActors = this->actors.toVector();

    for (const shared_ptr<Actor>& anActor: vecActors){
        this->actors.remove(anActor);
    }
}

/**********************************************************************************************************************/
string Movie::getTitle() const {
    return this->title;
}

/**********************************************************************************************************************/
void Movie::setTitle(const string &aTitle) {
    this->title = aTitle;
}

/**********************************************************************************************************************/
int Movie::getReleaseYear() const {
    return releaseYear;
}

/**********************************************************************************************************************/
void Movie::setReleaseYear(int year) {
    this->releaseYear = year;
}

/**********************************************************************************************************************/
ostream& operator<<(ostream& out, const Movie& aMovie) {
    out << ">>"
        << aMovie.getTitle() << "--"
        << aMovie.getReleaseYear() << "<<" <<endl;

    for (const shared_ptr<Actor>& anActor: aMovie.getActors())
        out << *anActor <<endl;

    return out;
}

/**********************************************************************************************************************/
bool Movie::addActor(const shared_ptr<Actor>& anActor) {
    if (this->actors.contains(anActor))
        return false;
    else{
        return this->actors.add(anActor);
    }
}

/**********************************************************************************************************************/
bool Movie::removeActor(const shared_ptr<Actor> &anActor) {
    return this->actors.remove(anActor);
}

/**********************************************************************************************************************/
vector<shared_ptr<Actor>> Movie::getActors() const {
    return this->actors.toVector();
}
