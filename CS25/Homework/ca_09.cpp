//Job qualification check
#include <iostream>

bool get_citizenship();
bool get_degree();
bool get_experience();

int main()
{
    //Asks for their citizenship, degree, and experience.
    //To qualify, applicant must be a citizen and have a degree or experience.
    if (get_citizenship() == true && ( get_degree() == true || get_experience() == true ))
    {
       std :: cout << "You got the job!" << std :: endl;
    }
    else
    {
        std :: cout << "Sorry, you do not qualify." << std :: endl;
    }
    return 0;
}

//Returns true if applicant is US citizenship
bool get_citizenship()
{
    char user_input;
    std :: cout << "Are you a US citizen (y/n)?";
    std :: cin >> user_input;
    if (user_input == 'y')
    {
        return true;
    }
    return false;
}

//Returns true if applicant has a bachelor's degree
bool get_degree()
{
    char user_input;
    std :: cout << "Do you have a bachelor's degree (y/n)?";
    std :: cin >> user_input;
    if (user_input == 'y')
    {
        return true;
    }
    return false;
}

//Returns true if applicant has at least two years of experience
bool get_experience()
{
    char user_input;
    std :: cout << "Do you have at least two years of experience (y/n)?";
    std :: cin >> user_input;
    if (user_input == 'y')
    {
        return true;
    }
    return false;
}