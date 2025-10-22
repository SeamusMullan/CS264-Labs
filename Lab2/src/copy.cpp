#include <iostream>
#include <stdlib.h>
#include "test.h"
#include "length.h"
#include "copy.h"

unsigned int numTests = 3;
unsigned int passed = 0;

/**
* Testing that copy moves the exact string from a to b.
* Expected Output: a == b
*/
void copy_name_test_case_1(){
    const char* a = "test";
    char* b = testing::dummy_string(100); // ensure we have somewhere to copy to
    copy(b, a);
    bool out = testing::assert_equals((const char*)a, (const char*)b);
    if (out) { passed++; }
    delete[] b; // free allocated memory
}

/**
* Testing that copy respects null terminators.
* Expected Output: b = "hello"
*/
void copy_name_test_case_2(){
    char* a = (char*)"hello\0 world";
    char* b = testing::dummy_string(100);
    // expect the copied data to equal the string before \0
    bool out = testing::assert_equals((const char*)"hello", (const char*)copy(b, a));
    if (out) { passed++; }
    delete[] b; // free allocated memory
}

/**
* Testing a destination that's smaller than source.
* Expected Output: NULL
*/
void copy_name_test_case_3(){
    // create a pointer to a smaller chunk of characters and try to copy to it.
    char* a = (char*)"some text";
    char* b = testing::dummy_string(1);
    char* pout = copy(b, a);
    // if copy returns NULL, it successfully stopped copying.
    if (testing::is_null(pout)) { passed++; }
    delete[] b; // free allocated memory
}

int main(){
    testing::setDebug(true);
    copy_name_test_case_1();
    copy_name_test_case_2();
    copy_name_test_case_3();

    std::cout << passed << "/" << numTests << " tests passed." << std::endl;
}
