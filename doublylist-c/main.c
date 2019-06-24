#include <stdio.h>
#include <stdlib.h>
struct node{
  int value;
  struct node *prev,*next;
};
struct node*head,*tail;

void fix(struct node *tmp){
    printf("\nCurrent=%x value=%d | prev=%x next=%x ",tmp,tmp->value,tmp->prev,tmp->next);
    getch();
}
void add(int val){ 
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->value=val;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        head = tail = temp;
    }
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void insert(int pos,int val){
    struct node *temp,*newnode;
    temp=head;
    int count=0;
    while(temp!=NULL && count < pos){
        temp=temp->next;
        count++;
    }
    if(count!=pos){
        printf("Invalid position");
    }
    else{
        fix(temp);
    /*
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->value=val;
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next->prev=newnode;*/
    }
    
}
void display(struct node *l){
    struct node *tmp; 
    tmp=l;
    while(tmp){
        //printf("%d -> ",tmp->value);
        fix(tmp);
        tmp=tmp->next;
    }
    printf("\n");
}
int main()
{
   add(1);
   add(2);
   insert(1,3);
   display(head); 
   
   
    return 0;
}


