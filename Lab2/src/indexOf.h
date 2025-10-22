#include <iostream>
#include "length.h"

/**
 * @brief Finds the index of the first occurance of a character in a string
 *
 * @param c The character to search for
 * @param str The string to search.
 * @return The index of the first occurance of the char, or -1 if it doesn't occur.
 */
int indexOf(char c, const char* str) {
    // note to account for null terminator in the string length.
    // This means an empty string won't cause the function to read memory that it shouldn't
    for (int i=0; i<length(str)+1; i++){
        if(str[i]==c) {return i;}
    }
    return -1;
}
