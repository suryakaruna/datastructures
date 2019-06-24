#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node *next;
};
struct node *head,*tail;
void add(int val){
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->v=val;
    tmp->next=NULL;
    if(head==NULL){
    head=tmp;
    tail=tmp;
    }
    else{
    tail->next=tmp;
    tail=tmp;
    }
}
void search(int val){
    struct node *tmp;
    tmp=head;
    while(tmp!=NULL){
    if(tmp->v==val){
        printf("%d is found\n",val);
        return;
    }
    tmp=tmp->next;
    }
    printf("%d is not found\n",val);
}
void insert(int val,char mode){
    struct node *tmp;
    int ins=30;
    tmp=head;
    if(mode=='f'){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->v=val;
    t->next=head;
    head=t;
    }
    else if(mode=='m'){
    printf("Enter the node after you like to insert\n");
    //scanf("%d",&ins);
    while(tmp!=NULL){
        if(tmp->v==ins){
        struct node *t;
          t=(struct node *)malloc(sizeof(struct node));
          t->v=val;
        t->next=tmp;
        t=tmp;
        return;
          }else{
            tmp=tmp->next;
          }

    }
    printf("Position not found!\n");
    }
    else
    add(val);
}
void del(int val){
    struct node *tmp=head,*prev;
    prev=head;
    while(tmp){
    if(tmp->v==val){
       if(tmp==head){
       head=head->next;
       free(tmp);
       return;
       }
       else if(tmp==tail)
       {
       prev->next=tmp->next;
       tail=prev;
       free(tmp);
       return;
       }
       else
       {
       prev->next=tmp->next;
       free(tmp);
       return;
       }
   }
    prev=tmp;
    tmp=tmp->next;
    }
}
void print(struct node *l){
struct node *tmp;
tmp=l;
while(tmp){
printf("%d -> ",tmp->v);
tmp=tmp->next;
}
}

/*
void reverse(struct node *l){
struct node *first,*last,*tmp,*t;
last=first=(struct node*)malloc(sizeof(struct node));
tmp=l;
while(tmp){
    
    t=tmp;
    while(t->next){
         t=t->next;
    }
//printf("\ntmp->next: %d",tmp->next->v);
printf("\ntmp: %d",t->v);
    if(first==NULL){
        first=last=t;
    }
    else{
        last->next=t;
        last=t;
    }
    del(t->v);
    tmp=tmp->next;
    }
 print(first);
}
*/
void reverse(struct node *head){
struct node *prev=NULL,*first=*head,*last=NULL;

}

int main()
{      
    add(20);
    add(30);
    add(40);
    insert(10,'f');
    del(40);
    print(head);
    reverse(head);
        return 0;
}
