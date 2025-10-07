#include <iostream>

// convert the number to a string, then use 2 pointers to verify if both halfs are identical
// if not, we dont have a palindrome number

bool palNum( int num ){
    // convert number to a string so we can index it.
    std::string str = std::to_string(num);

    // iterate over chars in the string, if every index is the same as the mirrored index
    // we can return true, since we have a palindrome
    for (int i=0; i<str.size()-1; i++){
       if (str[i] != str[str.size()-1-i]){ return false; } 
    }

    return true;

}

int main() {
    int in;

    std::cout << "Input Number: ";
    std::cin >> in;

    if (palNum(in)){
        std::cout << "Is a palindrome" << std::endl;
    } else {
        std::cout << "Isn't a palindrome" << std::endl;
    }

    return 0;
}


