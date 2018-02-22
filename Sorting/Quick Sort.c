#include <stdio.h>

int main()
{
    int ara[100], len, i;

    printf("Enter the size of the array: ");
    scanf("%d", &len);

    printf("Enter the elements of the array: ");

    for(i = 0;i < len; i++)
    {
        scanf("%d", &ara[i]);
    }

    quickSort(ara, 0, len-1);

    printf("Sorted array: ");

    for(i = 0; i < len; i++)
    {
        printf("%4d", ara[i]);
    }

    return 0;
}

quickSort(int *ara, int beg, int end)
{
    int pivot, i, j, temp;

    if(beg < end)
    {
        pivot = beg;
        i = beg;
        j = end;

        while(i < j)
        {
            while(ara[i] <= ara[pivot] && i <= end)
            {
                i++;
            }

            while(ara[j] > ara[pivot] && j >= beg)
            {
                j--;
            }

            if(i < j)
            {
                temp = ara[i];
                ara[i] = ara[j];
                ara[j] = temp;
            }
        }

        temp = ara[j];
        ara[j] = ara[pivot];
        ara[pivot] = temp;

        quickSort(ara, beg, j-1);
        quickSort(ara, j+1, end);
    }
}
