#include<stdio.h>

typedef struct node
{
    int data;
    struct node *next;

}node;

 int main()
 {

 }

void addnode(int data,node **node)
{
    newnode=(node*)malloc(sizeof(node));

    newnode->data=data;
    newnode->next=NULL;

    if(*node==null)
    {
        *node=newnode;
    }
    node *temp=*node;
    while(*node!=NULL)
    {
        temp=temp->next;

    }
    temp->next=newnode;
}
void printdata(node *node)
{

    while(node!=NULL)
    {

        node->data;
        printf("the linked list is%d",data);
        node=node->next;
    }
}
