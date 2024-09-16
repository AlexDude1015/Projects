//Outputs a 2x2 matrix of courses and student scores
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Title
    cout << setw(15) << left << "Course" << setw(10) << left << "Student" << endl;
    //Content
    cout << setw(15) << left << "C++" << setw(10) << right << "100" << endl;
    cout << setw(15) << left << "Javascript" << setw(10) << right << "50" << endl;
    return 0;
}