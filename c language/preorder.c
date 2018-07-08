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
                    printf("%d\t",root->data);
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

int isComplete(TNode *root){


        if(root->left==NULL && root->right==NULL){
            return 1;
        }

        if(root->left==NULL || root->right==NULL){
            return 0;
        }

        if(isComplete(root->left)==NULL && isComplete(root->right)==NULL){
            return 1;
        }
        int lh=isComplete(root->left);
        int rh=isComplete(root->right);

        if(lh==rh){
            return 1;
        }

    return 0;
}

int isBalanced(TNode *root){
    if(root==NULL) return 0;

    int lh=height(root->left);
    int rh=height(root->right);

    if(abs(lh-rh)>1)
        return 1;

    return 0;
}

void levelorder(TNode *root){
    Queue *q=createQueue();
    enqueue(&q,root);

    while(!isEmpty(q)){
        root=dequeue(&q);
        printf("%d\t",root->data);
        if(root->left){
            enqueue(&q,root->left);
        }
        if(root->right){
            enqueue(&q,root->right);
        }
    }
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

int rec_sum(TNode *root){
    static int sum=0;
    if(root==NULL){
        return 0;
    }
    sum+=root->data;
    if(root->left)  rec_sum(root->left);
    if(root->right) rec_sum(root->right);
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

void insertBST(TNode **root,int data){
    if((*root)==NULL){
        (*root)=createTNode(data);
        return;
    }

    if((*root)->data > data){
        insertBST(&((*root)->left),data);
    }else{
        insertBST(&((*root)->right),data);
    }
    return;
}

void insertreverseBST(TNode **root,int data){
    if((*root)==NULL){
        (*root)=createTNode(data);
        return;
    }

    if((*root)->data < data){
        insertreverseBST(&((*root)->left),data);
    }else{
        insertreverseBST(&((*root)->right),data);
    }
    return;
}

int isMirror(TNode *root1,TNode *root2){
    if(root1==NULL && root2==NULL){
        return 1;
    }

    if(root1->data==root2->data){
        isMirror(root1->left,root2->right);
        isMirror(root1->right,root2->left);
    }else{
        return 0;
    }
}

int searchBST(TNode *root,int key){
    if(root==NULL){
        return -1;
    }

    if(root->data==key){
        return 1;
    }

    if(root->data>key){
        searchBST(root->left,key);
    }else{
        searchBST(root->right,key);
    }
}

TNode* minBST(TNode *root){
    if(root==NULL){
        return -1;
    }

    if(root->left==NULL){
        return root;
    }else{
        minBST(root->left);
    }
}

TNode* maxBST(TNode *root){
    if(root==NULL){
        return -1;
    }

    if(root->right==NULL){
        return root;
    }else{
        maxBST(root->right);
    }
}

TNode* deleteBST(TNode *root,int key){
    if(root==NULL){
        return root;
    }

    if(root->data>key){
        root->left=deleteBST(root->left,key);
    }

    else if(root->data<key){
        root->right=deleteBST(root->right,key);
    }

    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }

        if(root->right==NULL){
            TNode *temp=root->left;
            free(root);
            return temp;
        }

        if(root->left==NULL){
            TNode *temp=root->right;
            free(root);
            return temp;
        }
        else{
            TNode *min=minBST(root->right);
            root->data=min->data;
            root->right=deleteBST(root->right,min->data);
        }
    }
    return root;
}

int main(){
    TNode *root=NULL;
    TNode *root1=NULL;
    TNode *root2=NULL;
    insertTNode(&root,10);
    insertTNode(&root,20);
    insertTNode(&root,30);
    insertTNode(&root,40);
    insertTNode(&root,50);
    insertTNode(&root,60);
    insertTNode(&root,70);
    insertTNode(&root,80);
    insertTNode(&root,90);
    insertTNode(&root,100);

    printf("\nPreorder is   : \n\t\t");
    preorder(root);
    printf("\n");

    printf("\nInorder is    : \n\t\t");
    inorder(root);
    printf("\n");

    printf("\nPostorder is  : \n\t\t");
    postorder(root);
    printf("\n");

    printf("\nLevelorder is : \n\t\t");
    levelorder(root);
    printf("\n\n");

    printf("\nMax element in the Tree is    :\t %d\n",max(root));
    printf("\nSum of elements is            :\t %d\n",sum(root));
    printf("\nRecursive Sum of elements is  :\t %d\n",rec_sum(root));
    printf("\nHeight of Tree is             :\t %d\n",height(root));

    printf("\nPrint Level                   :\t ");
    printlevel(root,3);
    printf("\n");
    printf("\nSearch                        :\t %d\n",search(root,50));
    printf("\n");
    printf("Print leaves                  : ");
    printleaves(root);
    printf("\n");
    printf("\n");

    printf("Print left                    : ");
    printleft(root);
    printf("\n");
    printf("\n");

    printf("Print right                   : ");
    printright(root);
    printf("\n");
    printf("\n");

    printf("Print boundry                 : ");
    printboundry(root);
    printf("\n");

    printf("\nisComplete                    :\t %d\n",isComplete(root));

    printf("\nisBalanced                    :\t %d\n",isBalanced(root));
    printf("\n");

    insertBST(&root1,40);
    insertBST(&root1,20);
    insertBST(&root1,30);
    insertBST(&root1,60);
    insertBST(&root1,10);
    insertBST(&root1,50);
    insertBST(&root1,70);

    insertreverseBST(&root2,40);
    insertreverseBST(&root2,20);
    insertreverseBST(&root2,30);
    insertreverseBST(&root2,60);
    insertreverseBST(&root2,10);
    insertreverseBST(&root2,50);
    insertreverseBST(&root2,70);

    printf("Trees are mirror trees        :\t %d",isMirror(root1,root2));
    printf("\n");
    printf("\n");

    printf("Is element to be searched present :\t %d",searchBST(root1,100));
    printf("\n");
    printf("\n");

    TNode *tmp=minBST(root1);
    printf("minimum element in tree       :\t %d",tmp->data);
    printf("\n");
    printf("\n");

    TNode *tmp1=maxBST(root1);
    printf("maximum element in tree       :\t %d",tmp1->data);
    printf("\n");
    printf("\n");

    printf("ascending order of BST        : ");
    inorder(root1);
    printf("\n");
    printf("\n");

    printf("Delete Node from BST          :\n");
    printf("\nLevelorder before deleting    : ");
    levelorder(root1);
    printf("\n");
    TNode *get=deleteBST(root1,50);
    printf("\nLevelorder after deleting     : ");
    levelorder(get);
    printf("\n\n");
    return;
}
