#include<stdlib.h>
#include<stdio.h>
struct node {
    int value;
    struct node *right,*left;
};
struct node *root;

void fix(struct node*tmp){
printf("Root:%x | Current:%x Right:%x Left:%x",root,tmp,tmp->right,tmp->left);
}

void create(int val){
    struct node *newnode,*temp,*prev;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->value=val;
    newnode->left=newnode->right=NULL;
    if(!root){
    root=newnode;
    }
    else{
      temp=root;
    while(temp!=NULL){
        prev=temp;
        if(val>temp->value)
        temp=temp->right;
        else if(val<temp->value)
        temp=temp->left;
        else
        {
            printf("Duplicate value %d",val);
            return;
        }
    }
    if(val>prev->value)
        prev->right=newnode;
    else
        prev->left=newnode;
    
    }
}
/*
struct node* newnode(struct node *n,int val){
    n=(struct node*)malloc(sizeof(struct node));
    n->value=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void insert(struct node *tmp,int val){
    if(tmp==NULL){
       newnode(tmp,val); 
    }
    else{
        if(val > tmp->value)
         tmp->right=insert(tmp->right, val);
        else
         tmp->left=insert(tmp->left, val);
        
    }
}*/

void preorder(struct node *head){
  if(head){
  printf("%d->",head->value);
  preorder(head->left);
   preorder(head->right);
  }
  }
  
  void del(int val) {
  struct node *temp,*prev;
  temp=root;
  if(!root){
    printf("Tree itslef is empty");
      return;
  }
  else{
        temp=root;
        while(temp->value != val){
            prev=temp;
          if(temp->value>val){
              temp=temp->left;
            }
          else if(temp->value<val){
                temp=temp->right;
              }
      }
       
  }
  //no child
  if(temp->left=NULL && temp->right==NULL){
    if(prev->value > val)
      prev->left=NULL;
    else
      prev->right=NULL;
    free(temp);
    return;
  }
}
  
int main()
{
    create(3);
    create(4);
    create(5);
   // insert(*root,1);
     preorder(root);
     del(4);
     printf("\n");
     preorder(root);
    return 0;
}













/*


void del(int val){
struct node *tmp,*prev;
  if(!root){
    printf("Tree is empty");
    return;
    }
    tmp=root;
while(tmp->value != val){
            prev=tmp;
          if(tmp->value>val){
              tmp=tmp->left;
            }
          else if(tmp->value<val){
                tmp=tmp->right;
              }
      }
       
  
    //no child
    if(tmp->left==NULL && tmp->right==NULL) 
      {
        if(prev->right->value==val)
        free(prev->right);
        else
        free(prev->left);
        
        return;
      }
      else if(tmp->left==NULL || tmp->right==NULL){//1 child
        if(prev->left==NULL)
          free(prev->right);
        else
          free(prev->left);
          return;
        }
    
}

*/


