#include <iostream>

using namespace std;

//Constant declerations
const int SIZE = 7;



//Prototype declerations
int get_search_input();
int search_array(int[], int search_value, int size);
void report_result(int);



int main(){

    int given_array[] = {1, 4, 6, 5, 2, 7, 10};
    int search_value = get_search_input();
    int search_result = search_array(given_array, search_value, SIZE);
    report_result(search_result);
    return 0;

}


//Prompts and receives user input
int get_search_input(){

    int search_value;
    cout << "Please enter an integer you wish to search: ";
    cin >> search_value;
    cout << endl;
    return search_value;

}


//Searches user input amongst given array's values
int search_array(int given_array[], int search_value, int array_size){

    for (int i = 0; i < array_size; i++){

        if (given_array[i] == search_value){

            return i;

        }

    }    

    return -1;

}


//Announces the findings
void report_result(int search_result){

    if (search_result == -1){

        cout << "The value entered does not exist\n\n";

    }

    else {
        cout << "The value was found at index: " << search_result << "\n";
    }


}