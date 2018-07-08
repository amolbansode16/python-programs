#include<stdio.h>
#include<malloc.h>
typedef struct Cards{
char cardname;
struct cards *nextcard;
}Card;
void addcard(Card **usercard,char cardname);
void displaycard(Card *dis);

int main()
{
    Card *p1=NULL;

    addcard(&p1,'a');
    addcard(&p1,'b');
    addcard(&p1,'c');
    displaycard(p1);
    return 0;

}
void addcard(Card **usercard,char cardname)
{
    Card *card=(Card*) malloc(sizeof(Card));
    card->cardname=cardname;
    card->nextcard=NULL;
    if(*usercard==NULL)
    {
       *usercard=card;
       return;
    }
     Card *temp=*usercard;
        while(temp->nextcard!=NULL){
                temp=temp->nextcard;
        }
        temp->nextcard=card;



}
void displaycard(Card *dis)
{
    while(dis!=NULL){
        printf("%c \n",dis->cardname);
        dis=dis->nextcard;
    }
    return;
}

