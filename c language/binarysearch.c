#include<stdio.h>
#include<math.h>
#include<stdlib.h>

 int binarysearch(int arr[],int start,int end,int key){

    if(start<end)
    {
        int mid=ceil(end-start)/2;
        mid=mid+start;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            binarysearch(arr,start,mid,key);
        }
        else{
             binarysearch(arr,mid+1,end,key);
        }
    }else{
    return -1;
    }
}

void main()
{
    int arr[6]={2,4,5,6,8,10};
    printf("element is present at index: %d",binarysearch(arr,0,5,8));
}

