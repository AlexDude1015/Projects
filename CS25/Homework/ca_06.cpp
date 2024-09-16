#include <iostream>
#include <string>

using namespace std;

//Prototype

string request_user_input(string);

int main()
{
    //Request inputs
    string user_street = request_user_input("street"), 
    user_city = request_user_input("city"),
    user_state = request_user_input("state"),
    user_zip_code = request_user_input("zip code");
    //Output data
    cout << user_street << endl; 
    cout << user_city << ", " << user_state << ", " << user_zip_code << endl;
    return 0;
}

//Requests and returns the user's input
string request_user_input(string metric_type)
{
    string user_output;
    cout << "Please enter your " << metric_type << ": ";
    cin >> user_output;
    cout << endl;
    return user_output;
}