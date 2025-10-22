#include <iostream>
#include "length.h"

/**
 * @brief A function to replace a character with another inside a string.
 *
 * @param c The original character to search for.
 * @param p The character to replace it with.
 * @param str The string to modify.
 * @return A pointer to the modified string.
 */
char* replace (char c, char p, const char* str){
    int len = length(str);  
    char* out = new char[len]; // make a new string for the output

    // for every character, replace c with p, or keep the same
    for (int i=0;i<len;i++){
        out[i] = (str[i] == c) ? p : str[i];
    }

    out[len] = '\0';
    return out;
}
