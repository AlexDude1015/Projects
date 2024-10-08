#include "swap_header.hpp"

//Swaps the values in two pointers
void swap::swap_values(int* first_value, int* second_value)
{
    int placeholder = *first_value;
    *first_value = *second_value;
    *second_value = placeholder;
}