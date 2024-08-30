#include <iostream>
#include <cmath>

using namespace std;


// Finds the absolute value of any integer.
int get_absolute_value(int counter_value){

    return sqrt(counter_value * counter_value);

}


// Produces diagram with a single star using two tricks: The counter is initialized as a negative number
// and a function that returns the absolute value.
int main(){

   for (int i = -6; i <= 6; i++) {
    
        for (int j = 0; j < pow(2, (6 - get_absolute_value(i))); j++ ){

            cout << "*";

        }
    
    cout << endl;

    }
       
    return 0;

}