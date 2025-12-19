#include <stdio.h>
int main()
{
    int student;
    printf("Enter number of students: ");
    scanf("%d", &student);
    int arr[student][3 + 1];
    for (int i = 0; i < student; i++)
    {
        printf("Enter Roll no: %d marks : ", i + 1);

        for (int j = 0; j < 3 + 1; j++)
        {
            if (j == 0)
            {
                arr[i][j] = i + 1;
            }
            else if (j == 1)
            {
                printf("\nEnter Physics Marks: ");
            }
            else if (j == 2)
            {
                printf("Enter chemistry Marks: ");
            }
            else
            {
                printf("Enter Math Marks: ");
            }

            if (j != 0)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        printf("\n");
    }
    printf("Roll-no  Physics  chemisty   Math.\n");

    for (int i = 0; i < student; i++)
    {

        for (int j = 0; j < 3 + 1; j++)
        {
            if (j == 0)
            {
                printf(" %d ", arr[i][0]);
            }
            else
            {
                printf("      %d    ", arr[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}