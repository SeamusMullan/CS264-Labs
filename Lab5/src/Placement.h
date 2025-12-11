#ifndef PLACEMENT_H
#define PLACEMENT_H

#include "Module.h"
#include <string>

// placement is the module where you pay for your degree, usually...
class Placement : public Module {
private:

    std::string _description;

public:

    Placement();
    Placement(std::string name, std::string description, unsigned int students = 0);

    std::string getDescription() const;
    void setDescription(std::string description);
};

#endif
