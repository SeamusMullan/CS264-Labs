#include <iostream>
#include <stdlib.h>
#include "test.h"
#include "length.h"

char* copy(char* dest, const char* src){
    // get length of source material to copy
    unsigned int len = length(src);

    for (unsigned int i=0; i<len; i++){
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}

unsigned int numTests = 5;
unsigned int passed = 0;

/**
*
*/
void copy_name_test_case_1(){

}

/**
*
*/
void copy_name_test_case_2(){

}

/**
*
*/
void copy_name_test_case_3(){

}

/**
*
*/
void copy_name_test_case_4(){

}

/**
*
*/
void copy_name_test_case_5(){

}


int main(){
    testing::setDebug(true);
    std::cout << length("hello\0") << std::endl;
    copy_name_test_case_1();
    copy_name_test_case_2();
    copy_name_test_case_3();
    copy_name_test_case_4();
    copy_name_test_case_5();

    std::cout << passed << "/5 tests passed." << std::endl;
}


