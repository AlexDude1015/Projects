#include <iostream>

int main()
{
    int row_number;
    std::cout << "Please enter the number of rows: " << std::endl;
    std::cin >> row_number;
    for (int i = 0; i < row_number; i++ )
    {
        for (int j = 0; j < i + 1; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}