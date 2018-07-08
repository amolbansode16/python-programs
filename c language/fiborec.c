#include<stdio.h>

void fibo(int n1,int n2,int n3,int n)
{

    printf("%d",n1);
     fibo(0,1,0,10);
    n3=n2+n1;
    n1=n2;
    n2=n3;


}
void main(){
int n1,n2,n3,n,i;
fibo(0,1,0,10);
for(i=0;i<=n;i++){
printf("%d",n1);
}
}
