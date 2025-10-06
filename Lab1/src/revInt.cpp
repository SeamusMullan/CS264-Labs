#include <iostream>


/**

  This function takes an input integer and reverses the numbers in the integer.
  Numbers will be outputted to standard output in this file, but the function itself returns the true negative value without padding

  Example input: 12345
  Example output: 54321

  For numbers ending in 0, the stdout contains a leftpadded 0, the function does not (since it returns integer).
  Example input: -420
  Example stdout output: -024
  Example function output: -24

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
    
    // run the function for multiple numbers to test the outputs

    revInt(12345);
    revInt(54321);
    revInt(-123);
    revInt(-420);
    revInt(1337);
    revInt(10105);
}

