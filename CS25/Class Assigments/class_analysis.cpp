#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

namespace grade
{
    std::vector<std::string> name;
    std::vector<int> score;

    void get_grade(std::vector<std::string> &student_names, std::vector<int> &student_grades)
    {
        char yes = 'n';
        do 
        {
            std::string name;
            int grade;
            std::cout << "Please enter the student's name: ";
            std::cin >> name;
            student_names.push_back(name);

            std::cout << "\nPlease enter the student's grade: ";
            std::cin >> grade;
            student_grades.push_back(grade);

            std::cout << "\n";
            std::cout << "Would you like to add another student? (y/n)";
            std::cin >> yes;
            std::cout << "\n";
        }
        while (yes == 'y');
    }

    double get_average(std::vector<int> &student_grades)
    {
        int total = 0;
        for (int i = 0; i < student_grades.size(); i ++)
        {
            total = total + i;
        }
        return total / student_grades.size();
    }

    int get_highest_grade(std::vector<int> &student_grades)
    {
        int highest_grade = student_grades[0];
        for (int i = 0; i < student_grades.size(); i ++)
        {
            if (student_grades[i] > highest_grade)
            {
                highest_grade = student_grades[i];
            }
        }
        return highest_grade;
    }

    int get_lowest_grade(std::vector<int> &student_grades)
    {
        int lowest_grade = student_grades[0];
        for (int i = 0; i < student_grades.size(); i ++)
        {
            if (student_grades[i] < lowest_grade)
            {
                lowest_grade = student_grades[i];
            }
        }
        return lowest_grade;
    }

    void print_above_average_students(std::vector<std::string> &student_names, std::vector<int> &student_grades)
    {
        double class_average = get_average(student_grades);
        std::cout << "Above average students: \n";
        for (int i = 0; i < student_grades.size(); i++)
        {
            if (student_grades[i] > class_average)
            {
                std::cout << student_names[i] << std::endl;
            }
        }
    }

    void compare_students(std::vector<std::string> &student_names, std::vector<int> &student_grades)
    {
        std::cout << std::left << std::setw(10) << "Name:" << std::left << std::setw(10) << "Grade:\n";

        for (int i = 0; i < student_names.size(); i++)
        {
            std::cout << std::left << std::setw(10) << student_names[i] << std::left << std::setw(10) << student_grades[i] << "\n";         
        }
    }

}

int main()
{   
    grade::get_grade(grade::name, grade::score);
    return 0;
}
