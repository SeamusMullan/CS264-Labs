#pragma once

/**
 * @brief Return the length of a string.
 *
 * Excludes the characters "\0" AND the null terminator
 * eg:
 *
 * Hello   -> 5
 * Hello\0 -> 5
 *
 * @param str char* to the start of a string.
 * @return unsigned int length of the string excluding null terminator.
 */
unsigned int length(const char* str){
    unsigned int len = 0;
    // count along every byte until we reach a null terminator.
    for (const char* p = str; *p != '\0'; p++){
        len++;
    }
    return len;
}
