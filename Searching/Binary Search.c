#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *ara, int key, int len);
void bubbleSort(int len, int *ara);

int main()
{
    int len, *ara, *reset, i, key, pos;

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

    bubbleSort(len, ara);

    printf("Sorted Array: ");

    for(i = 0; i < len; i++)
    {
        printf("%4d ", ara[i]);
    }

    printf("\nEnter search key: ");
    scanf("%d", &key);

    pos = binarySearch(ara, key, len);

    if(pos == -1)
        printf("The search key is not in the array\n");
    else
        printf("The search key %d is at location %d\n", key, pos);

    return 0;
}

int binarySearch(int *ara, int key, int len)
{
    int low = 0, high = len-1, middle;

    while(low <= high)
    {
        middle = (low+high)/2;

        if(key == ara[middle])
            return middle+1;
        else if(key < ara[middle])
            high = middle-1;
        else
            low = middle+1;
    }

    return -1;
}

void bubbleSort(int len, int *ara)
{
    int i, pass, temp;

    for(pass = 1; pass < len; pass++)
    {
        for(i = 0; i < len-1; i++)
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

