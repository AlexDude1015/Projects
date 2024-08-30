#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototypes
void print_column_name();
void print_values();
int get_square(int);
double get_square_root(int);


int main(){

    print_column_name();
    print_values();
    return 0;

}


//Creates columns
void print_column_name(){

    cout << left << setw(10) << "Number";
    cout << left << setw(10) << "Square";
    cout << left << setw(10) << "Root" <<;

}


//Prints values of each row for 81 times
void print_values(){

    static int current_value = 1;

    if (current_value < 82 ){

        cout << fixed << setprecision(2);
        cout << left << setw(10) << current_value;
        cout << left << setw(10) << get_square(current_value);
        cout << left << setw(10) << get_square_root(current_value) << endl;
        current_value++;
        print_values(); 

    }

}



//Returns the square of the argument
int get_square(int current_value){

    return pow(current_value, 2);

}


//Returns the square root of the argument
double get_square_root(int current_value){

    return sqrt(current_value);

}