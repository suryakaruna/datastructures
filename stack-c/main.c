#include<stdio.h>
#include<stdlib.h>

struct node{
 int value;
  struct node *next;
};

struct node *top;


void push(int val){
struct node *newnode,*tmp;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->value=val;
newnode->next=NULL;
	if(newnode==NULL){
		printf("\nOVERFLOW");
		return;
	}
	if(!top){
	top=newnode;
	}
	else{
	   newnode->next=top;
	   top=newnode;
	}
}

void pop(){
struct node *tmp;
	if(!top){
	printf("underflow");
	}
	else{
	   tmp=top;
	   printf("\n%d is popped out\n",tmp->value);
	   top=top->next;
	   free(tmp);
	}
}


void display(struct node *h){
struct node *tmp=h;
if(!tmp){printf("Stack Underflow\n");return;}
while(tmp){
//fix(tmp);
printf("%d --> ",tmp->value);
tmp=tmp->next;
}
printf("NULL\n");
}

int main(){
int c,e;

do{
printf("*** Menu: ***\n1.Push\n2.Pop\n3.Display\n4.Exit");
scanf("%d",&c);
switch(c){
case 1:
	printf("Enter Element to be pushed\n");
	scanf("%d",&e);
	push(e);
	break;
case 2: pop();break;
case 3: printf("The Stack Is\n");
	display(top);break;
case 4:	exit(0);
default:printf("Invalid Selection !\n");
}
}while(c<4);

return 0;
}
