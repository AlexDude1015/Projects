#include <iostream>
using namespace std;


//Returns an integer from the user
int get_user_input();
//Output a reversed integer
void reverse_integer(int working_value);


int main()
{

    int user_input = get_user_input();
    reverse_integer(user_input);
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


void reverse_integer(int working_value)
{
    
    if (working_value / 10 == 0)
    {
        cout << working_value % 10 << endl;
    }
    else 
    {
        cout << working_value % 10;
        reverse_integer(working_value / 10);
    }
    
}