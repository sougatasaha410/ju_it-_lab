#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node * previous;
        struct node * next;
};
struct node * first=NULL;
//creating a doubly linked list
void create(int a[],int n){
    first=(struct node *)malloc(sizeof(struct node));
    struct node * last,*t;
    last=first;
    first->data=a[0];
    first->previous=NULL;
    first->next = NULL;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        t->previous=last;
        last->next=t;
        last=t;
    }
}
//display linkedlist 

void display( struct node *p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
//count the no of node in a linkedlist 
int count(struct node *p){
	int c=0;
	while(p!=NULL){
		c++;
		p=p->next;
		
	}
	return c;
}
//inseet node at particular position
void insert(struct node * p,int pos , int data){
   struct  node *t=(struct node *)malloc(sizeof(struct node));
    if(pos<0||pos>count(p)){
        printf("enter valid position to insert\n");
        return;
    }
    if(pos==0){
        if(first==NULL){
            t->data=data;
            t->next=t->previous=NULL;
            first=t;
        }
        else{
        t->data=data;
        t->next=first;
        first->previous=t;
        t->previous=NULL;
        first=t;
        } 
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t->data=data;
        t->next=p->next;
        t->previous=p;
        p->next->previous=t;
        p->next=t;

    }
}
//delete node at a specific position
int  deletenode(struct node * p,int pos){
     int x;
    if(pos<0||pos>count(p)){
         printf("enter valid position to delete\n");
        return -1;
    }
    if(pos==0){
        struct node * t=first;
        if(first->next!=NULL){
            first=first->next;
            x=t->data;
             free(t);
        }
        else{
            first=NULL;
        }
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        if(p->next) p->next->previous=p->previous;
        p->previous->next=p->next;
        x=p->data;
        free(p);


    }
    return x;

}

//reversing a doubly linked list
void reverse(struct node * p){
   struct node * q;
    while(p!=NULL){
        q=p;
        struct node * temp;
        temp=p->next;
        p->next=p->previous;
        p->previous=temp;
        p=p->previous;
    }
    first=q;;

}
//prting linkedlist in reverse order 
 void reverseprint(struct node * p){
    while(p->next!=NULL){
        p=p->next;
    }
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->previous;
    }
 }
 int main(){
	int b[]={2,4,6,8,10,12,14,16,18,20};
    create(b,10);
    display(first);
    printf("\n");
    reverseprint(first);
    

    
}

