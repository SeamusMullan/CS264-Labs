#include <iostream>

/**
 * @brief Function for calculating x^y in O(Log n)
 *
 * This function returns a float since negative powers can be calculated as 1 / x^y (if y is negative)
 *
 * @param x the base
 * @param y the power
 * @return the output as a float.
 */
float powFun(int x, int y){

    // power of 0 is always 1
    if (y == 0){ return 1; }

    // Negative powers result in division instead, functions same as below.
    if (y < 0){
        if (y == -1){ return x; }
        return 1 / powFun(x, y*-1);

    } else {
        // Calculate the power recursively, decreasing the power each iteration.
        // Results in a O(log n) computation time, where n = y
        if (y == 1){ return x; }
        return x * powFun(x, y-1);
    }
}

int main() {
    int x, y;
    std::cout << "Input number for x: ";
    std::cin >> x;
    std::cout << "Input number for y: ";
    std::cin >> y;

    float out = powFun(x, y);
    // return a floating point output for values under 0
    // these are caused by negative powers, resulting in fractions / decimal answers
    std::cout << "Output equals: " << out << std::endl;
    return 0;
}
