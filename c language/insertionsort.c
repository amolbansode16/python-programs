#include<stdio.h>


void insertionsort(int arr[],int length){
int i,j,temp;
for(i=0;i<length;i++){
    temp=arr[i];
    j=i-1;
    while(j>=0 && temp<arr[j]){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
}
}
int main(){
int i;
int arr[6]={10,20,30,5,6,1};
printf(" this is :");
insertionsort(arr,6);
for(i=0;i<6;i++)
{

    printf("%d ",arr[i]);
}
return 0;
}

