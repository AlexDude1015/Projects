#include <iostream>
using namespace std;


int get_factorian(int value){

    if (value > 0){
        return value * get_factorian(value - 1);
    }
    return 1;

}

int get_gcd(int first_value, int second_value){

    if (first_value % second_value == 0){

        return second_value;

    }
    return get_gcd(second_value, first_value % second_value);


}


int main(){

    cout << get_gcd(49, 28);
    return 0;

}