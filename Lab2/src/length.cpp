#include <iostream>
#include "test.h"

unsigned int length(const char* str){
    unsigned int len = 0;
    for (const char* p = str; *p != '\0'; p++){
        len++;
    }
    return len;
}


/**
 * Test 1: Testing an empty String
 */
void length_name_test_case_1() {
    const unsigned int a = length("hello world");
    const unsigned int b = 0;
    bool out = testing::assert_equals(a, b);
}

/**
 * Test 2: Testing a string with a huge length
 */
void length_name_test_case_2() {
    // generate a string of random characters
    const unsigned int b = 8192;


}

/**
 * Test 3: Testing a string with \0 in the middle
 */
void length_name_test_case_3() {
    unsigned int a = length("hello\0world");
    unsigned int b = 5;
    bool out = testing::assert_equals(a, b);

}

/**
 * Test 4: Testing a string with non-ASCII characters (Unicode)
 */
void length_name_test_case_4() {

}

/**
 * Test 5: Testing a string with ASCII and non-ASCII characters
 */
void length_name_test_case_5() {

}

int main(){
    std::cout << length("hello\0") << std::endl;

}


