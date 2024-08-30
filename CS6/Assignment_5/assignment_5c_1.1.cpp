#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


//Prototype
void generate_monthly_statement(double initial_principle, double monthly_interest, double terms, double monthly_payment);
double get_initial_principle();
double get_monthly_interest();
double get_terms();
double get_monthly_payment(double initial_principle, double monthly_interest, double terms);



//Neat programming is organizing our code...
//...into functions much like how essays are organized into paragraphs.
int main(){

    double initial_principle = get_initial_principle();
    double monthly_interest = get_monthly_interest();
    double terms = get_terms();
    double monthly_payment = get_monthly_payment(initial_principle, monthly_interest, terms);
    cout << fixed << setprecision(2);

    generate_monthly_statement(initial_principle, monthly_interest, terms, monthly_payment);


    return 0;

}


void generate_monthly_statement(double initial_principle, double monthly_interest, double terms, double monthly_payment){

    
    for (int i = 0; i < 1; i++){

        cout << "Month = " << i + 1 << endl;
        
        cout << "Initial Principle = " << initial_principle << endl;

        double interest_payment = monthly_interest * initial_principle;
        cout << "Interest Payment = " << interest_payment << endl;

        double principle_payment = monthly_payment - interest_payment;
        cout << "Principle Payment = " << principle_payment << endl;

        double final_principle = initial_principle - principle_payment; 
        cout << "Final Principle = " << final_principle << endl;

        initial_principle = final_principle;   

    }
}


double get_initial_principle(){

    double initial_principle;
    cout << "Please enter the initial principle: ";
    cin >> initial_principle;
    cout << endl;
    return initial_principle;
    
}


double get_monthly_interest(){

    double monthly_interest;
    cout << "Please enter the interest rate: ";
    cin >> monthly_interest;
    cout << endl;
    return monthly_interest / (12 * 100);

}


double get_terms(){

    double terms;
    cout << "Please enter the terms: ";
    cin >> terms;
    cout << endl;
    return terms;

}


double get_monthly_payment(double initial_principle, double monthly_interest, double terms){

    return (initial_principle * monthly_interest) / (1 - (1 / pow((1 + monthly_interest), terms * 12)));

}




