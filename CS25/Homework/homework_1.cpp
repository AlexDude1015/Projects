#include <iostream>
#include <vector>

int get_number();
void get_binary(std::vector<int> &sequence, int user_input);
void output_binary(std::vector<int> sequence);

int main()
{
    int user_input = get_number();
    std::vector<int> sequence;
    get_binary(sequence, user_input);
    output_binary(sequence);
    return 0;
}

//Asks users to input a positive number
int get_number()
{
    int user_input;
    do
    {
        std::cout << "Please enter a positive integer: ";
        std::cin >> user_input;
        std::cout << std::endl;
    } 
    while(user_input < 0);
    return user_input;
}

//Gets the binary sequence in reverse
void get_binary(std::vector<int> &sequence, int user_input)
{
    while (user_input != 0)
    {
        sequence.push_back(user_input % 2);
        user_input /= 2;
    }
}

//Prints the binary sequence correctly
void output_binary(std::vector<int> sequence)
{
    for (int i = sequence.size() - 1; i >= 0; --i)
    {
        std::cout << sequence.at(i);
    }
}