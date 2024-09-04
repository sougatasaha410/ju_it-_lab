#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
 struct node *first=NULL;

// creating a linked list 
 void create(int a[],int n){
    first=(struct node *)malloc(sizeof(struct node));
	struct node *t;
	 struct node * last;
	first->data=a[0];
	first->next=NULL;
	last=first;
	for(int i=1;i<n;i++){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=last->next;
		last->next=t;
		last=t;
	}
}

// display a linkedlist 
void display( struct node *p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
//count the number of node
int count(struct node *p){
	int c=0;
	while(p!=NULL){
		c++;
		p=p->next;
		
	}
	return c;
}

//insert in a linkedlist into a specific position 
void insert( struct node *p,int position,int data){
	struct node *t=(struct node *)malloc(sizeof(struct node));
	if(position ==0){
		t->data=data;
		t->next=first;
		first=t;
	}
	else{
		for(int i=0;i<position-1;i++){
		p=p->next;
	}
	t->data=data;
	t->next=p->next;
	p->next=t;
}
}

//deleting a elennt of the array
int deleteNode(struct node *p, int pos) {  
    struct node *q;
	int x;
    if (pos < 1 || pos > count(p)) {
        return -1;  
    }
    if (pos == 1) {
        p = first;
        first = first->next;
        x = p->data;
        free(p);  
       
    } else {
        for (int i = 0; i < pos - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        int x = p->data;
         free(p);  
    }
	return x;
}

//reverse a linkedlist using array
void reverse (struct node *p){
	int n=count(p);
	int *a=(int  *)malloc(n*sizeof(int ));
	int i=0;
	struct node *q=p;
	while(q!=NULL){
		a[i++]=q->data;
		q=q->next;
	}
	i--;
	q=p;
	while(q!=NULL){
		q->data=a[i--];
		q=q->next;
	}
	 free(a); 
}
//reversing a linkedlist by reversing the links using loop and sliding pointer 
void lreverse(struct node *p){
	struct node *q=NULL;
	struct node *r=NULL;
	while(p!=NULL){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}

int main(){
	int a[]={1,3,5,7,9,11,13,15,17,19};
    create(a,10);
}