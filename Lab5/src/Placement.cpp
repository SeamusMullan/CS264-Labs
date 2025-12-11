#include "Placement.h"

Placement::Placement() : Module("", 15, 0), _description("") {
    // default thing. its a module but with hella credits
}

Placement::Placement(std::string name, std::string description, unsigned int students) : Module(name, 15, students), _description(description) {
        // similar to above, allow input but  ALWAYS use 15 credits
    }

std::string Placement::getDescription() const {
    return _description;
}

void Placement::setDescription(std::string description) {
    _description = description;
}
