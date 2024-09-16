#include <iostream>
using namespace std;

int main()
{   
    //Asks user for a specific quantity of inputs
    int input_quantity;
    cout << "How many inputs will you enter: ";
    cin >> input_quantity;

    //Stores the sums of all inputs
    double total_temp = 0;

    //Calculates the sum of every input
    cout << endl << "Please enter the temperatures: ";
    for (int i = 0; i < input_quantity; i++)
    {
        double placeholder_value;
        cin >> placeholder_value;
        total_temp += placeholder_value;
    }

    //Prints the average
    cout << "The average temperature is " << total_temp / input_quantity << endl;
    return 0;
}
