//This program inputs a user's date as a string and outputs a user's date as an int. 

#include <iostream>
#include <string>
#include <cctype>
using namespace std;


//Declare prototype
void get_date(int* day_int_value, int* month_int_value, int* year_int_value);
string get_user_input();
string get_lowercase(string);
int convert_month(string month_value);
void output_date(int, int, int);



int main(){

    //Declare placeholders for day, month, and year
    int day_int_value, month_int_value, year_int_value;
    //User inputs values into the placeholders
    get_date(&day_int_value, &month_int_value, &year_int_value);  
    //Outputs the days according to mm/dd/yyyy
    output_date(day_int_value, month_int_value, year_int_value);

    return 0;

}


//Takes three integers as arguments and returns the date
void get_date(int* day_int_value, int* month_int_value, int* year_int_value){

    //Recieves string of date in dd/mmm/yyyy syntax
    string date_input = get_user_input();
    //Creates substring of the day and converts it into an integer
    *day_int_value = stoi(date_input.substr(0,2));
    //Creates substring of the month, converts it into lowercase, and convert it an integer
    *month_int_value = convert_month(get_lowercase((date_input.substr(3,3))));
    //Creates substring of year and converts it into an integer
    *year_int_value = stoi(date_input.substr(7,4));

}


//Ask user for a date and returns it as a string in dd/mmm/yyyy syntax
string get_user_input(){

    string date_input;
    cout << "Please enter the date in the form dd/mmm/yyyy: ";
    cin >> date_input;
    cout << endl;
    return date_input;

}


//Returns a lowercase string; accepts string argument
string get_lowercase(string month_input){

    //Transforms string into lowercase characters using a ranged based for loop C++ 11
    for (auto& x : month_input){
        x = tolower(x);
    }
    return month_input;

}


//Outputs the date; accepts three int arguments
void output_date(int day_int_value, int month_int_value ,int year_int_value){

    cout << "The user input is: ";
    //Outputs the user's input in mm/dd/yyyy syntax
    cout << month_int_value << "/" << day_int_value << "/" << year_int_value << endl;

}


//Converts the string value of a month into an integer value of a month
int convert_month(string month_value){

    //Initialize an array which holds every month
    string month_string[] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    //Cycles through every month and returns the corresponding month as an integer
    for (int i = 0; i < 12; i++){
        if (month_string[i] == month_value){
            return i + 1;
        }
    }
    return -1;
}
