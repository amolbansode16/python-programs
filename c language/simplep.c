#include<stdio.h>
void main()
{
    //printf("i am in c program");

    int i,j,n;


    printf("how many element u want to enter array element \n ");
    scanf("%d",&n);
    printf("enter %d elements \n",n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("the resulting array is  : ");
    for(j=0;j<n;j++)
    {
        printf("%d",arr[j]);
    }
}
