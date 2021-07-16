#ifndef INC_2021_SUMMER_CSCI2421_ACTOR_H
#define INC_2021_SUMMER_CSCI2421_ACTOR_H

#include <string>

using namespace std;

class Actor {
private:
    string name;

public:
    explicit Actor();
    explicit Actor(const string& aName);
    virtual ~Actor();

    const string &getName() const;
    void setName(const string &aName);

    friend ostream& operator<<(ostream& out, const Actor& anActor);
};

#include "Actor.cpp"
#endif //INC_2021_SUMMER_CSCI2421_ACTOR_H
