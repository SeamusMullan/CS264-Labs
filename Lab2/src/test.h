#pragma once
namespace testing {
    /**
     *
     * @tparam T This allows us to use any type in the function
     * @param a var1
     * @param b var2
     * @return true/false if a==b
     */
    template <typename T>
    bool assert_equals(T const & a, T const & b) {
        return a == b;
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
        return a != b;
    }

}
