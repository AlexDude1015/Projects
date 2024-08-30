#include <iostream>
using namespace std;

//Prototype decleration

    //Returns the nth value of the Fibonacci sequence.
    //Function parameter accepts the nth value as an integer.
    long int get_fibonacci(int sequence);
    //Returns an integer greater than 0 from the user
    int get_sequence_input();

//End


int main()
{

    int sequence = get_sequence_input();
    cout << get_fibonacci(sequence);
    return 0;

}


long int get_fibonacci(int sequence)
{

    if (sequence == 0)
    {
        return 0;
    }
    if (sequence == 1)
    {
        return 1;
    }
    return get_fibonacci(sequence - 1) + get_fibonacci(sequence - 2);

}


int get_sequence_input()
{

    int sequence;
    cout << "Please enter the sequence number: ";
    cin >> sequence;
    cout << endl;
    while (sequence < 0)
    {
        cout << "Please enter a sequence number greater than 0: ";
        cin >> sequence;
        cout << endl;   
    }
    return sequence;

}
