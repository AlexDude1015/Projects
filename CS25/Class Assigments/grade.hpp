#ifndef GRADE_HPP
#define GRADE_HPP

#include <string>

namespace grade
{
    int get_highest_number(int scores[], int array_size);
    int get_lowest_number(int scores[], int array_size);
    void print_above_average_students(int scores[], std::string names[], int array_size);
    void compare_all_student_grades(int scores[], std::string names[], int array_size);
}

#endif