#include <iostream>
using namespace std;

int get_sum_of_digits(int user_input)
{
    int temp = user_input;
    int count = 0;
    while(temp > 0)
    {
        count += temp % 10;
        temp /= 10; 
    };
    return count;
}

int main()
{   

    cout << get_sum_of_digits(12345);
    return 0;

}