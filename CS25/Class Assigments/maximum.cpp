#include <iostream>

int return_maximum(int first_value, int second_value)
{
    if(first_value > second_value)
    {
        return first_value;
    }
    return second_value;
}

int main()
{
    int x = 3;
    int y = 12;
    std::cout << return_maximum(3, 12) << "\n";
    return 0;
}