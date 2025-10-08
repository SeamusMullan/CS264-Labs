#include <iostream>

/**
 * @brief This function reverses an integer and returns the value of the reversed number.
 *
 * The function returns the actual value of the reversed number. Numbers ending in 0 will end up
 * having a different value to the reversed string of digits.
 *
 * An example would be the number -120
 * which would be written "-021" if the digits were reversed
 * but would actually be equal to -21
 *
 * The function prints the reversed number with 0's on the left side to the console.
 *
 * @param in The number to reverse
 * @return The value of the reversed number.
 */
int revInt(int in){

    int out = 0;
    
    // if number is negative, convert to positive and manually add minus sign.
    bool pos = (in >= 0);
    if (!pos) {
        in *= -1;
        // write a minus sign so numbers ending in 0 get printed right.
        std::cout << "-";
    }

    // recursively get the first number (rightmost), add to out and do out*10.
    // use mod 10 and divide to move numbers across from input
    while (in>0){
        int temp = in % 10; // number on right
        out *= 10;
        out += temp; // put in temp
        std::cout << temp;
        in /= 10; // move input right
    }

    std::cout << "" << std::endl;

    // we now have a reversed integer, carry over sign from input and return
    if (!pos){ out *= -1; }

    // this output is the actual negative number with no 0 padding on the left.
    return out;
}

int main() {
    

    int input;
    std::cout << "Input a number to reverse: ";
    std::cin >> input;
    std::cout << "Reversed Number: ";
    int x = revInt(input);
    std::cout << "Actual Value: " << x << std::endl;

    // run the function for multiple numbers to test the outputs
    /*
    revInt(12345);
    revInt(54321);
    revInt(-123);
    revInt(-420);
    revInt(1337);
    revInt(10105);
    */
}

