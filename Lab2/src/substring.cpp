#include <iostream>
#include "substring.h"
#include "test.h"

unsigned int numTests = 5;
unsigned int passed = 0;

/**
* Testing a basic substring for the first half of the word.
* Expected Output: te
*/
void substring_name_test_case_1(){
    const char* a = "test";
    bool out = testing::assert_equals((const char*)"te", (const char*)substring(0,2,a));
    if (out) { passed++; }
}


/**
* Testing a basic substring for the end of the word.
* Expected Output: ing
*/
void substring_name_test_case_2(){
    const char* a = "testing";
    bool out = testing::assert_equals((const char*)"ing", (const char*)substring(4,7,a));
    if (out) { passed++; }
}

/**
* Testing a basic substring for the middle of the word.
* Expected Output: llo wo 
*/
void substring_name_test_case_3(){
    const char* a = "hello world";
    bool out = testing::assert_equals((const char*)"llo wo", (const char*)substring(2,8,a));
    if (out) { passed++; }
}

/**
* Testing invalid start position.
* Expected Output: NULL
*/
void substring_name_test_case_4(){
    const char* a = "hello world";
    bool out = testing::is_null((const char*)substring(-1,8,a));
    if (out) { passed++; }
}

/**
* Testing invalid end position.
* Expected Output: NULL
*/
void substring_name_test_case_5(){
    const char* a = "hello world";
    bool out = testing::is_null((const char*)substring(2,800,a));
    if (out) { passed++; }
}

int main() {
    testing::setDebug(true);
    substring_name_test_case_1();
    substring_name_test_case_2();
    substring_name_test_case_3();
    substring_name_test_case_4();
    substring_name_test_case_5();

    std::cout << passed << "/" << numTests << " tests passed." << std::endl;
}
