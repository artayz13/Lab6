#include "Actor.h"

Actor::Actor(): Actor("") {}
Actor::Actor(const string& aName): name(aName) {}
Actor::~Actor() = default;

const string &Actor::getName() const {
    return name;
}

void Actor::setName(const string &aName) {
    Actor::name = aName;
}

ostream& operator<<(ostream& out, const Actor& anActor){
    out << "   - "<< anActor.getName();
    return out;
}
