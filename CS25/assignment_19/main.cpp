#include <iostream>
#include "swap_header.hpp"

int main()
{
    int x = 2;
    int y = 7;

    int* ptr_x = &x;
    int* ptr_y = &y;

    std::cout << "\nThe value of x is " << x << "\n";
    std::cout << "The value of y is " << y << "\n\n";
    std::cout << "Swapping x & y\n\n";

    swap::swap_values(ptr_x, ptr_y);

    std::cout << "The value of x is " << x << "\n";
    std::cout << "The value of y is " << y << "\n\n";
    
    return 0;
}