#include <stdio.h>
#include <string.h>
int betidx(char str[], int size)
{
    int idx;
    int len = size;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            idx = i;
            return idx;
            break;
        }
    }
}
void insertSpaceAtIdx(char str[], int size)
{
    int len = size;
    for (int i = len; i > betidx(str, len) + 1; i--)
    {
        str[i] = str[i - 1];
    }
    str[betidx(str, len) + 1] = ' ';

    return;
}
void addHalfSpaceAtBothEnd(char str[], int size, int halfspace)
{
    int len = size;
    for (int i = len; i >= 0; i--)
    {
        str[i + halfspace] = str[i];
    }
    for (int i = 0; i < halfspace; i++)
    {
        str[i] = ' ';
    }

    return;
}
void inBetweenString(char str[], int size, int strsize)
{
    // str[strsize - 1] = str[len]; // first shift null character at end
    int len = size;
    int spaceempty = strsize - len - 1;
    int halfspace = spaceempty / 2;
    if (spaceempty % 2 == 0)
    {
        addHalfSpaceAtBothEnd(str, len, halfspace);
        // this below line add spaces at end
        for (int i = strsize - 2; i >= strsize - 1 - halfspace; i--)
        {
            str[i] = ' ';
        }
    }
    else
    {
        insertSpaceAtIdx(str, len);
        addHalfSpaceAtBothEnd(str, len, halfspace);
        // this below line add spaces at end
        for (int i = strsize - 2; i >= strsize - 1 - halfspace; i--)
        {
            str[i] = ' ';
        }
    }
    return;
}
int main(int argc, char const *argv[])
{
    int strsize = 16;

    struct Student
    {
        int rollno;
        char name[16];
        int marks[5];

        int total;
        float percentage;
    };
    struct Student a;
    struct Student b;
    struct Student c;
    struct Student d;
    a.rollno = 01;
    char str[16] = "Amit kumar";
    int len = strlen(str); // store this len for further reference
    inBetweenString(str, len, strsize);

    strcpy(a.name, str);
    // int arr[3];
    // arr[3]={1,2,3};//this also giving error because this declration is define in the same line only i.e int arr[3]={1,2,3}
    // show below declration also give error
    // a.marks[]={1,2,3};
    // correct declration of marks in array given below
    a.marks[0] = 20;
    a.marks[1] = 50;
    a.marks[2] = 70;
    a.marks[3] = 40;
    a.marks[4] = 60;

    a.total = a.marks[0] + a.marks[1] + a.marks[2] + a.marks[3] + a.marks[4];
    a.percentage = (a.total * 100) / 500;

    b.rollno = 02;
    char str1[16] = "Surajesh kumar";
    len = strlen(str1); // store this len for further reference
    inBetweenString(str1, len, strsize);
    strcpy(b.name, str1);
    b.marks[0] = 30;
    b.marks[1] = 55;
    b.marks[2] = 40;
    b.marks[3] = 40;
    b.marks[4] = 30;
    b.total = b.marks[0] + b.marks[1] + b.marks[2] + b.marks[3] + b.marks[4];
    b.percentage = (b.total * 100) / 500;


    c.rollno = 03;
    char str2[16] = "mahendra kumar";
    len = strlen(str2); // store this len for further reference
    inBetweenString(str2, len, strsize);
    strcpy(c.name, str2);
    c.marks[0] = 30;
    c.marks[1] = 55;
    c.marks[2] = 40;
    c.marks[3] = 40;
    c.marks[4] = 30;
    c.total = c.marks[0] + c.marks[1] + c.marks[2] + c.marks[3] + c.marks[4];
    c.percentage = (c.total * 100) / 500;

    d.rollno = 04;
    char str3[16] = "Ram kumar";
    len = strlen(str3); // store this len for further reference
    inBetweenString(str3, len, strsize);
    strcpy(d.name, str3);
    d.marks[0] = 30;
    d.marks[1] = 55;
    d.marks[2] = 40;
    d.marks[3] = 40;
    d.marks[4] = 30;
    d.total = d.marks[0] + d.marks[1] + d.marks[2] + d.marks[3] + d.marks[4];
    d.percentage = (d.total * 100) / 500;


    printf("Roll no       Name        Physics  chemistry  Math  science  social.science  total marks  percentage \n");
    printf(" %d      %s     %d        %d       %d     %d          %d             %d       %f\n", a.rollno, a.name, a.marks[0], a.marks[1], a.marks[2], a.marks[3], a.marks[4], a.total, a.percentage);
    printf(" %d      %s     %d        %d       %d     %d          %d             %d       %f\n", b.rollno, b.name, b.marks[0], b.marks[1], b.marks[2], b.marks[3], b.marks[4], b.total, b.percentage);
    printf(" %d      %s     %d        %d       %d     %d          %d             %d       %f\n", c.rollno, c.name, c.marks[0], c.marks[1], c.marks[2], c.marks[3], c.marks[4], c.total, c.percentage);
    printf(" %d      %s     %d        %d       %d     %d          %d             %d       %f\n", d.rollno, d.name, d.marks[0], d.marks[1], d.marks[2], d.marks[3], d.marks[4], d.total, d.percentage);



    return 0;
}
