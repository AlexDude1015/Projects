#include <iostream>
using namespace std;

int main(){

    int number_one = 2;
    int number_two = 1;
    int placeholder = number_one;
    number_one = number_two;
    number_two = placeholder;
    return 0;
    
}