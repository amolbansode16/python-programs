#include<stdio.h>

int main(){
int i;
int arr[6]={10,20,30,5,6,1};
printf(" this is :");
quicksort(arr,0,6);
for(i=0;i<6;i++)
{

    printf("%d ",arr[i]);
}
return 0;
}
void swap(int *one,int *two)
{
  int temp=*one;
  *one=*two;
  *two=temp;

}
int partition(int arr[],int l,int h){
int i,j;
int pivot=arr[l];
i=l;
j=h;
while(i<j){
  do{
    i++;
  }  while(arr[i]<pivot);
  do{
    j--;
  }while(arr[j]>pivot);
  if(i<j)
    swap(&arr[i],&arr[j]);
    else
    swap(&arr[j],pivot);

return j;
}
}
void quicksort(int arr,int l,int h){
if(l<h){
    int j=partition(arr,l,h);
    quicksort(arr,l,j-1);
    quicksort(arr,j+1,h);
}
}
