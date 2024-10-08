#include <iostream>
#include "swap_header.hpp"

int main()
{
    //Starts with two variables
    int x = 12;
    int y = 7;

    //Prints their values
    std::cout << "\nThe value of x is " << x << "\n";
    std::cout << "The value of y is " << y << "\n\n";

    //Create two pointers to hold them
    int* ptr_x = &x;
    int* ptr_y = &y;

    //Swaps
    std::cout << "Swapping x & y\n\n";
    swap::swap_values(ptr_x, ptr_y);

    //Prints the values again
    std::cout << "The value of x is " << x << "\n";
    std::cout << "The value of y is " << y << "\n\n";
    
    return 0;
}