#include <iostream>
using namespace std;


int get_number()
{
    int user_input = 0;
    do
    {
        cout << "Please enter a number: ";
        cin >> user_input;
    } while(user_input < 0);
    return user_input;
}

int get_factorial(int user_input)
{
    if (user_input == 0)
    {
        return 1;
    }
    return user_input * get_factorial(user_input - 1);
}

int main()
{
    int factorial_result = get_factorial(get_number());
    cout << "The result is: " << factorial_result;
    return 0;
}