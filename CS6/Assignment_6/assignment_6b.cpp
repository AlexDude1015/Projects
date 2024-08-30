#include <iostream>
#include <cmath>
using namespace std;


//Change MAXIMUM_ROWS to change the total amount of rows.
const int MAXIMUM_ROWS = 7;


//Function Prototypes
void create_row(int);
void create_column(int);
void output_star(int, int);



int main(){

    int current_row_value = 0;
    create_row(current_row_value);
    return 0;

}


//Creates new rows until there are enough
void create_row(int current_row_value){

    if (current_row_value < MAXIMUM_ROWS){

        create_column(current_row_value);
    
    }
        
}


//Determines how many stars are required in one row
void create_column(int current_row_value){

    int column_value = pow(2, current_row_value);
    output_star(column_value, current_row_value);

}


//Prints a specific amount of stars
void output_star(int column_value, int current_row_value){

    cout << string(column_value,'*') << endl;
    create_row(++current_row_value);

}


