#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Declare prototype
double get_user_input();
double get_root(double);
void output_result(double);


int main(){

    double user_input = get_user_input();
    double final_answer = get_root(user_input);
    output_result(final_answer);
    return 0;

}


double get_user_input(){
    
    double user_input;
    cout << "Please enter a number ";
    cin >> user_input;
    cout << endl;
    return user_input;

}


double get_root(double user_input){

    double last_guess = 1.0, new_guess, current_difference;

    do {

        new_guess = 0.5 * (last_guess + user_input/last_guess); 
        current_difference = abs(new_guess - last_guess);
        last_guess = new_guess;
        
    }
    while (current_difference > 0.00001);

    return new_guess;

}

void output_result(double final_answer){

    cout << fixed << setprecision(16) << final_answer;

}