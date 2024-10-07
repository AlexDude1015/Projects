#include <iostream>

int find_target(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if ( arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int target = 13;
    std::cout << "The target found is " <<  find_target(arr, 10, target);
    return 0;
}