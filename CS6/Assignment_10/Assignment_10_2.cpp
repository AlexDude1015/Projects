//This program finds the greatest common value inside an array.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


//Global variable

//Affects the size of the array generated for this program
const int ARRAY_SIZE = 20;


//Function prototypes

void get_random_values(int sequence[], int array_size);
void output_array_values(int sequence[], int array_size);
int find_greatest_common_number(int sequence[], int array_size);



int main(){
    
    srand(time(0));

    int sequence[ARRAY_SIZE];

    get_random_values(sequence, ARRAY_SIZE);

    output_array_values(sequence, ARRAY_SIZE);

    cout << "The most common value in the array is: " << find_greatest_common_number(sequence, ARRAY_SIZE) << endl;;
    
    return 0;

}


//Assigns random numbers to any array. The paramater takes an array and its size.
void get_random_values(int sequence[], int array_size){

    for (int i = 0; i < array_size; i++){

        *(sequence + i) = rand() % 10 + 1;

    }

}


//Couts the array's value. The parameter takes the array and its size.
void output_array_values(int sequence[], int array_size){

    for (int i = 0; i < array_size; i++){

        cout << *(sequence + i) << " ";

    }

    cout << endl;
}


//Returns the greatest common value inside an array. The parameter takes in an array and its size.
int find_greatest_common_number(int sequence[], int array_size){

    int max_index = 0;
    int max_counter = 0;

    for (int i = 0; i < array_size; i++){

        int current_counter = 0;

        for (int j = i + 1; j < array_size; j++){

            if (*(sequence + i) == *(sequence + j)){

                current_counter++;
            }

        }

        if ( current_counter > max_counter) {

            max_counter = current_counter;
            max_index = i;

        }
        
    }

    if (max_counter == 1){

        return -1;
    }


    else if (max_counter > 1){

        return *(sequence + max_index);

    }

    else {

        return -1;

    }

}