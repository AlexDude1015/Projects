//This program generates two random values between 1-6
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Returns number between 1 - 6
int roll_dice()
{
    return rand() % 6 + 1;
}

int main()
{   
    //Uses current time as seed for rand()
    srand(time(nullptr));
    cout << "Dice rolls: " << roll_dice() << " " << roll_dice() << endl; 
    return 0;
}