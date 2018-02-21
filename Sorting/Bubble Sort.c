#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int num, int *ara);

int main()
{
    int num, *ara, *reset, i;

    printf("How many number: ");
    scanf("%d", &num);
    printf("Enter number: ");

    ara = malloc(sizeof(int) * num);
    reset = ara;

    for(i = 0; i < num; i++)
    {
        scanf("%d",ara++);
    }

    ara = reset;

    bubbleSort(num, ara);

    printf("Sorted Array: ");

    for(i = 0; i < num; i++)
    {
        printf("%d ", ara[i]);
    }

    return 0;
}

void bubbleSort(int num, int *ara)
{
    int i, pass, temp;

    for(pass = 1; pass < num; pass++)
    {
        for(i = 0; i < num-1; i++)
        {
            if(ara[i] > ara[i+1])
            {
                temp = ara[i];
                ara[i] = ara[i+1];
                ara[i+1] = temp;
            }
        }
    }
}
