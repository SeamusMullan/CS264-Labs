#include <iostream>
#include "test.h"
#include "indexOf.h"

unsigned int numTests = 2;
unsigned int passed = 0;

/**
* Testing a basic example.
* Expected Output: index = 2
*/
void indexOf_name_test_case_1() {
    const char* a = (char*)"hello";
    int b = indexOf('l', a);
    bool out = testing::assert_equals(2, b);
    if (out) {passed++;}
}

/**
* Testing when char doesnt exist
* Expected Output: index = -1
*/
void indexOf_name_test_case_2() {
    const char* a = (char*)"heya";
    int b = indexOf('l', a);
    bool out = testing::assert_equals(-1, b);
    if (out) {passed++;}
}

int main() {
    testing::setDebug(true);
    indexOf_name_test_case_1();
    indexOf_name_test_case_2();

    std::cout << passed << "/" << numTests << " tests passed." << std::endl;
}
