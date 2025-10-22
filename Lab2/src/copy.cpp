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
    char* a = (char*)"test";
    char* b;
    copy(b, a);
    bool out = testing::assert_equals(a, b);
    if (out) { passed++; }
}

/**
* Testing that copy respects null terminators.
* Expected Output: b = "hello"
*/
void copy_name_test_case_2(){
    char* a = (char*)"hello\0 world";
    char* b;
    // expect the copied data to equal the string before \0
    bool out = testing::assert_equals((char*)"hello", copy(b, a));
    if (out) { passed++; }
}

/**
* Testing a destination that's smaller than source.
* Expected Output: nullptr
*/
void copy_name_test_case_3(){
    // create a pointer to a smaller chunk of characters and try to copy to it.
    char* a = (char*)"some text";
    char b[2] = "a";
    char& pb = *b;
    char* pout = copy(b, a);
    // if copy returns a nullptr, it successfully stopped copying.
    if (testing::is_nullptr(pout)) { passed++; }
}

int main(){
    testing::setDebug(true);
    std::cout << "Length of word 'hello' is "<< length("hello\0") << std::endl;
    copy_name_test_case_1();
    copy_name_test_case_2();
    copy_name_test_case_3();

    std::cout << passed << "/" << numTests << " tests passed." << std::endl;
}
