#include <iostream>
#include <iomanip>

double input_f_temp()
{

  std :: cout << "Please enter the temperature in Fahrenheit: ";
  double f_temp;
  std :: cin >> f_temp;
  std :: cout << std :: endl;
  return f_temp;

}

double convert_f_to_c(double f_temp)
{

    return (f_temp - 32) * 5 / 9;

}

int main(){

    double f_temp = input_f_temp();
    double c_temp = convert_f_to_c(f_temp);
    std :: cout << std :: fixed << std :: setprecision(2) << "The temperature in celsius is: " << c_temp << std :: endl;
    return 0;

}