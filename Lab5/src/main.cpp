#include "Module.h"
#include "Placement.h"
#include "Programme.h"
#include <iostream>

int main() {
    // make modules n programme
    Module cs264("CS264", 5, 181);
    Module cs357("CS357", 5, 155);
    Programme csse("CSSE", 3, 10);

    csse.addModule(&cs264);
    csse.addModule(&cs357);

    // print csse
    std::cout << csse.toStr() << std::endl;

    // test the override
    Module testModule1("CS264", 5, 100);
    Module testModule2("CS264", 5, 200);
    Module testModule3("CS264", 3, 100);

    if (cs264 == testModule1) {
        std::cout << "cs264 and testModule1 are identical (same name and credits)" << std::endl;
    }

    if (cs264 == testModule2) {
        std::cout << "cs264 and testModule2 are identical (same name and credits)" << std::endl;
    }

    if (!(cs264 == testModule3)) {
        std::cout << "cs264 and testModule3 are NOT identical (different credits)" << std::endl;
    }

    // for funzies, get a placement (difficulty: hard)
    Placement placement("Industrial Placement", "12-month industry placement", 42);
    std::cout << "\nPlacement Module: " << placement.getName()
              << ", Credits: " << placement.getCredits()
              << ", Students: " << placement.getStudents()
              << ", Description: " << placement.getDescription() << std::endl;

    return 0;
}
