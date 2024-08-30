#include <iostream>
using namespace std;

int get_digits(int user_input)
{   
    if (user_input == 0)
    {
        return 0;
    }   
    return user_input % 10 + get_digits(user_input / 10);
}

int main()
{
    cout << get_digits(123);
    return 0;
}