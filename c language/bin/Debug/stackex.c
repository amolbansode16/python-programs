#include<stdio.h>

typedef struct node
{

    int data;
    struct node *next;

}node;

int main()
{
    node firstnode;
    node secondnode;
    firstnode.data=10;
    secondnode.data=20;
    printf("the first node %d",node);
}
