#pragma once

#include <iostream>
#include <stdio.h>

namespace testing {
    
    bool debug = false;

    void setDebug(bool val){
        debug = val;
    }

    char* dummy_string(unsigned int n){
        char* out = new char[n+1];
        for (int i=0; i<n; i++){out[i] = 'x';}
        out[n] = '\0';
        return out;
    }

     /**
     *
     * @tparam T This allows us to use any type in the function
     * @param a var1
     * @param b var2
     * @return true/false if a==b
     */
    template <typename T>
    bool assert_equals(T const & a, T const & b) {
        if (debug){
            std::cout << "Input for a: " << a << std::endl;
            std::cout << "Input for b: " << b << std::endl;
        }
        return a == b;
    }

    /**
     * @brief Compare the values of the text in two character pointers.
     *
     * @param a first character pointer
     * @param b second character pointer
     * @return true/false if contents of strings are identical.
     */
    template <>
    inline bool assert_equals<const char*>(const char* const & a, const char* const & b) {
        if (debug) {
            std::cout << "Input for a: " << (a ? a : "null") << std::endl;
            std::cout << "Input for b: " << (b ? b : "null") << std::endl;
        }
        if (a == nullptr || b == nullptr) return a == b;  // both null?
        return std::string(a) == std::string(b);
    }

    /**
     * @brief Check if a pointer is a nullptr
     *
     * @tparam T allows use of any type
     * @param a the pointer we wish to check
     * @return true/false if a==nullptr
     */
    template <typename T>
    bool is_nullptr(T const & a){
        if (debug) {std::cout << "Input for a: " << a << std::endl;}
        return (a == nullptr);
    }


    template <typename T>
    bool is_null(T const a){
        bool isNull = (a == NULL);
        if (debug) {std::cout << "Input for a: " << ((isNull) ? "NULL" : a) << std::endl;}
        return (isNull);
    }

    /**
     *
     * @tparam T This allows us to use any type in the function
     * @param a var1
     * @param b var2
     * @return true/false if a==b
     */
    template <typename T>
    inline bool assert_not_equal(T const & a, T const & b) {
        if (debug){
            std::cout << "Input for a: " << a << std::endl;
            std::cout << "Input for b: " << b << std::endl;
        }
        return a != b;
    }

}
