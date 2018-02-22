#include<stdio.h>

int ara[100];

int main()
{
  int n,i;

  printf("Enter the size of array\n");
  scanf("%d",&n);

  printf("Enter the elements:");

  for(i=0; i<n; i++)
    scanf("%d",&ara[i]);

  merge_sort(ara,0,n-1);

  printf("Sorted array:");

  for(i=0; i<n; i++)
    printf("%4d",ara[i]);

  return 0;
}

int merge_sort(int ara[],int low,int high)
{
  int mid;

  if(low<high) {
    mid=(low+high)/2;
    merge_sort(ara,low,mid);
    merge_sort(ara,mid+1,high);
    merge(ara,low,mid,high);
  }

  return 0;
}

int merge(int ara[],int l,int m,int h)
{
  int arr1[10],arr2[10];
  int n1,n2,i,j,k;

  n1=m-l+1;
  n2=h-m;

  for(i=0; i<n1; i++)
    arr1[i]=ara[l+i];

  for(j=0; j<n2; j++)
    arr2[j]=ara[m+j+1];

  arr1[i]=9999;
  arr2[j]=9999;

  i=0;
  j=0;

  for(k=l; k<=h; k++) {
    if(arr1[i]<=arr2[j])
      ara[k]=arr1[i++];
    else
      ara[k]=arr2[j++];
  }

  return 0;
}
