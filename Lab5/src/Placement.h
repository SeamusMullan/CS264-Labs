#ifndef PLACEMENT_H
#define PLACEMENT_H

#include "Module.h"
#include <string>

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
