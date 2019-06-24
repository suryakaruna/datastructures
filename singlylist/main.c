#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
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

void insertAfterReference(int ref,int val){
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
while(tmp->next!=NULL && (++count)!=pos)
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
 void deleteHead(){
    struct  list *tmp=head;
    if(!tmp){
        printf("Head itself empty\n");
        return;
    }
    head=tmp->next;
    printf("%d is Removed\n",tmp->value);
    free(tmp);
     
 }
  void deleteTail(){
    struct  list *tmp=head;
    if(!tmp){
        printf("List itself empty\n");
        return;
    }
    while(tmp->next){tmp=tmp->next;}
    printf("%d is Removed\n",tmp->next->value);
    tmp->next=NULL;
    free(tmp->next);
     
 }
void reverse(head){
    struct list *tmp,*prev,*next;
    
}
int main()
{
int c,e,pos;
//clrscr();
do{
printf("*** Menu: ***\n1.insertAtLast\n2.insertAtPosition\n3.insertAfterReference\n4.search\n5.deleteNode\n6.deleteTail\n.7.deleteHead\n8.display\n9.Reverse\n10.Exit");
scanf("%d",&c);
switch(c){
case 1:
	printf("Enter Element to be Inserted\n");
	scanf("%d",&e);
	insertAtLast(e);
	break;
case 2: printf("Enter Position where to Inserted\n");
	    scanf("%d",&pos);
        printf("Enter Element to be Inserted\n");
	    scanf("%d",&e);
	insertAtPosition(pos,e);
	break;
case 3: printf("Enter Reference node value\n");
	    scanf("%d",&pos);
        printf("Enter Element to be Inserted\n");
	    scanf("%d",&e);
	    insertAfterReference(pos,e);
	    break;
case 4:	printf("Enter Element to be Searched\n");
	    scanf("%d",&e);
        search(e);
        break;
case 5:	printf("Enter Element to be Deleteded\n");
	    scanf("%d",&e);
        deleteNode(e);
        break;        
case 6:deleteTail();break;
case 7:deleteHead();break;
case 8:display(head);break;
case 9:reverse(head);break;
case 10:exit(0);
default:printf("Invalid Selection !\n");
}
}while(c<11);

//getch();
return 0;
}

