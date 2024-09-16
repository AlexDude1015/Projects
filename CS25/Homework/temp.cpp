#include <iostream>
using namespace std;

int main()
{
    int input_quantity;
    cout << "How many inputs will you enter?";
    cin >> input_quantity;
    double total_temp = 0;
    double placeholder_value = 1;
    cout << endl << "Please enter the temperatures: ";
    for (int i = 1; i <= input_quantity; i++)
    {
        cin >> placeholder_value;
        total_temp += placeholder_value;
    }   
    cout << total_temp / input_quantity;
    return 0;
}
