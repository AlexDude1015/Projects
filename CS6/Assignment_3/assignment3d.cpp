#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;


// Ask user for income.
double input_income_value(){

    double income_value;
    cout << "Please enter your total taxable income this year: ";
    cin >> income_value;

    // Loops until the user's income is reasonable
    while (income_value >= INT_MAX) {

        cout << "\nThe value was too large, please try again: ";
        cin >> income_value;
        cout << "\n";

    }

    return income_value;

}


// Inputs the income value and outputs the tax owed.
double calculate_tax_owed(double income_value){

    double tax_owed_value = 0;
    int tax_brackets[] = {0, 30000, 50000, 100000, 200000, 250000, INT_MAX};
    double tax_rates[] = {0.0, 0.1, 0.2, 0.3, 0.35, 0.4};

    // Compares user's income to incrementally higher tax brackets
    for (int i = 0; i < sizeof(tax_brackets) / sizeof(int) - 1; i++){

        if (income_value <= tax_brackets[i + 1]){
            return tax_owed_value += ( income_value - tax_brackets[i] ) * tax_rates[i];
        }
        else {
            tax_owed_value += ( tax_brackets[i + 1] - tax_brackets[i] ) * tax_rates[i];
        }

    }
}


int main(){

    double income_value = input_income_value();
    double tax_owed_value = calculate_tax_owed(income_value);
    cout << fixed << setprecision(2) << "Deducted amount: $" << tax_owed_value << endl;
    cout << "Amount after deduction: $" << income_value - tax_owed_value << endl;
    return 0;
    
}