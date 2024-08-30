#include <iostream>
using namespace std;


//Declare prototype:
int* double_array(int[], int);
void output_array(int*, int);

int main(){

    //Creates original array
    int original_array[4] = {1,2,3,4};
    //Doubles original array and assigns it to pointer placeholder
    int* ptr_double_array = double_array(original_array, 4);
    //Outputs the array 
    output_array(ptr_double_array, 8);
    //Deletes the dynamically allocated memory
    delete [] ptr_double_array;
    //Deallocated pointer
    ptr_double_array = nullptr;
    return 0;

}

//Takes an array and return a doubled array with its the original's elements copied
int* double_array(int original_array[], int array_size){

    //Create pointer for dynamic array
    int* ptr_temp_array = new int [array_size * 2];

    //For loop cycles through every element of the dynamic array,
    //copies the original array to new one, and assigns unused elements to 0
    for (int i = 0; i < ((array_size * 2) - 1); i++){

        //Copies original array
        if (i < array_size) {
            ptr_temp_array[i] = original_array[i];
        }
        //Assigns unused elements to 0
        else {
            ptr_temp_array[i] = 0;
        }

    }

    return ptr_temp_array;

}


//Outputs any array
void output_array(int* ptr_double_array, int array_size){

    cout << "The double array's value is: ";

    //Cycles through the array and outputs each element
    for (int i = 0; i < array_size; i++){

        cout << *(ptr_double_array + i) << " ";

    }

    cout << endl;
}