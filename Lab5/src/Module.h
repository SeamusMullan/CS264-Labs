#ifndef MODULE_H
#define MODULE_H

#include <string>

class Module {
public:
    // empty constrcutr (input of actual vars later)
    Module();

    // default 2 creds and 0 students, but allow specific ones
    Module(std::string name, unsigned int credits = 2, unsigned int students = 0);

    std::string getName() const;
    void setName(std::string name);

    unsigned int getStudents() const;
    void setStudents(unsigned int students);

    unsigned int getCredits() const;
    void setCredits(unsigned int credits);

    bool operator==(const Module& someModule) const;


private:
    std::string _name;
    unsigned int _students;
    unsigned int _credits;

};

#endif
