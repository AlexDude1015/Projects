#include <iostream>
#include <string>
#include <cctype>
using namespace std;


//Global variables
const int VOWEL = 0;
const int CONSTANT = 1;


//Function prototypes
string get_user_input();
int* count_vowels_and_constants(string);
void announce_results(int, int);


//Asks users to input word
//Creates a pointer to hold an array
//Assigns the number of vowels to the first element and the number of constants to the second element of the array
//Announces the results
int main(){

    string word_input = get_user_input();
    int *pointer_character_count = count_vowels_and_constants(word_input);
    announce_results(pointer_character_count[VOWEL], pointer_character_count[CONSTANT]);
    return 0;

}


//Asks users for first input
string get_user_input(){

    string word_input;
    cout << "Please enter a single word: ";
    cin >> word_input;
    cout << endl;
    return word_input;

}


//Creates a static array to hold two values, the number of vowels and constants
//Examines each character to determine if its a vowel, constant, or anything else
//Returns both as an pointer to an array
int* count_vowels_and_constants(string word_input){

    static int character_count[2] = {0, 0};

    for (int i = 0; i < word_input.size(); i++){
        
        if (isalpha(word_input[i])){

            switch (word_input[i]){

                case 'A':
                case 'a':
                case 'E':
                case 'e':
                case 'I':
                case 'i':
                case 'O':
                case 'o':
                case 'U':
                case 'u':
                case 'Y':
                case 'y':
                    character_count[VOWEL] += 1;
                    break;
                
                default:
                    character_count[CONSTANT] += 1;
                    break;

            }
        
        }

    }

    return character_count;

}


//Announces the results
void announce_results(int vowel_count, int constant_count) {

    cout << "The word contains " << vowel_count << " vowel(s)\n";
    cout << "and contains " << constant_count << " constant(s).\n";

}