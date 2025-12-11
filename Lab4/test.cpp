#include <iostream>



char* str_rev(const char* str){
    // iterate thru str to get size
    int n = 0;
    while (str[n]){
        n++;
    }
    //std::cout << n << std::endl;
    char* cpy = new char[n+1];

    for (int i=n-1; i>-1; i--){
        cpy[n-1-i] = str[i];
        //std::cout << i << "=" << str[i] << std::endl;
    }

    return cpy;
}

char* merge(const char* str){
    int n=0;
    while (str[n]){n++;}

    char* rev = str_rev(str);
    char* out = new char[2*n +1];

    for (int i=0; i<2*n; i++){
        out[i] = (i>n-1) ? rev[i-n] : str[i];
    }

    return out;
}


int main() {

    char* x = str_rev("hello");
    
    std::cout << "hello -> ";

    int a = 0;
    while (x[a]){
        std::cout << x[a];
        a++;
    }
    std::cout << std::endl;

    delete x;


    std::cout << "cat -> ";

    char* dble = merge("cat");
    a=0;
    while (dble[a]){
        std::cout << dble[a];
        a++;
    }
    std::cout << std::endl;
    delete dble;

    return 0;
}
