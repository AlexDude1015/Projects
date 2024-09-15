//This program calculates a circle's area from a radius input
#include <iostream>
#include <iomanip>

//Asks users to input the radius
double get_user_radius()
{
  std :: cout << "Please enter the radius of a circle: ";
  double user_radius;
  std :: cin >> user_radius;
  std :: cout << std :: endl;
  return user_radius;
}

int main()
{
    const double PI = 3.14;
    double user_radius = get_user_radius();
    //Calculates the area from the user input
    double circle_area = user_radius * user_radius * PI;
    //Outputs the
    std :: cout << std :: fixed << std :: setprecision(2) << "Area of the circle: " << circle_area << std :: endl;
    return 0;
}