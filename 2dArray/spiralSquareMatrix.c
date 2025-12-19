#include<stdio.h>
int main(){
    // we need to create a square matrix nxn which contain element 1 to nxn in spiral order
   //n=3  elements in square matrix is 1 to 9
   // 1 2 3
   // 8 9 4
   // 7 6 5
   int n;
printf("Enter Positive integer n: ");
scanf("%d",&n);
   int tne = n*n;
    int minr = 0;
    int maxr = n - 1;
    int maxcol = n - 1;
    int mincol = 0;
    int count = 0;
int arr[n][n];
    while (count < tne)
    {
        // printing minimum row
        for (int j = mincol; j <= maxcol; j++)
        {
            arr[minr][j]=count+1;
            count++;
        }
        minr++;
        // printing maximum column
        for (int i = minr; i <= maxr; i++)
        {
            arr[i][maxcol]=count+1;

            count++;
        }
        maxcol--;
        // printing maximum row
        for (int j = maxcol; j >= mincol; j--)
        {
            arr[maxr][j]=count+1;

            count++;
        }
        maxr--;
        // printing minimum column
        for (int i = maxr; i >= minr; i--)
        {
            arr[i][mincol]=count+1;

            count++;
        }
        mincol++;
    }

    // spiral matrix creationend
    printf("Sqare matrix of 1 to %d element arranged in spiral manner...\n",tne);
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
       printf("  %d  ",arr[i][j]);
    }
    printf("\n");
}


    return 0;
}