#include "student.h"
extern "C"
{
#include "loadHelper.h"
}
void *NewStudent()
{
    return (void *)new Student();
}
void SName(void *student)
{
    ((Student *)student)->SName();
}
void DoSomething(void *student, char *name)
{
    ((Student *)student)->DoSomething(name);
}
void DeleteStudent(void *student)
{
    delete (Student *)student;
}