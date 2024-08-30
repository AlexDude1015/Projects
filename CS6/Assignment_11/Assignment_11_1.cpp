#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Function prototypes:

    //Returns an user inputted integer
    int get_user_input();
    //Outputs the a number, its square, and its root starting from 1 until the desired number.
    void print_squares_and_roots(int final_base, int current_base = 1);

//End


int main()
{   
    int user_input = get_user_input();
    print_squares_and_roots(user_input);
    return 0;

}


int get_user_input()
{

    int input;
    cout << "Please enter a positive integer: ";
    cin >> input;
    cout << endl;
    return input;

}


void print_squares_and_roots(int final_base, int current_base = 1)
{

    //Outputs base
    cout << left << setw(15) << current_base;
    //Outputs square
    cout << left << setw(15) << static_cast<int>(pow(current_base, 2));
    //Outputs square root
    cout << fixed << setprecision(4)<< left << setw(20); 
    cout << sqrt(static_cast<double>(current_base)) << endl;
    //Begins next line
    if (final_base > current_base)
    {
        print_squares_and_roots(final_base, current_base + 1);
    }
    
}