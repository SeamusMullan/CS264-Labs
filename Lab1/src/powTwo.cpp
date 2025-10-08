#include <iostream>

/**
 * @brief This function checks if a number is a power of two.
 *
 * Powers of two are always represented as one bit in binary.
 * eg: 00001000 (base 2) = 8 (base 10)
 * 
 * so we can check if the number & the inverse of the number -1 is true
 * eg:
 * 
 * 1000 -> number
 * 0111 -> number - 1
 * 1000 -> inverse of number - 1
 * 
 * 1000 & 1000 = true, 8 is a power of 2
 *
 *
 * @param x The input number to check
 * @return A boolean value if the number is a power of two.
 */
bool powTwo(int x){
    return x && !(x & (x - 1));
}

int main() {
    int x;
    std::cout << "Input number for x: ";
    std::cin >> x;
    
    if (powTwo(x)){
        std::cout << x << " is a power of two." << std::endl;
    } else {
        std::cout << x << " is not a power of two." << std::endl;
    }

    return 0;
}
