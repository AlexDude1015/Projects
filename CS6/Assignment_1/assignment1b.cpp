#include <iostream>
#include <cmath>

using namespace std;

//asks for all the inputs, calculates them, and outputs the distance.
void findDistanceOfTwoPoints() {

    //Introduces program
    cout << "\nThis program finds the distance between two points\n";
    

    //intializes inputs
    double pointOneX, pointOneY, pointTwoX, pointTwoY;
    

    //Ask users to input the coordinates of two points
    cout << "Please enter the x-coordinate of the first point\n";
    cin >> pointOneX;                                                        
    cout << "Please enter the y-coordinate of the first point\n";             
    cin >> pointOneY;                                                        
    cout << "Please enter the x-coordinate of the second point\n";            
    cin >> pointTwoX;                                                        
    cout << "Please enter the y-coordinate of second point\n";                
    cin >> pointTwoY;                                                        

    //Finds the difference of both X values and the difference of both Y values
    double differenceOfX = pointTwoX - pointOneX , differenceOfY = pointTwoY - pointOneY;  


    /*
    Outputs the difference of both values for testing
    cout << "The difference of X is " << differenceOfX << endl;
    cout << "The difference of Y is " << differenceOfY << endl;
    */

    //Squares both values   
    double squareOfX = pow(differenceOfX, 2);                                                      
    double squareOfY = pow(differenceOfY, 2);

    /*
    outputs the square of both values for testing
    cout << "The square of the difference of X is " << squareOfX << endl;
    cout << "The square of the difference of Y is " << squareOfY << endl;
    */

    //Adds both values
    double sumOfXY = squareOfX + squareOfY;


    /*
    Outputs the sum for testing
    cout << "The sum is " << sumOfXY << endl; 
    */

    //Square roots the sum
    double distanceOfAB = sqrt(sumOfXY);

   //Outputs the distance
    cout << "The distance between the two point is " << distanceOfAB << endl;
}

int main() {

    findDistanceOfTwoPoints();
    return 0;

}