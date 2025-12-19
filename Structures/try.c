#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 2;
    int *ptr = NULL;
    *ptr = a;
    printf("%d", *ptr);

    return 0;
}