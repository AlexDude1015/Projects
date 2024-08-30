#include <iostream>
using namespace std;

// Gets the first value
int get_value_one(){

    int value_one = 0;
    cout << "Please enter a integer number: ";
    cin >> value_one;
    cout << endl;
    return value_one;

}


// Gets the second value
int get_final_value(){

    int final_value = 0;
    cout << "Please enter another integer number: ";
    cin >> final_value;
    cout << endl;
    return final_value;

}


// Adds the first value by itself repeatively. The second value determines how many repeats.
int multiply_by_addition( int value_one, int final_value){

    int product_value = 0;
    for (int i = 0; i < final_value; i++){
        product_value += value_one;
    }
    return product_value;

}


// Gets the inputs, calculates, and outputs the results.
int main(){

    int value_one = get_value_one();
    int final_value = get_final_value();
    int product_value = multiply_by_addition(value_one, final_value);
    cout << value_one << " X " << final_value << " = " << product_value << endl;
    return 0;

}