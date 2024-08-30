#include <iostream>
#include <string>
using namespace std;


class Person
{
    private:

        string name;
        string biography;
        char gender;
        char preference;
        int age;
        string* ptr_interests;

    public:

        Person()
        {
            name = "";
            biography = "";
            gender = ' ';
            preference = ' ';
            age = 0;
            ptr_interests = nullptr;

        }

        Person(string name, string biography, char gender, char preference, int age, string* ptr_interests)
        {
            this-> name = name;
            this-> biography = biography;
            this-> gender = gender;
            this-> preference = preference;
            this-> age = age;
            this-> ptr_interests = ptr_interests;
        }

        void set_name(string name)
        {
            this->name = name;
        }

        string get_name()
        {
            return name;
        }

        void set_biography(string biography)
        {
            this->biography = biography;
        }

        string get_biography()
        {
            return biography;
        }

        void set_gender(char gender)
        {
            this->gender = gender;
        }

        char get_gender()
        {
            return gender;
        }

        void set_preference(char preference)
        {
            this->preference = preference;
        }

        char get_preference()
        {
            return preference;
        }

        void set_age(int age)
        {
            this->age = age;
        }

        int get_age()
        {
            return age;
        }

        void set_interests(string* ptr_interests)
        {
            this->ptr_interests = ptr_interests;
        }

        string* get_interests()
        {
            return ptr_interests;
        }

};

class Match
{
    private:
        Person person_1;
        Person person_2;

    public:
        Match()
        {
            person_1 = Person();
            person_2 = Person();
        }

        Match(Person person_1, Person person_2)
        {
            this->person_1 = person_1;
            this->person_2 = person_2;
        }

        bool is_match(Person person_1, Person person_2)
        {

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (*(person_1.get_interests() + i) == *(person_2.get_interests() + j))
                        {
                            return true;
                        }
                }
            }   
            return false;
        
        }

        string get_message(bool is_true){
            
            if (is_true)
            {
                cout << "You got a match... You SLUT!!!" << endl;
            }
            else
            {
                cout << "I'm sorry you're boring and ugly" << endl;
            }

        }
    

};




int main(){

    Person Connie = Person();


    return 0;

}