#include<stdio.h>
#include<stdlib.h>

typedef struct SNode{
void *sdata;
struct SNOde *next;
}SNode;

typedef struct QNode{
void *data;
struct QNode *next;
}QNode;

SNode *createSNode(void *Sdata){
    SNode *snode=(SNode *}malloc(sizeof(SNode));
    snode->data=data;
    qnode->next=NULL;
    return snode;
}
QNode *createQNode(void *data){
    QNode *qnode=(QNode *)malloc(sizeof(QNode));
    qnode->data=data;
    qnode->next=NULL;
    return qnode;
}
