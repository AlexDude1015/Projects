//Asks users to enter two values, stores the larger value in a seperate variable, and prints it on the terminal.
#include <iostream>

int get_user_input();

//Prints the larger of two numbers
int main()
{
    int input_one = get_user_input(),
        input_two = get_user_input(), 
        larger_input;
    (input_one > input_two) ? larger_input = input_one : larger_input = input_two;
    std :: cout << "The larger input is: " << larger_input << std :: endl;
    return 0;
}

//Returns an integer
int get_user_input()
{
    int user_input;
    std :: cout << "Please enter a number: ";
    std :: cin >> user_input;
    return user_input;
}