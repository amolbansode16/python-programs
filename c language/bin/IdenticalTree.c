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



int max(TNode *root){
    if(root==NULL){
        return 0;
    }
    int maxroot=root->data;
    int maxL=max(root->left);
    int maxR=max(root->right);
    return maxroot>maxL?(maxroot>maxR?maxroot:maxR):(maxL>maxR?maxL:maxR);;
}

int sum(TNode *root){
    Queue *q=createQueue();
    enqueue(&q,root);
    int sum=0;
    while(!isEmpty(q)){
        root=dequeue(&q);
        sum+=root->data;

        if(root->left){
            enqueue(&q,root->left);
        }
        if(root->right){
            enqueue(&q,root->right);
        }
    }
    return sum;
}


int height(TNode *root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);

    return lh>rh?lh+1:rh+1;
}

void printlevel(TNode *root,int level){
    if(root==NULL) return;

    if(level==1){
        printf("%d\t",root->data);
        return;
    }else{
        printlevel(root->left,level-1);
        printlevel(root->right,level-1);
    }
}

int search(TNode *root,int key){
    if(root==NULL) return 0;

    if(root->data==key) return 1;

    return (search(root->left,key)||search(root->right,key));
}

void printleaves(TNode *root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        printf("%d\t",root->data);
    }
    printleaves(root->left);
    printleaves(root->right);
}

void printleft(TNode *root){
    if(root){
        if(root->left){
            printf("%d\t",root->data);
            printleft(root->left);
        }
    }
    return;
}

void printright(TNode *root){
    if(root){
        if(root->right){
            printright(root->right);
            printf("%d\t",root->data);
        }
    }
    return;
}

void printboundry(TNode *root){
    printf("%d\t",root->data);
    if(root){
        printleft(root->left);
        printleaves(root);
        printright(root->right);
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
    insertTNode(&root,90);
    //insertTNode(&root,100);



`   printf("\nMax element in the Tree is    :\t %d\n",max(root));
    printf("\nSum of elements is            :\t %d\n",sum(root));
    printf("\nHeight of Tree is             :\t %d\n",height(root));

    printf("\nPrint Level                   :\t ");
    printlevel(root,3);
    printf("\n");

    printf("\nSearch                        :\t %d\n",search(root,50));
    printf("\n");
    printf("Print leaves                  : ");
    printleaves(root);
    printf("\n");

    printf("Print left                    : ");
    printleft(root);
    printf("\n");

    printf("Print right                   : ");
    printright(root);
    printf("\n");

    printf("Print boundry                 : ");
    printboundry(root);
    printf("\n");

}
