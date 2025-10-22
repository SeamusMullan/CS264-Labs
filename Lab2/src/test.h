#pragma once

#include <iostream>
#include <stdio.h>

namespace testing {
    
    bool debug = false;

    void setDebug(bool val){
        debug = val;
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
