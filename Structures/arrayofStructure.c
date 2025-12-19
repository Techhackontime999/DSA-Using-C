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
// structure is passed to a function by call by value not call by reference
// i.e when we pass a structure variable to a function then it is passed as a noramal value not address then it can't able to change the actual structture variable value.
int main()
{
    typedef struct Student
    {
        int rollno;
        char name[20];

        int marks[5];

        int total;
        float percentage;
    } Student;
    // integer array
    // int arr[10];
    // arr[0]=1;
    // arr[1]=2
    // structure array
    int n;
    printf("Enter no of student: ");
    scanf("%d", &n);
    Student arr[n];
    for (int i = 0; i < n; i++)
    {
        printf(".............Roll-no. %d ............................\n", i + 1);

        arr[i].rollno = i + 1;
        // arr[i].name="rakesh";//wrong declaration
        char str1[20];
        

        printf("\nEnter first name: ");
        scanf("%s", str1);
        strcat(str1, " ");
        int x=strlen(str1);
        char str2[20-x] ;

        printf("Enter last name: ");
        scanf("%s", str2);

        strcat(str1, str2);
        int len = strlen(str1);
        inBetweenString(str1, len, 20);
        strcpy(arr[i].name, str1);

        arr[i].total = 0;
        for (int j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                printf("Enter Physics marks: ");
            }
            else if (j == 1)
            {
                printf("Enter Chemistry marks: ");
            }
            else if (j == 2)
            {
                printf("Enter Math marks: ");
            }
            else if (j == 3)
            {
                printf("Enter SocialScience marks: ");
            }
            else
            {
                printf("Enter Science marks: ");
            }

            scanf("%d", &arr[i].marks[j]);
            arr[i].total = arr[i].total + arr[i].marks[j];
        }
        arr[i].percentage = (arr[i].total * 100) / 500;
    }

    // printing the element
    printf("Roll no    Student Name      Physics  chemistry  Math  science  social.science  total marks  percentage \n");


    for (int i = 0; i < n; i++)
    {
        printf(" %d      %s     %d        %d       %d     %d          %d             %d       %f\n", arr[i].rollno, arr[i].name, arr[i].marks[0], arr[i].marks[1], arr[i].marks[2], arr[i].marks[3], arr[i].marks[4], arr[i].total, arr[i].percentage);
    }

    return 0;
}