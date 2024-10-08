#include <iostream>
#include <string>
#include <iomanip>
#include "grade.hpp"

int main()
{   
    const int SIZE = 10;
    int scores[SIZE] = {87, 69, 65, 74, 95, 83, 92, 97, 68, 100};
    std::string names[SIZE] = {"Alex", "Bob", "Charlie", "David", "Evan", "Fred", "Greg", "Harold", "Isaac", "Jack"};
    
    std::cout << grade::get_highest_number(scores, SIZE);
    return 0;
}
