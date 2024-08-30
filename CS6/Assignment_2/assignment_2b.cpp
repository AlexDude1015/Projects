#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Cashier inputs amount received
double get_amount_received(){

    double amount_received;
    cout << "How much money did you receive?\n";
    cin >> amount_received;
    return amount_received;

}

//Cashier inputs amount due
double get_amount_due(){

    double amount_due;
    cout << "How much money is due?\n";
    cin >> amount_due;
    return amount_due;
    
}

//Gets the total dollar value of the customer's change
int get_total_change(double amount_received, double amount_due){

    cout << "The total change is $" << fixed << setprecision(2) << amount_received - amount_due << endl;
    //Multiplied the total change by 100 in order to create an integer.
    return ( amount_received - amount_due ) * 100;

}

//Outputs the optimal quantity of a given currency and the function returns what's still owed.
int get_currency_unit(string currency_name, double currency_value, int current_change, int value_space){

    //Multiplied the currency value by 100 in order to remove decimals and output a perfect integer.
    int modified_currency_value = currency_value * 100;
    cout << currency_name << ":" << setw(value_space) << current_change / modified_currency_value << endl;
    return current_change % modified_currency_value;

}

int main(){

    //Calculates the total change owed
    double amount_received = get_amount_received();
    double amount_due = get_amount_due();
    int current_change = get_total_change(amount_received, amount_due);

    //Exports the optimal quantity of currency for the cashier to return
    current_change = get_currency_unit("Dollars", 1, current_change, 5);
    current_change = get_currency_unit("Quartars", .25, current_change, 4);
    current_change = get_currency_unit("Dimes", .1, current_change, 7);
    current_change = get_currency_unit("Nickles", .05, current_change, 5);
    current_change = get_currency_unit("Pennies", .01, current_change,5 );

    return 0;
}