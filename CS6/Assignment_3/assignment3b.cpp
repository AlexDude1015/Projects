#include <iostream>
#include <cmath>
#include <string>

using namespace std;


// Asks users to input their score
int input_score_value(){
    
    int score_value;
    cout << "What score did you recieve?\n";
    cin >> score_value;
    return score_value;

}


// Returns true if the score is between 0 and 100
bool check_valid_grade(int score_value){

    if (score_value <= 100 && score_value >= 0){
        return true;
    }
    else {
        cout << "Please enter a valid grade.\n";
        return false;
    }
}


// Returns the grade letter from the score
char get_grade_letter_from_score_value(int score_value) {

    if (score_value >= 90){
        return 'A';
    }
    if (score_value >= 80){
        return 'B';
    }
    if (score_value >= 70){
        return 'C';
    }
    if (score_value >= 60){
        return 'D';
    }
    else {
        return 'F';
    }

}


// Outputs a comment depending on the letter grade
void get_comment_from_grade_letter(char grade_letter){

    switch (grade_letter){
        case 'A': 
            cout << "Excellent!\n";
            break;
    
        case 'B':
            cout << "Very Good!\n";
            break;
        
        case 'C':
            cout << "Good!\n";
            break;

        case 'D':
            cout << "Try harder next time.\n";
            break;
        
        case 'F':
            cout << "Try very hard next time.\n";
            break;

    }

}


int main(){

    int score_value = input_score_value();
    if (check_valid_grade(score_value) == true) {

        char grade_letter = get_grade_letter_from_score_value(score_value);
        cout << "Your grade is: " << grade_letter << endl;
        get_comment_from_grade_letter(grade_letter);
    
    }
    return 0;
    
}