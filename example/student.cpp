#include "student.h"
Student::Student()
{
    std::cout << "Student is " << std::endl;
}
void Student::SName()
{
    std::cout << "DZ" << std::endl;
}
void Student::DoSomething(char *name)
{
    std::cout << "DZ  " << name << std::endl;
}
Student::~Student()
{

    std::cout << "DZ deleted" << std::endl;
}
