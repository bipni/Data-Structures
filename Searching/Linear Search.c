#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *ara, int key, int len);

int main()
{
    int *ara, *reset, key, pos, len, i;

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

    printf("Enter search key: ");
    scanf("%d", &key);

    pos = linearSearch(ara, key, len);

    if(pos == -1)
        printf("The search key is not in the array\n");
    else
        printf("The search key %d is at location %d\n", key, pos);

    return 0;
}

int linearSearch(int *ara, int key, int len)
{
    int i;

    for(i = 0; i < len; i++)
    {
        if(*ara++ == key)
            return i+1;
    }
    return -1;
}
