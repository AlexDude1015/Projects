#include <iostream>
#include <iomanip>


double input_tax(){

  std::cout << "Please enter your revenue: ";
  double user_tax;
  std::cin >> user_tax;
  std::cout << std::endl;
  return user_tax;

}

int main()
{

  double user_tax = input_tax();
  double estate_tax = user_tax * .04;
  double county_tax = user_tax * .02;
  std::cout << std::fixed << std::setprecision(2) << "Total taxes owed: $" << county_tax + estate_tax << std::endl;
  return 0;

}