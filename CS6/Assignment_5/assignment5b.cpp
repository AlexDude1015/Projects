#include <iostream>
#include <cctype>
using namespace std;


//Function prototype
int get_sequence_number();
int calculate_fibonacci_sequence(int);


int main(){

    int sequence_number = get_sequence_number();
    cout << "At sequence number " << sequence_number << ", the value is " << calculate_fibonacci_sequence(sequence_number) << ". \n";
    return 0;

}



int get_sequence_number(){

    int sequence_number;
    cout << "Please number in the Fibonacci sequence would you like to see: ";
    cin >> sequence_number;
    cout << "\n";

    while (isdigit(sequence_number) && sequence_number <= 0) {

        cout << "Please enter a proper value: ";
        cin >> sequence_number;
        cout << endl;

    }

    return sequence_number;

}


int calculate_fibonacci_sequence(int sequence_number){

    switch(sequence_number) {

        case 0:
            return 0;
        
        case 1:
            return 1;
    
    }
    
    int sequence_result[sequence_number];

    sequence_result[0] = 0;
    sequence_result[1] = 1;

    for ( int i = 2; i < (sequence_number + 1); i++ ){

        sequence_result[i] = sequence_result[i-1] + sequence_result[i-2];

    }

    return sequence_result[sequence_number];
    
}
