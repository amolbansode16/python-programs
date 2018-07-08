#include<stdio.h>
#include<stdlib.h>

void selectionsort(int arr[],int length){
int i,j;
printf("selection sort");
for(i=0;i<length;i++){
   int minindex=i;
   for(j=i+1;j<length;j++)
   {
       if(arr[minindex]>arr[j]){
        minindex=j;
       }
       swap(&arr[minindex],&arr[i]);
   }
}
}
void swap(int *one,int *two){
int temp=*one;
*one=*two;
*two=temp;
}
