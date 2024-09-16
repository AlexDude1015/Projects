//Finds the size and limits of short and double on my machine
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

int main()
{
    //Outputs size and limit of a short
    cout << "Short size: " << sizeof(short) << " bytes " << endl;
    cout << "Short limit: " << numeric_limits<short> :: min() << " to " << numeric_limits<short> :: max() << endl;
    //Outputs size and limits of a double
    cout << "Double size: " << sizeof(double) << " bytes " << endl;
    cout << "Double limit: " << numeric_limits<double> :: min() << " to " << numeric_limits<double> :: max() << endl;
    return 0;
}