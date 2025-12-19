// union is same as structure but at a time we can use only one
#include <stdio.h>
struct Result
{
    int roll_no;

    char *name;
    int percentage;
};
union Student
{
    long roll_no;

    char *name;
    int percentage;
};

int main()
{
    // struct Result student;
    // student.roll_no=01;
    // student.name = "sumit";
    // student.percentage=85;
    // printf("%d\n",student.roll_no);
    // printf("%s\n",student.name);
    // printf("%d\n",student.percentage);
    union Student student;
    // student.percentage = 90;
    // student.roll_no = 01;
    student.name = "sumit";

    // printf("%d\n", student.percentage);
    printf("%s\n", student.name);
    // printf("%ld\n", student.roll_no);

    return 0;
}