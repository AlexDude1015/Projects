#include "swap_header.hpp"

//Swaps two values; accepts two int pointers arguments
void swap::swap_values(int* first_value, int* second_value)
{
    int placeholder = *first_value;
    *first_value = *second_value;
    *second_value = placeholder;
}