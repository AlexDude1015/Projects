#include <iostream>
#include <string>
using namespace std;

//Declare prototype
string* get_names();
string input_name();
bool ask_more_names();
void sort_array_alphabetically(string* ptr_names_holder, int size);
void output_names(string* ptr_names_holder, int size);



int main(){

    //Assigns the array of names to pointer
    string *ptr_names_holder = get_names();
    //Sorts names alphabetically
    sort_array_alphabetically(ptr_names_holder, 20);
    //Outputs the names
    output_names(ptr_names_holder, 20);
    //Deletes dynamically allocated memory
    delete [] ptr_names_holder;
    //Deallocates pointer
    ptr_names_holder = nullptr;
    return 0;

}

string* get_names(){
    
    //Counts each new name inputs
    int name_index = 0;
    //Is true if user wants to input more names
    bool more_name = true;
    //Assigns dynamic array with 20 elements to pointer
    string* ptr_temp_name = new string[20];

    //Keeps asking for names until user is finished or there are 20 names
    while (name_index < 20 && more_name){

        //Assigns each name to the array
        *(ptr_temp_name + name_index++) = input_name();

        //Asks users if they have more names
        if (name_index < 20){

            more_name = ask_more_names();

        }

    }

    //Assigns unused elements to an empty string
    for (int i = name_index ;i < 20; i++){

        *(ptr_temp_name + i) = "";
    }

    //Returns the pointer of the array
    return ptr_temp_name;

} 

//Prompts and inputs name
string input_name(){
    
    string name_input;
    cout << "Please enter a name: ";
    cin >> name_input;
    cout << endl;
    return name_input;

}

//Gives option to add another name
bool ask_more_names(){

    char is_yes;
    cout << "Would you like to add another name (y/n): ";
    cin >> is_yes;
    cout << endl;

    //Returns true if user inputs 'y'
    if (is_yes == 'y'){

        return true;
        
    }

    //Otherwise, returns false
    return false;

}


//Sorts arrays alphabetically in ascending order
void sort_array_alphabetically(string* ptr_names_holder, int size ){

    for (int i = 0; i < size - 1; i++){

        int highest_index = i;
        
        for (int j = i + 1; j < size; j++){

            if (ptr_names_holder[j] < ptr_names_holder[highest_index]){

                highest_index = j;

            }

        }

        string placeholder_value = ptr_names_holder[i];
        ptr_names_holder[i] = ptr_names_holder[highest_index];
        ptr_names_holder[highest_index] = placeholder_value;

    }

}



//Outputs array's elements
void output_names(string* ptr_names_holder, int size){

    cout << "These are the following name(s): " << endl;

    for (int i = 0; i < size; i++){

        cout << ptr_names_holder[i] << endl; 

    }
}