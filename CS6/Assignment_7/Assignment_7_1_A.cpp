#include <iostream>
#include <cstdlib>
#include <time.h> 
#include <iomanip>
#include <string>

using namespace std;

//Declare Prototype
void get_histogram(int []);
double custom_rand();
void initialize_array(int [], int);
void announce_results(int [], int);
string generate_star(int);


int main(){

    srand(time(0));
    int histogram_value[10];
    initialize_array(histogram_value, 10);
    get_histogram(histogram_value);
    announce_results(histogram_value, 10);

}


//Assigns every element in an array's value to zero
void initialize_array(int array_placeholder[], int array_length){

    for (int i = 0; i < array_length; i++){
        array_placeholder[i] = 0;
    }

}

//Creates random values and assigns their range to an array
void get_histogram(int histogram_value[]){

    for (int i = 0; i < 10000; i++ ){
        double random_value = custom_rand();

        for (int j = 9; j >= 0; j--){
            if (random_value > static_cast<double>(j) / 10){
                histogram_value[j] += 1;
                break;
            }
        }
    }   
}


//Generates a random number between zero and one
double custom_rand(){

    double random_value = rand() % 1000 + 1;
    return random_value / 1000;

}

string generate_star(int star_quantity){

    star_quantity /= 50;
    string total_star_value = "";


    for (int i = 0; i < star_quantity; i++){

        total_star_value += "*";

    }

    return total_star_value;

}


//Announces the results
void announce_results(int histogram_value[], int array_length){

    cout << fixed << setprecision(2);
    cout << left << setw(25) << "Frequency";
    cout << left << "Histogram" << endl << endl;

    for (int i = 0; i < array_length; i++){

        cout << left << setw(25) << histogram_value[i];
        cout << left << generate_star(histogram_value[i]) << endl;
        
    }

}
