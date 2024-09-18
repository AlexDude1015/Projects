//Users guess a random number and the program insults you each time you get it wrong.
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;



int main()
{
    //Creates random number
    srand(time(nullptr));
    int random_number = rand() & (1000) + 1;

    //Generates 5 possible insults
    string insults[5] = {"You suck bro!", "Guess again loser!!!", "What an idiot!", "Try again dummy", "Nope, are you having fun yet?"};

    //Ask users to guess until they get it right.
    cout << "Please get the number between one and one thousand. ";
    int user_choice = 0;
    while (user_choice != random_number)
    {
        cout << "What is your choice?" << endl;
        cin >> user_choice;
        if (user_choice == random_number) 
        {
             cout << "Congratulations idiot!" << endl;
        }
        else
        {
            cout << insults[(rand() % 4) + 1] << endl;
        } 
    }
    return 0;
}