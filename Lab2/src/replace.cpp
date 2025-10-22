#include <iostream>
#include "replace.h"
#include "test.h"

unsigned int numTests = 2;
unsigned int passed = 0;

/**
* Testing a basic example from pdf.
* Expected Output: say
*/
void replace_name_test_case_1(){
    const char* in = "string";
    bool out = testing::assert_equals((const char*)"strxng", (const char*)replace('i', 'x', in));
    if (out) {passed++;}
}

/**
* Testing another basic example where c doesn't occur.
* Expected Output: hello
*/
void replace_name_test_case_2(){
    const char* in = "hello";
    bool out = testing::assert_equals((const char*)"hello", (const char*)replace('i', 'j', in));
    if (out) {passed++;}
}

int main() {
    testing::setDebug(true);
    replace_name_test_case_1();
    replace_name_test_case_2();

    std::cout << passed << "/" << numTests << " tests passed." << std::endl;

}
