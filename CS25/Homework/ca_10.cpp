//Calculates the commission of a sale.
#include <iostream>
#include <iomanip>

double get_user_sale();
double get_commission_rate(double);

//Prints the saleman's earnings
int main()
{
    double user_sale = get_user_sale();
    double sale_commission = get_commission_rate(user_sale);
    std :: cout << std :: fixed << std :: setprecision(2);
    std :: cout << "Your commission is $" << user_sale * sale_commission;
    return 0;
}

//Returns the value of the user's last sale
double get_user_sale()
{
    double user_input;
    std :: cout << "How much did you make on your sale?";
    std :: cin >> user_input;
    return user_input;
}

//Returns the commission rate based on the user's last sale
double get_commission_rate(double user_input)
{
    if (user_input > 15000){
        return .2;
    }
    if (user_input > 10000)
    {
        return .15;
    }
    return .1;
}