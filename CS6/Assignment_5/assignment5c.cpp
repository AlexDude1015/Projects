#include <iostream>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;


//Global value decleration
const int MONTH = 0;
const int INITIAL_PRINCIPLE = 1;
const int INTEREST_PAYMENT = 2;
const int PRINCIPLE_PAYMENT = 3;
const int FINAL_PRINCIPLE = 4;
const int TOTAL_NUMBER_OF_MONTHLY_REPORTS = 36;



//Prototype decleration
double get_principle_input();
double get_terms_input();
double get_interest_input();
double calculate_monthly_payment(double, double, double);
void output_table_title();
void output_monthly_loan_bill(double, double, double);



int main(){

    double principle_value = get_principle_input();
    double terms_value = get_terms_input();
    double monthly_interest_rate_value = get_interest_input() / 12;
    output_table_title();
    output_monthly_loan_bill(principle_value, terms_value, monthly_interest_rate_value);
    return 0;

}


double get_principle_input(){

    double principle_input;
    cout << "Please enter the initial principle amount: $";
    cin >> principle_input;
    cout << endl;
    return principle_input;

}


double get_terms_input(){

    double terms_input;
    cout << "Please enter the terms of the loan in years: ";
    cin >> terms_input;
    cout << endl;
    return terms_input;

}


double get_interest_input(){

    double interest_input;
    cout << "Please enter the interest rates as a percentage: %";
    cin >> interest_input;
    cout << endl;
    return interest_input / 100;

}


void output_table_title(){

    cout << left << setw(10) << "Months" << setw(20) << "Initial Principle" << setw(20) << "Interest Payment";
    cout << setw(20) << "Principle Paid" << setw(20) << "Final Principle" << endl;

}


double calculate_monthly_payment(double principle_value, double terms_value, double monthly_interest_rate_value){

    double monthly_payment_value = principle_value * monthly_interest_rate_value / ( 1 - ( 1 / pow( (1 + monthly_interest_rate_value) , (terms_value * 12) ) ) );
    return monthly_payment_value;

}


void output_monthly_loan_bill(double principle_value, double terms_value, double monthly_interest_rate_value){

    double payment_details[5];
    payment_details[INITIAL_PRINCIPLE] = principle_value;
    cout << fixed << setprecision(2);
    double monthly_payment_value = calculate_monthly_payment(principle_value, terms_value, monthly_interest_rate_value);

    for (int i = 0; i < TOTAL_NUMBER_OF_MONTHLY_REPORTS; i++){

        payment_details[MONTH] = i + 1;
        payment_details[INTEREST_PAYMENT] = payment_details[INITIAL_PRINCIPLE] * monthly_interest_rate_value;
        payment_details[PRINCIPLE_PAYMENT] = monthly_payment_value - payment_details[INTEREST_PAYMENT];
        payment_details[FINAL_PRINCIPLE] = payment_details[INITIAL_PRINCIPLE] - payment_details[PRINCIPLE_PAYMENT];

        cout << "Month " << left << setw(10) << static_cast<int>(payment_details[MONTH]);
        cout << setw(20) << payment_details[INITIAL_PRINCIPLE];
        cout << setw(20) << payment_details[INTEREST_PAYMENT];
        cout << setw(20) << payment_details[PRINCIPLE_PAYMENT];
        cout << setw(20) << payment_details[FINAL_PRINCIPLE] << endl;

        payment_details[INITIAL_PRINCIPLE] = payment_details[FINAL_PRINCIPLE];

    }

}





