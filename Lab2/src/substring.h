#include <iostream>
#include "copy.h"
#include "length.h"

/**
 * @brief A function to return a substring of an input.
 *
 * The function validates the values i and j before creating the substring.
 * the values i and j must lie inside the range of the original string.
 *
 * @param i starting index.
 * @param j ending index.
 * @param str string to obtain substring from.
 * @return a pointer to the newly created substring.
 */
char* substring(int i, int j, const char* str) {
    if (i >= j || i < 0 || j < 0 || j > length(str)) return NULL;

    int len = j - i;
    char* result = new char[len + 1];

    for (int x = 0; x < len; x++) {
        result[x] = str[i + x];  // copy offset by i
    }

    result[len] = '\0';
    return result;
}

