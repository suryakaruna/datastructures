#include<stdio.h>
#include<stdlib.h>

struct list{
int value;
struct list *next;
};

struct list *head,*tail;
void fix(struct list *l){
  printf("\ncurrent=%x value=%d next=%x",l,l->value,l->next);
}

void insertAtLast(int val){
struct list *newlist;
newlist=(struct list*)malloc(sizeof(struct list));
newlist->value=val;
newlist->next=NULL;
	if(!head){
	    head = tail =newlist;
	}else{
	tail->next=newlist;
	tail=newlist;
	}
}

void insertAtReference(int ref,int val){
	struct list *newlist;
	newlist=(struct list*)malloc(sizeof(struct list));
	newlist->value=val;
	newlist->next=NULL;
	if(!head){
	printf("\nReference unavailable: List Is Empty");
	}
	else{
	struct list *tmp;
	tmp=head;
	while(tmp!=NULL && tmp->value!=ref){
	tmp=tmp->next;
	}
	if(tmp->value==ref){
	newlist->next=tmp->next;
	tmp->next=newlist;
	printf("\nNode:%d inserted After %d",val,ref);
	}
	else{
	printf("\nReference Node Not Existed");
	}
	}

}

void display(struct list *l){
	struct list *tmp=l;
	printf("\n");
	while(tmp){
	 printf("%d -> ",tmp->value);
	//fix(tmp);
	tmp=tmp->next;
	}
	printf("NULL");
}

void insertAtPosition(int pos,int val){
int count=1;
struct list *newlist,*tmp;
newlist=(struct list*)malloc(sizeof(struct list));
newlist->value=val;
newlist->next=NULL;
if(pos==count){
newlist->next=head;
head=newlist;
return;
}
tmp=head;
while(tmp!=NULL && (++count)!=pos)
    tmp=tmp->next;
if(count==pos){
newlist->next=tmp->next;
tmp->next=newlist;
printf("\nNode:%d Inserted At Position:%d",val,pos);
}
else{
printf("\nPosition Invalid");
}
}

void search(int val){
	int count=1;
    struct list*tmp=head;
    while(tmp){
    if(tmp->value==val){
    printf("\nNode:%d Is Found At Position:%d",val,count);
    return;
    }else{
    tmp=tmp->next;
    count++;
    }
    }
    printf("\nNode:%d Is Not Found",val);

}

void deleteNode(int val){
	struct list *tmp=head,*prev=head;
	if(tmp->value==val){
	   head=tmp->next;
	   free(tmp);
	   printf("\nNode:%d Removed Successfully",val);
	   return;
	}else{
	while(tmp!=NULL && tmp->value!=val){
	prev=tmp;
	tmp=tmp->next;
	}
	if(tmp->value==val){
	prev->next=tmp->next;
	free(tmp);
	printf("\nNode:%d Removed Successfully",val);
	}else{
	printf("\nNode:%d Not Found",val);
	}
	}
 }

int main(){

return 0;
}