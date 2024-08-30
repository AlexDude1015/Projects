#include <iostream>
using namespace std;


//Prototype declaration
int get_prime_input();
bool is_prime(int);
int set_even(int);
void output_result(bool);


int main(){

    //Creates a placeholder value to store user input
    int prime_value = get_prime_input();
    //Changes negative inputs into positive ones
    prime_value = set_even(prime_value);
    //Stores true/false after determining if the input is prime
    bool prime_status = is_prime(prime_value);
    //Outputs the results depending on true/false
    output_result(prime_status);
    return 0;

}

//Ask users for a prime number and checks for negative numbers
int get_prime_input(){

    int prime_value;
    cout << "Please enter an integer: ";
    cin >> prime_value;
    cout << endl;

    return prime_value;

}

//Changes negative inputs to positive ones in order for the for loop to run properly
int set_even(int prime_value){

    if (prime_value < 0){

        prime_value *= -1;

    }

    return prime_value;

}


//Loops through lesser values of argument and returns true if it is prime.
bool is_prime(int prime_value){

    for (int i = 2; i < prime_value; i++){

        if ((prime_value % i) == 0){

            return false;

        }

    }

    return true;

}


//Outputs the results depending if the input is prime or not.
void output_result(bool prime_status){

    if (prime_status){

        cout << "The value is a prime number" << endl;

    }

    else {

        cout << "The value is not a prime number" << endl;

    }

}