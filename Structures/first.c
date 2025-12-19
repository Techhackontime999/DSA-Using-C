#include <stdio.h>
#include<string.h>
int main()
{
    // array is use to store collection of similar data items
    // but in c structure is an  user defined data type that store collection of similar or disimilar data items.
    // array
    //  int marks[]={10,20,30,43,35,60};//here all the elements are of same types or category
    //  but we need to store marks,rollno and name of students as a single collection then we use structure in place of array beccause in array we need to  create array for all similar category.
    // declaration of user defined data type structure 
    // struct Student
    // {
    //     int rollno;
    //     int marks;
    //     char name[20];
    // };

    //below is the creation of struct Student data type of object or variables
    // struct Student a;
    // struct Student b;
//we can also directly define structure variale at the time of structure data type creation
struct Student{
    
        int rollno;
        int marks;
        char name[20];
}a,b,c,d;
    a.rollno=01;
    a.marks=70;
    // a.name="suraj";//this getting an error due to assignment of string (which is character array) directly to variable in this declration
    //because when we write char str[6];
    //str="Sohan";//this assignment not possible in other line.do assignment like char str[6]="Sohan";
    strcpy(a.name,"Amit kumar");//good medthod for assigning string to a character array variable outside of declration
    printf("%s\n",a.name);
    printf("%d\n",a.rollno);
    printf("%d\n",a.marks);

       b.rollno=02;
    b.marks=50;
   strcpy(b.name,"Sumit Kumar") ;

printf("%s\n",b.name);
    printf("%d\n",b.rollno);
    printf("%d\n",b.marks);
// direct assiment of one structure variable to other
// like below
c=b;//assign all value of student type of structure and its variable b to c.
d=a;//assign all value of student type of structure and its variable b to c.
printf("%s\n",c.name);
    printf("%d\n",c.rollno);
    printf("%d\n",c.marks);
    printf("%s\n",d.name);
    printf("%d\n",d.rollno);
    printf("%d\n",d.marks);
    return 0;
}