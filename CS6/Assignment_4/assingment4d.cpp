#include <iostream>
#include <string>


using namespace std;


// Asks users to input numbers into a string because this data type is an array.
string get_initial_value(){

    string initial_value;
    cout << "Please enter an integer value: ";
    cin >> initial_value;
    cout << endl;
    return initial_value;
    
}


// Reverses the argument by breaking the initial input into chars and assigning the reverse to a new string.
string reverse_initial_value(string initial_value){

    string reverse_value = initial_value;

    for (int i = 0, j = initial_value.size(); i < initial_value.size(); i++, j--){

        reverse_value[i] = initial_value[j-1];

    }

    return reverse_value;

}



int main(){

    string initial_value = get_initial_value();
    string reverse_value = reverse_initial_value(initial_value);
    cout << "This is your value reversed: " << reverse_value << endl;
    return 0;

}