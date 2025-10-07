#include <iostream>

/**
    This method calculates the Greatest Common Divisor (GCD) of a pair of numbers

    The GCD is calculated by the 'Euclidian Algorithm' which basically does the following;

    - We can recursively shrink the second number, in this case b and then swap the inputs.
    - when b is 0, we have found the gcd and can return it (will be in the a section)

    This also works for negative numbers, see https://proofwiki.org/wiki/GCD_for_Negative_Integers
    for proofs that gcd(a,b) = gcd(a,|b|) and other variations.
 
*/
int GCD(int a, int b){
    // abs value of numbers to ensure negatives dont break things.
    if (a<0) {a*=-1;}
    if (b<0) {b*=-1;}

    int out = -1;

    // if we have a 0 input, the gcd is going to be the other input.
    if (b == 0){
        return a;
    } else {
        // If we actually have two numbers, 
        // recursively shrink the second input using modulus
        out = GCD(b, a%b);
    }

    return out;
}

int main() {
    // Test the function with some example values
    std::cout << GCD(12, 24) << std::endl; // 12
    std::cout << GCD(1, 2) << std::endl; // 1
    std::cout << GCD(-3, 9) << std::endl; // -3 
    std::cout << GCD(8, 13) << std::endl; // 1
    std::cout << GCD(256, 2) << std::endl; // 2
    std::cout << GCD(2, 256) << std::endl; // 2
}
