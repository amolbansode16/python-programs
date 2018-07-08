#include<stdio.h>

int main(){
int i;
int arr[]={10,20,30,5,6,1};
printf(" this is :");
mergesort(arr,0,5);
for(i=0;i<6;i++)
{

    printf("%d ",arr[i]);
}
return 0;
}


void merge(int arr[],int i1,int j1,int i2,int j2){
    int t=j2-i1+1;
    int temp[t];
    int i=i1;
    int j=i2;
    int k=0;
    while(i<=j1&&j<=j2){
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];

    }
    while(j<=j2){
        temp[k++]=arr[j++];
    }
        while(i<=j1){
            temp[k++]=arr[i++];
        }

        for(i=i1,j=0;i<=j2;i++,j++)
        {
            arr[i]=temp[j];
        }
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=(r+l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,m+1,r);
    }
}
