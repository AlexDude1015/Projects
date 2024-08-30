#include <iostream>
using namespace std;



//Constant declerations
const int SIZE = 7;


//Prototype declerations
void reverse_array(int[], int);
void report_array(int[], int);



int main(){

    int given_array[] = {1, 4, 6, 5, 2, 7, 10};
    report_array(given_array, SIZE);
    reverse_array(given_array, SIZE);
    report_array(given_array, SIZE);
    return 0;

}


//Announces all values stored in the array
void report_array(int given_array[], int array_size){

    cout << "Here are the values of the array: ";

    for (int i = 0; i < array_size; i++){

        cout << given_array[i] << ", ";

    }

    cout  << endl;

}


//Reverses any given array
void reverse_array(int given_array[], int array_size){
    
    //The variable "i" increments while "j" decrements...
    //...which swaps arrays with even or odd number of elements.

    for (int i = 0, j = array_size - 1; i < j; i++, j--){

        int placeholder_value = *(given_array + i);
        *(given_array + i) = *(given_array + j);
        *(given_array + j) = placeholder_value;

    }

    cout << "Array has been reversed!\n";

}

