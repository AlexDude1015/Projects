#include <iostream>
#include <iomanip>

using namespace std;


//Asks user for first input value
int input_first_value(){

    int first_value;
    cout << "Please enter the first number: ";
    cin >> first_value;
    cout << endl;
    return first_value;

}


//Asks users for second input value
int input_second_value(){

    int second_value;
    cout << "Please enter the second number: ";
    cin >> second_value;
    cout << endl;
    return second_value;

}


//Ask users for the operator input value
char input_operator_value(){

    char operator_value;
    cout << "Please enter the operation (enter one of +, -, * , /, % ): ";
    cin >> operator_value;
    cout << endl;
    return operator_value;

}


//Checks to see if the input operator is valid.
bool check_operator_value (char operator_value){

    if (operator_value == '+' || operator_value == '-' || operator_value == '/' || operator_value == '*' || operator_value == '%') {
        return true;
    }
    else {
        cout << "Error! The selected operator was not vaid.\n";
        return false;
    }

}


//Returns the calculations of the user's inputs.
double calculate_inputs_value(int first_value, int second_value, char operator_value){

    if (operator_value == '+'){
        return first_value + second_value;
    }

    else if (operator_value == '-'){
        return first_value - second_value;
    }

    else if (operator_value == '*'){
        return first_value * second_value;
    }

    else if (operator_value == '/'){
        return static_cast<double>(first_value) / second_value;
    }

    else {
        return first_value % second_value;
    }

}

void report_calculation(int first_value, int second_value, char operator_value){

    cout << fixed << setprecision(2) << first_value << " " << operator_value << " " << second_value << " = " << calculate_inputs_value(first_value, second_value, operator_value) << endl << endl;

}

void calculation_iteration() {

    int first_value = input_first_value();
    int second_value = input_second_value();
    char operator_value = input_operator_value();

    if (check_operator_value(operator_value) == true) {

        report_calculation(first_value, second_value, operator_value);

    }


}

int main(){
    
    cout << "Welcome to the calculator app.\n";

    for ( bool i = true; i == true; ) {
        calculation_iteration();
    }

    return 0;

}