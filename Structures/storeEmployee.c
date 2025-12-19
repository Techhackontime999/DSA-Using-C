#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
int id()
{
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random ID in a specific range, e.g., 1000–9999
    int random_id = rand() % 703873878492900 + 1003834300;

    return random_id;
}
char convertintegertochar(int a)
{
    int askii[10];
    int k = 48;
    for (int i = 0; i < 10; i++)
    {
        askii[i] = k;
        k++;
    }

    return (char)askii[a];
}
int numOfDigits(int num)
{
    int count = 0;
    if (num == 0)
    {
        return 1;
    }

    // num%10;//last digit
    while (num > 0)
    {
        num = num / 10;
        count++;
    }

    return count;
}
char *numInChar(int num, int count)
{

    char *numchar = (char *)malloc((count + 1) * sizeof(char));
    for (int i = count - 1; i >= 0; i--)
    {
        int digit = num % 10;
        numchar[i] = convertintegertochar(digit);
        num = num - num % 10;
        num = num / 10;
    }
    numchar[count] = '\0';
    return numchar;
}
typedef struct Employee
{
    int emp_id;
    char firstname[10];
    char lastname[10];

    char village[20];
    char dob[12];
    float salary;

} Employee;
int main()
{
    time_t currentTime;
    time(&currentTime);
    FILE *ptr = fopen("data.txt", "a");

    fputs("**************************************Employee data ****************************************\n", ptr);
    fputs("Current time: ", ptr);
    fputs(ctime(&currentTime), ptr);
    fputs("\n", ptr);

    fputs(" s.i        Employee_id         Employee_Name         village         D/OB       salary\n", ptr);

    int noemp;
    printf("Enter no of employee: ");
    scanf("%d", &noemp);
    Employee *arr = (Employee *)malloc(noemp * sizeof(Employee));

    printf("Enter Employee  data below .\n");

    int i = 0;
    while (i < noemp)
    {

        printf("\n****************************************\n");
        printf("Enter Employee %d data.\n", i + 1);
        arr[i].emp_id = id();
        printf("Enter first name: ");
        scanf("%s", arr[i].firstname);
        printf("Enter last name: ");
        scanf("%s", arr[i].lastname);
        printf("Enter Village: ");
        scanf("%s", arr[i].village);

        printf("Enter D/O/B: ");
        scanf("%s", arr[i].dob);
        printf("Enter salary: ");
        scanf("%f", &arr[i].salary);
        i++;
    }

    for (int i = 0; i < noemp; i++)
    {
        printf("****************************************\n\n");
        printf("Employee %d .\n", i + 1);
        char *si = numInChar((i + 1), numOfDigits(i + 1));
        fputs("  ", ptr);

        fputs(si, ptr);
        fputs("            ", ptr);
        free(si);
        printf("Employee id: %d \n", arr[i].emp_id);
        char *empid = numInChar(arr[i].emp_id, numOfDigits(arr[i].emp_id));

        fputs(empid, ptr);
        fputs("               ", ptr);

        free(empid);
        printf("Employee name: %s %s\n", arr[i].firstname, arr[i].lastname);
        char *namestr = (char *)malloc(20 * sizeof(char));

        strcat(namestr, arr[i].firstname);
        strcat(namestr, " ");

        strcat(namestr, arr[i].lastname);
        fputs(namestr, ptr);
        fputs("                   ", ptr);

        free(namestr);

        printf("Employee village: %s \n", arr[i].village);
        fputs(arr[i].village, ptr);
        fputs("              ", ptr);

        printf("Employee D/O/B: %s \n", arr[i].dob);
        fputs(arr[i].dob, ptr);
        fputs("                  ", ptr);

        printf("Employee salary: %f \n", (int)arr[i].salary);
        char *salary = numInChar((int)arr[i].salary, numOfDigits((int)arr[i].salary));

        fputs(salary, ptr);
        free(salary);
        fputs("\n", ptr);
    }
    fclose(ptr);

    free(arr);
    return 0;
}
