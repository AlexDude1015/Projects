#include <iostream>


int main()
{
  std::cout << "Enter three numbers between 1 to 10" << std::endl;
  int number_one, number_two, number_three;
  std::cin >> number_one >> number_two >> number_three;
  std::cout << "You entered the numbers: " << number_one << number_two << number_three << std::endl;

  return 0;
}