#include <string>
#include <iostream>
#include "grade.hpp"

//Returns an array's largest value
int grade::get_highest_number(int scores[], int array_size)
{
    int highest_score = 0;
    for (int i = 0; i < array_size; i++)
    {
        if (scores[i] > highest_score)
        {
            highest_score = scores[i];
        }
    }
    return highest_score;
}

//Returns an array's smallest value
int grade::get_lowest_number(int scores[], int array_size)
{
    int lowest_score = 100;
    for (int i = 0; i < array_size; i++)
    {
        if (scores[i] < lowest_score)
        {
            lowest_score = scores[i];
        }
    }
    return lowest_score;
}

void grade::print_above_average_students(int scores[], std::string names[], int array_size)
{
    //Calculate Average
    int average_score = 0;
    for (int i = 0; i < array_size; i++)
    {
        average_score += scores[i];
    }
    average_score /= array_size;

    //prints student names
    for (int i = 0; i < array_size; i++)
    {
        if (scores[i] > average_score)
        {
            std::cout << names[i] << " ";
        }
    }
    std::cout << "\n";
}

void grade::compare_all_student_grades(int scores[], std::string names[], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        std::cout << names[i] << ": " << scores[i] << std::endl;
    }
}