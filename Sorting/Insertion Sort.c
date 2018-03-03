#include <stdio.h>
#include <stdlib.h>

void insertionSort(int len, int *ara);

int main()
{
    int len, *ara, *reset, i;

    printf("How many number: ");
    scanf("%d", &len);
    printf("Enter number: ");

    ara = malloc(sizeof(int) * len);
    reset = ara;

    for(i = 0; i < len; i++)
    {
        scanf("%d",ara++);
    }

    ara = reset;

    insertionSort(len, ara);

    printf("Sorted Array: ");

    for(i = 0; i < len; i++)
    {
        printf("%4d ", ara[i]);
    }

    return 0;
}

void insertionSort(int len, int *ara)
{
    int pass, i, temp;

    for(pass = 1; pass <= len - 1; pass++)
    {
        i = pass;

        while(i > 0 && ara[i-1] > ara[i])
        {
            temp = ara[i];
            ara[i] = ara[i-1];
            ara[i-1] = temp;

            i--;
        }
    }
}
