#include "Programme.h"
#include <sstream>

Programme::Programme() : _name(""), _year(0), modules(nullptr), cap(0), moduleCount(0) {}

// blame the formatter for this mess
Programme::Programme(std::string name, unsigned int year, unsigned int cap)
    : _name(name), _year(year), cap(cap), moduleCount(0) {
    
    // allocate module array and make em all null
    modules = new Module*[cap];
    for (unsigned int i = 0; i < cap; i++) {
        modules[i] = nullptr;
    }
}

Programme::~Programme() {
    if (modules != nullptr) {
        delete[] modules;
    }
}

std::string Programme::getName() const {
    return _name;
}

void Programme::setName(std::string name) {
    _name = name;
}

unsigned int Programme::getYear() const {
    return _year;
}

void Programme::setYear(unsigned int year) {
    _year = year;
}

void Programme::addModule(Module* module) {
    // checks cap first, then adds, then increments.
    if (moduleCount < cap) {
        modules[moduleCount] = module;
        moduleCount++;
    }
}

std::string Programme::toStr() const {
    // thanks to this stackoverflow thingy
    // https://stackoverflow.com/questions/20594520/what-exactly-does-stringstream-do

    std::ostringstream oss;
    oss << "Programme: " << _name << " (Year " << _year << ")" << std::endl;

    // if we got a module, spit out the info
    for (unsigned int i = 0; i < moduleCount; i++) {
        if (modules[i] != nullptr) {
            oss << "  Module: " << modules[i]->getName()
                << ", Credits: " << modules[i]->getCredits()
                << ", Students: " << modules[i]->getStudents() << std::endl;
        }
    }

    return oss.str();
}
