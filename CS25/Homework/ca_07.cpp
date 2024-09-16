//Asks users for three names, stores them in the array, and prints the first name
#include <iostream>
#include <string>

//Prototype
std :: string request_user_input();

int main()
{
    //Creates storage for the names
    std :: string name_inputs[3];
    //Gets three names
    for (int i = 0; i < 3; i++)
    {
        name_inputs[i] = request_user_input();
    }
    //Prints the first name
    std :: cout << "The first name is: " << name_inputs[0] << std :: endl;
    return 0;
}

//Prompts and returns names
std :: string request_user_input()
{
    std :: string user_output;
    std :: cout << "Please enter your name: ";
    std :: cin >> user_output;
    std :: cout << std :: endl;
    return user_output;
}