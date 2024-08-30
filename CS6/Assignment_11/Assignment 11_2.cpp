#include <iostream>
#include <string>
using namespace std;

//Function prototypes:----------------------------------------------------

    //Returns an user input as a string
    string get_input();
    //Returns a lowercase string and accepts any string as an argument
    string to_lower(string palindrome);
    //Returns true if the argument is a palindrome
    //Accepts only a string as an argument
    bool is_palindrome(string user_input, int start_index = 0);
    //Announces the user's input is a palindrome if the argument is true.
    void announce_results(string input, bool is_palindrome);

//End of prototypes--------------------------------------------------------



int main()
{
    
    while (true)
    {
        string user_input = get_input();
        string lowercase_user_input = to_lower(user_input);
        bool input_is_palindrome = is_palindrome(lowercase_user_input);
        announce_results(user_input, input_is_palindrome);
    }
    return 0;

}


string get_input()
{

    string palindrome;
    cout << "Please enter a palindrome: ";
    cin >> palindrome;
    cout << endl;    
    return palindrome;
    
}


string to_lower(string palindrome)
{

    for (int i = 0; i < palindrome.size(); i++)
    { 
        palindrome[i] = tolower(palindrome[i]);
    }
    return palindrome;

}


bool is_palindrome(string user_input, int start_index)
{

    int end_index = user_input.length() - start_index - 1;
    if (start_index >= end_index)
    {
        return true;
    }
    else if (user_input[start_index] == user_input[end_index] && is_palindrome(user_input, start_index + 1))
    {
        return true;
    }
    else
    {
        return false;
    }

}


void announce_results(string input, bool is_palindrome)
{

    if (is_palindrome)
    {
        cout << input << " is a palindrome" << endl;
    }
    else
    {
        cout << input << " is not a palindrome" << endl;
    }
    cout << endl;

}