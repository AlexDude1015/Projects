//This program asks users to input two 2x2 matrixes. Then the user can decide to add or subtract them.

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;


//Constant declaration:
const int ARRAY_SIZE = 2;


//Prototype decleration:
void get_matrix_input(int[][ARRAY_SIZE], int, string);
bool is_plus();
void report_matrix_result(int[][ARRAY_SIZE], int, bool);
char get_operator_char(bool);


int main(){

    //Define two 2X2 matrixes
    int matrix_a[ARRAY_SIZE][ARRAY_SIZE];
    int matrix_b[ARRAY_SIZE][ARRAY_SIZE];

    //Inputs the values for the two matrixes
    get_matrix_input(matrix_a, ARRAY_SIZE, "Matrix_A");
    get_matrix_input(matrix_b, ARRAY_SIZE, "Matrix_B");

    //Inputs user selected operator
    bool selected_operation = is_plus();
    
    int calculated_matrix[ARRAY_SIZE][ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++){

        for (int j = 0; j < ARRAY_SIZE; j++){

            if (selected_operation) {

                calculated_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];

            }

            else {

                calculated_matrix[i][j] = matrix_a[i][j] - matrix_b[i][j];

            }
        }
    }

    return 0;

}


//Ask users to input the value for each element of the 2D array
void get_matrix_input(int matrix[][ARRAY_SIZE], int array_size, string matrix_name){

    for (int i = 0; i < array_size; i++){

        for (int j = 0; j < array_size; j++){

            cout << "Please enter the value for " << matrix_name << " [" << i << "][" << j <<"]: ";
            cin >> matrix[i][j];
            cout << endl;

        }
    }
}


//Prompts the user to choose an operator and returns true if plus was selected
bool is_plus(){

    int computation_input = 0;

    do {

        cout << "PLease choose an operator to compute the two matrices: \n";
        cout << "Press '1' for +" << endl;
        cout << "Press '2' for -" << endl;
        cin >> computation_input;

    } while (computation_input != 1 && computation_input != 2);

    if (computation_input == 1){

        return true;

    }

    return false;

}


//Announces the results of the matrix
void report_matrix_result(int matrix[][ARRAY_SIZE], int array_size) {

    for (int i = 0; i < ARRAY_SIZE - 1; i++) {

        for (int j = 0; j < ARRAY_SIZE - 1; j++) {

            

        }
    }

}


