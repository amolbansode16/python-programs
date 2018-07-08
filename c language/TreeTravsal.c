#include<stdio.h>
#include<stdlib.h>

typedef struct SNode{
    void *sdata;
    struct SNode *next;
}SNode;

typedef struct QNode{
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

SNode *createSNode(void *sdata){
    SNode *snode=(SNode *)malloc(sizeof(SNode));
    snode->sdata=sdata;
    snode->next=NULL;
    return snode;
}

QNode *createQNode(void *data){
    QNode *qnode=(QNode *)malloc(sizeof(QNode));
    qnode->data=data;
    qnode->next=NULL;
    return qnode;
}

Queue *createQueue(){
    Queue *q=(Queue *)malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

void enqueue(Queue **q,void *data){
    QNode *qnode=createQNode(data);
    if((*q)->front==NULL){
        (*q)->front=qnode;
        (*q)->rear=qnode;
        return;
    }
    (*q)->rear->next=qnode;
    (*q)->rear=qnode;
}

void *dequeue(Queue **q){
    if(!(*q)->front){
        return;
    }

    void *data=(*q)->front->data;
    QNode *temp=(*q)->front;

    (*q)->front=(*q)->front->next;
    free(temp);

    if((*q)->front==NULL){
        (*q)->rear=NULL;
    }
    return data;
}

int isEmpty(Queue *q){
    return q->front==NULL;
}

void deleteQueue(Queue **q){
    while(!isEmpty(*q)){
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

    if(!*root){
        *root=tnode;
        return;
    }

    enqueue(&q,*root);
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

void push(SNode **top, void *sdata){

    SNode *newNode = (SNode *)malloc(sizeof(SNode));


    newNode->sdata = sdata;
    newNode->next = *top;
    *top = newNode;

}

void *pop(SNode **top){
    if(*top==NULL)
        return NULL;

    void *sdata=(*top)->sdata;
    SNode *temp = *top;
    *top = (*top)->next;
    free(temp);
    return sdata;
}


void preorder(TNode *root){
    SNode *s=NULL;
    while(root){
        printf("%d\t",root->data);

        if(root->right!=NULL){
            push(&s,root->right);

        }
        if(root->left!=NULL){
            root=root->left;
        }
        else{
            root=(TNode *)pop(&s);
        }
    }
}

void inorder(TNode *root){

    SNode *s = NULL;
  Repeat: while (root){

                push(&s, root);
                root = root->left;
            }
            root=pop(&s);
            while(root){
                    printf("\t%d",root->data);
                    if (root->right!=NULL){
                       root=root->right;
                        goto Repeat;
                    }
                    else{
                        root=pop(&s);
                    }
            }

}


void postorder(TNode *root){

    SNode *s1=NULL;
    SNode *s2=NULL;

    while(root){

        push(&s1,root);
        if(root->left)
            push(&s2,root->left);
        if(root->right)
            push(&s2,root->right);
        root=pop(&s2);
    }
    while(s1!=NULL){
        TNode *temp=pop(&s1);
        printf("%d \t",temp->data);
    }

}

int main(){
    TNode *root=NULL;
    insertTNode(&root,10);
    insertTNode(&root,20);
    insertTNode(&root,30);
    insertTNode(&root,40);
    insertTNode(&root,50);
    insertTNode(&root,60);
    insertTNode(&root,70);
    insertTNode(&root,80);

    printf("\nPreorder is : ");
    preorder(root);

    printf("\nInorder is : ");
    inorder(root);

    printf("\nPostorder is : ");
    postorder(root);

    return;
}
