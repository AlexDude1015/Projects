//Assignment 10.1 Palindrome 
//This program takes a user input and determines if it's a palindrome.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


//Prototype start:
string get_input();
string to_lower(string palindrome);
bool is_palindrome(string palindrome);
void announce_results(bool is_palindrome);



int main(){

    string palindrome = get_input();    

    palindrome = to_lower(palindrome);              
    
    bool result = is_palindrome(palindrome);        
    
    announce_results(result);                       
    
    return 0;

}


//Asks for an user input and returns it as a string
string get_input(){

    string palindrome;
    
    cout << "Please enter a palindrome: ";
    
    cin >> palindrome;
    
    cout << endl;
    
    return palindrome;
    
}


//Takes a string and returns it in all lowercase
string to_lower(string palindrome){

    for (int i = 0; i < palindrome.size(); i++){
     
        palindrome[i] = tolower(palindrome[i]);
    
    }
    
    return palindrome;

}


//Takes a string and returns true if it's a palindrome
bool is_palindrome(string palindrome){

    for (int start_char = 0, end_char = palindrome.size() - 1; start_char < end_char; start_char++, end_char-- ){
        
        if (!(palindrome[start_char] == palindrome[end_char])){
        
            return false;
        
        }
    }

    return true;

}


//Takes in a boolean value. If true, the function reports that the value is a palindrome.
void announce_results(bool is_palindrome){

    if (is_palindrome){

        cout << "The value is a palindrome" << endl;

    }

    else {
    
        cout << "The value is not a palindrome" << endl;
    
    }

}