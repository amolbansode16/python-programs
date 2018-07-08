#include<stdio.h>
#include<stdlib.h>

int binarysearch(int arr[],int start,int end,int key){
    printf("i am in binary search program");
if(start<end)
    {

        int mid=ceil(end-start)/2;
        if(arr[mid]==key){
            return mid;
            if(arr[mid]>key){
                binarysearch(arr,start,mid,key);
            }
            else{
                binarysearch(arr,mid+1,end,key);
            }
            }return -1;
        }
}


