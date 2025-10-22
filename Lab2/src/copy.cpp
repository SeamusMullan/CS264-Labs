#include <iostream>
#include <stdlib.h>
#include "test.h"
#include "length.h"
#include "copy.h"

unsigned int numTests = 5;
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
    bool out = testing::assert_equals((char*)"hello", copy(b, a));
    if (out) { passed++; }
}

/**
* Testing a destination that's smaller than source.
* Expected Output: nullptr
*/
void copy_name_test_case_3(){
    char* a = (char*)"some text";
    char b[] = "a";
    char& pb = *b;
    bool out = testing::assert_equals(copy(&pb,a), (char*)nullptr);
    if (out) { passed++; }
}

int main(){
    testing::setDebug(true);
    std::cout << length("hello\0") << std::endl;
    copy_name_test_case_1();
    copy_name_test_case_2();
    copy_name_test_case_3();

    std::cout << passed << "/5 tests passed." << std::endl;
}
