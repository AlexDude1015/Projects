#include <iostream>
#include <iomanip>
using namespace std;

double get_pow(double base, double power);
double get_base_input();
double get_power_input();


int main()
{   
    double base = get_base_input(), power = get_power_input();
    cout << fixed << setprecision(2);
    cout << "The exponent is: " << get_pow(base, power);
    return 0;
}


//Returns the exponent as an double
//Accepts an double base and power as arguments
double get_pow(double base, double power)
{   
    //Solves positive powers
    if (power > 0)
    {
        if ( power == 1 )
        {
        return base;
        }
        else
        {
        return base * get_pow( base, --power );
        }
    }
    //Solves negative powers
    else
    {
        if ( power == -1 )
        {
        return 1 / base;
        }
        else
        {
        return 1 / base * get_pow( base, ++power );
        }  
    }
}


//Returns the base of an exponent
//represented as an integer
double get_base_input()
{
    double base;
    cout << "Please enter the number of a base: ";
    cin >> base;
    cout << endl;
    return base;
}


//Returns the power of an exponent
//represented as an integer
double get_power_input()
{
    double power;
    cout << "Please enter the number of a power: ";
    cin >> power;
    cout << endl;
    return power;
}