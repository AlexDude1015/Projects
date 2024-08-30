#include <iostream>
using namespace std;

int main(){

    const int x = 5;
    const int* ptr;

    ptr = &x + 1;

    
    cout << *ptr;

    return 0;
}