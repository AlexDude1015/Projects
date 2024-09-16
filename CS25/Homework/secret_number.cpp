#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;



int main()
{
    srand(time(nullptr));
    int random_number = rand() & (1000) + 1;
    cout << "Please get the number between one and one thousand. ";
    int user_choice = 0;
    string insults[5] = {"You suck bro!", "Guess again loser!!!", "What an idiot!", "Try again dummy", "Nope, are you having fun yet?"};
    while (user_choice != random_number)
    {
        cout << "What is your choice?" << endl;
        cin >> user_choice;
        if (user_choice == random_number) 
        {
             cout << "Congratulations!" << endl;
        }
        else
        {
            cout << insults[(rand() % 4) + 1] << endl;
        } 
    }
    return 0;
}