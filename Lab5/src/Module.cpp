#include "Module.h"

Module::Module() : _name(""), _students(0), _credits(2) {
    // do nothing and use defaults
}

Module::Module(std::string name, unsigned int credits, unsigned int students) : _name(name), _students(students), _credits(credits) {
        // use provided vals
    }


// something something, good code comments itself.

std::string Module::getName() const {
    return _name;
}

void Module::setName(std::string name) {
    _name = name;
}

unsigned int Module::getStudents() const {
    return _students;
}

void Module::setStudents(unsigned int students) {
    _students = students;
}

unsigned int Module::getCredits() const {
    return _credits;
}

void Module::setCredits(unsigned int credits) {
    _credits = credits;
}

bool Module::operator==(const Module& someModule) const {
    return (_name == someModule._name) && (_credits == someModule._credits);
}
