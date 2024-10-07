#include <iostream>
using namespace std;

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}

void bubble_sort(int arr[], int size)
{
    //Passes
    for (int i = 0; i < size; i++)
    {
        print_array(arr, size);
        //Each pass
        for (int j = 0; j < (size - 1 - i); j++)
        {
            if (arr[j] > arr[j+1])
            {
                int placeholder = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = placeholder;
            }
        }
    }
    print_array(arr, size);
}

int main()
{
    int arr[] = {10,9,1,3,7,12,7,2,0,11};
    bubble_sort(arr, 10);
    return 0;
}