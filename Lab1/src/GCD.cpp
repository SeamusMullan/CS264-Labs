#include <iostream>

/**
 * @brief Calculates the Greatest Common Divisor (AKA Highest Common Factor) for a and b
 * 
 * This function accounts for negative numbers and uses the following proof as a reference.
 *
 * The GCD is calculated by the 'Euclidian Algorithm' which basically does the following;
 *
 * - We can recursively shrink the second number, in this case b and then swap the inputs.
 * - when b is 0, we have found the gcd and can return it (will be in the a section)
 * 
 * https://proofwiki.org/wiki/GCD_for_Negative_Integers shows gcd(x,y) = gcd(|x|,y) or vice versa.
 *
 * @param a first number
 * @param b second number
 * @return GCD of the two numbers
 */
int GCD(int a, int b){
    // abs value of numbers to ensure negatives dont break things.
    // this doesnt change output, see attached proof.
    if (a<0) {a*=-1;}
    if (b<0) {b*=-1;}

    int out = -1;

    // if we have a 0 input, the gcd is going to be the other input.
    if (b == 0){
        return a;
    } else {
        // If we actually have two numbers, 
        // recursively shrink the second input using modulus until we have 0 in one of the inputs.
        out = GCD(b, a%b);
    }

    return out;
}

int main() {
    int x,y;

    std::cout << "Input First Number: ";
    std::cin >> x;

    std::cout << "Input Second Number: ";
    std::cin >> y;

    std::cout << "GCD is " << GCD(x,y) << std::endl;

}
