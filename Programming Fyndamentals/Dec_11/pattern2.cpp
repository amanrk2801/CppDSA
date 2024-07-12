#include <iostream>
int main() {

    int n;
    std::cin>>n; // user input

    // we need to do some task for every row
    for(int row = 1; row <= n; row++) {
        // write the logic to repeat for every row
        for(int num = 1; num <= row; num++) {
            std::cout<<num<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}

/**
 * n = 4
1
1 2 
1 2 3 
1 2 3 4 

*/