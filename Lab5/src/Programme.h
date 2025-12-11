#ifndef PROGRAMME_H
#define PROGRAMME_H

#include "Module.h"
#include <string>

class Programme {
public:
    // same as other classes basically...
    Programme();
    Programme(std::string name, unsigned int year, unsigned int capacity);

    ~Programme(); // we need this since we be allocatin things

    std::string getName() const;
    void setName(std::string name);

    unsigned int getYear() const;
    void setYear(unsigned int year);

    void addModule(Module* module);
    std::string toStr() const;

private:

    std::string _name;
    unsigned int _year;
    Module** modules; // not technically in UML but we need it... unless theres some crazy way not to use it that idk
    unsigned int cap;
    unsigned int moduleCount;

};

#endif
