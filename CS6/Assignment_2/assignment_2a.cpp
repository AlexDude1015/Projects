#include <iostream>
#include <cmath>

using namespace std;

//Declaring a global constant
const double simple_pie = 3.14;


//Ask the user to enter radius
void display_prompt(){

    cout << "----------------------------------------------------------\n";
    cout << "This program finds the area and circumference of a circle.\n";
    cout << "As well as the volume and surface area of a sphere\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Please enter the radius of the circle.\n";
    
}


//User inputs the radius
double get_radius(){

    double radius_input;
    cin >> radius_input;
    return radius_input;

}


//Returns the circumfrence
double find_circumfrence(double radius_input){

    double circle_circumfrence = 2 * simple_pie * radius_input;
    return circle_circumfrence;

}


//Returns the area
double find_area(double radius_input){ 

    double circle_area = simple_pie * pow(radius_input,2);
    return circle_area;

}


//Returns the volume
double find_volume(double radius_input){

    double sphere_volume = 4 * simple_pie * pow(radius_input,3) / 3;
    return sphere_volume;

}


//Returns the surface area
double find_surface_area(double radius_input){

    double sphere_surface_area = 4 * simple_pie * pow(radius_input,2);
    return sphere_surface_area;

}


//Announces the calculated findings
void export_findings(double radius_input){

    cout << "The circumfrence of the circle is " << find_circumfrence(radius_input) << endl;
    cout << "The area of the circle is " << find_area(radius_input) << endl;
    cout << "The surface area of the sphere is " << find_volume(radius_input) << endl;
    cout << "The volume of the sphere is " << find_surface_area(radius_input) << endl;

}



int main(){

    display_prompt();   
    double radius_input = get_radius();
    export_findings(radius_input);
    return 0;

}