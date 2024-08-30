#include <iostream>
using namespace std;


//Constant declerations
const int SIZE = 7;


//Prototype declerations
void report_array(int[], int);
void sort_odd_first(int[], int);
bool is_even(int);



int main(){

    int given_array[] = {1, 4, 6, 5, 2, 7, 10};
    report_array(given_array, SIZE);
    sort_odd_first(given_array, SIZE);
    report_array(given_array, SIZE);
    return 0;

}


//Outputs every single value inside the array
void report_array(int given_array[], int array_size){

    cout << "Here are the values of the array: ";
    for (int i = 0; i < array_size; i++){
        cout << given_array[i] << ", ";
    }
    cout  << endl;

}


//Bubble sorts the given array by swapping even elements with the next element
void sort_odd_first(int given_array[], int array_size){

    for (int i = 0; i < array_size - 2; i++){
        for (int j = 0; j < array_size - 2 - i; j++){
            if (is_even(given_array[j])){
                int placeholder = given_array[j];
                given_array[j] = given_array[j + 1];
                given_array[j + 1] = placeholder;
            }
        }
    }
    cout << "Array has been sorted by odd first.\n";

}



//Returns true if the integer is even
bool is_even(int test_value){

    if (test_value % 2 == 0 ){
        return true;
    }
    return false;

}




