#include <iostream>
#include <stdlib.h>
#include "test.h"
#include "length.h"

unsigned int numTests = 5;
unsigned int passed = 0;

/**
 * Test 1: Testing an empty String
 * Expected Output: 11
 */
void length_name_test_case_1() {
    const unsigned int a = length("hello world");
    const unsigned int b = 11;
    bool out = testing::assert_equals(a, b);
    if (out) { passed++; }
}

/**
 * Test 2: Testing a string with a manual null terminator.
 * Expected Output: 0
 */
void length_name_test_case_2() {
    unsigned int a = length("\0");
    unsigned int b = 0;
    bool out = testing::assert_equals(a, b);
    if (out) { passed++; }
}

/**
 * Test 3: Testing a string with \0 in the middle
 * Expected Output: 5
 */
void length_name_test_case_3() {
    unsigned int a = length("hello\0world");
    unsigned int b = 5;
    bool out = testing::assert_equals(a, b);
    if (out) { passed++; }
}

/**
 * Test 4: Testing a string with non-ASCII characters (Unicode)
 * Expected Output: 2
 *
 * since unicode characters are two bytes, the length function will read the
 * character delta as 2 characters, since char is a single byte by default
 */
void length_name_test_case_4() {
    unsigned int a = length("Δ"); // greek letter delta
    unsigned int b = 2;
    bool out = testing::assert_equals(a, b);
    if (out) { passed++; }
}

/**
 * Test 5: Testing a string with ASCII and non-ASCII characters
 * Expected Output: 9
 *
 * See test 4 for explanation about unicode character lengths
 */
void length_name_test_case_5() {
    unsigned int a = length("Delta: Δ");
    unsigned int b = 9;
    bool out = testing::assert_equals(a, b);
    if (out) { passed++; }
}

int main(){
    testing::setDebug(true);
    std::cout << length("hello\0") << std::endl;
    length_name_test_case_1();
    length_name_test_case_2();
    length_name_test_case_3();
    length_name_test_case_4();
    length_name_test_case_5();

    std::cout << passed << "/5 tests passed." << std::endl;
}
