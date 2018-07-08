#include<stdio.h>
#include<stdlib.h>

typedef struct Qnode{
void *data;
struct QNode *next;
}QNode;

typedef struct Queue{
QNode *front,*rear;
}Queue;

typedef struct TNode{
int data;
struct TNode *left,*right;
}TNode;

QNode *createQNode(void *data){

QNode *qnode=(QNode*)malloc(sizeof(QNode));
qnode->data=data;
qnode->next=NULL;
return qnode;
}

Queue *createQueue(){
Queue *q=(Queue*)malloc (sizeof (Queue));
q->front=NULL;
q->rear=NULL;
return q;
}

void enqueue(Queue **q,void *data){
QNode *qnode=createQNode(data);
if((*q)->front==NULL)
{


    (*q)->front=qnode;
    (*q)->rear=qnode;
    return;
}

(*q)->rear->next=qnode;
(*q)->rear=qnode;
}


void *dequeue(Queue **q)
{

    if(!(*q)->front){
        return;
    }
    void *data=(*q)->front->data;
    QNode *temp=(*q)->front;

    (*q)->front=(*q)->front->next;
    free (temp);

    if((*q)->front==NULL)
    {
        (*q)->rear=NULL;
    }
    return data;
}

int isEmpty(Queue *q){
return q->front==NULL;
}

void deleteQueue(Queue **q){
while(!isEmpty(*q))
    {

        QNode *temp=(*q)->front;
        (*q)->front=(*q)->front->next;
        free(temp);
    }
}

TNode *createTNode(int data){
TNode *tnode=(TNode*)malloc(sizeof(TNode));
tnode->data=data;
tnode->left=NULL;
tnode->right=NULL;
return tnode;
}


void insertTNode(TNode **root,int data){
Queue *q=createQueue();
TNode *tnode=createTNode(data);
if(!*root)
    {

        *root=tnode;
        return;
    }

    enqueue(&q ,*root);
    while(!isEmpty(q)){
        TNode *temp=dequeue(&q);
        if(!temp->left){
            temp->left=tnode;
            deleteQueue(&q);
            return;
        }
        else
            enqueue(&q,temp->left);

        if(!temp->right){
            temp->right=tnode;
            deleteQueue(&q);
            return;
        }
        else
            enqueue(&q,temp->right);

    }
}

void preorder(TNode *root)
{

    if(!root)
        return;
    printf("%d \t",root->data);
    preorder(root->left);
    preorder(root->right);

}

void inorder(TNode *root)
{

    if(!root)
        return;

    preorder(root->left);
     printf("%d \t",root->data);
    preorder(root->right);

}



void postorder(TNode *root)
{

    if(!root)
        return;

    preorder(root->left);
    preorder(root->right);
     printf("%d \t",root->data);

}


int main()
         {
          TNode *root=NULL;
          insertTNode(&root,10);
          insertTNode(&root,20);
          insertTNode(&root,30);
          insertTNode(&root,40);
          insertTNode(&root,50);
          insertTNode(&root,60);
          insertTNode(&root,70);
          printf("preorder is \n");
          preorder(root);
          printf("inorder is \n");
          inorder(root);
          printf("postorder is \n");
          postorder(root);
          return;

         }





