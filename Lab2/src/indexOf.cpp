#include <iostream>
#include "length.h"
#include "test.h"
#include "indexOf.h"

unsigned int numTests = 3;
unsigned int passed = 0;

/**
* Testing a basic example.
* Expected Output: index = 3
*/
void indexOf_name_test_case_1() {
    const char* a = (char*)"hello";
    int b = indexOf('l', a);
}

/**
* Testing when char doesnt exist
* Expected Output: index = 3
*/
void indexOf_name_test_case_2() {
    const char* a = (char*)"heya";
    int b = indexOf('l', a);
}


/**
* Testing a basic example.
* Expected Output: index = 3
*/
void indexOf_name_test_case_3() {
    const char* a = (char*)"hello";
    int b = indexOf('l', a);
}


int main() {
}
