#include <iostream>
using namespace std;


int get_number()
{
    int user_input = 0;
    do
    {
        cout << "Please enter a positive number: ";
        cin >> user_input;
    } while(user_input < 0);
    return user_input;
}

int get_factorial(int user_input)
{
    int factorial_result = 1;
    for (int i = 1; i <= user_input; i++)
    {
        factorial_result *= i;
    }
    return factorial_result;
}

int main()
{
    int factorial_result = get_factorial(get_number());
    cout << "The result is: " << factorial_result;
    return 0;
}