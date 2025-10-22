#pragma once
#include "length.h"

/**
 * @brief Copies a value from a source pointer to a destination
 *
 * @param dest destination for copied data
 * @param src source of copied data
 * @return char* pointer to the newly copied data
 */
char* copy(char* dest, const char* src) {
    // get len of destination, if less than source, we can't copy so return null
    // add 1 to account for the null terminator not counted in length()
    int d=length((const char*)dest)+1;
    int s=length(src)+1;

    if(d<s)
        return NULL;

    // overwrite every character in the destination.
    // if we have already copied all the source, fill with null terminators
    // this stops random data being left in dest.
    for(int i=0; i<s; i++) {
        if(i<d) {
            dest[i]=src[i];
        } else {
            dest[i]='\0';
        }
    }

    return dest;
}
