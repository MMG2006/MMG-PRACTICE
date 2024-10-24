#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* link;
} node;
node* head;
node* ln;
void create();
void insert();
void delete();
void display();

int main() {
	char k;
	printf("\n/// SINGLE LINKED LIST ///\n");
	while(1) {
		printf("\nc->create\ni->insertion\nd->deletion\np->display\ne->exit");
		printf("\n Enter your choice: ");
		scanf("%s",&k);
		if(k=='c') {
			create();
		}
		else if(k=='e') {
			return 0;
		}
		else if(k=='i') {
			insert();
		}
		else if(k=='p') {
			display();
		}
		else if(k=='d') {
			delete();
		}
	}
}

void create() {
	if(head==NULL) {
		node* p=(node*) malloc(sizeof(node));
		printf("\nEnter your integer data: ");
		scanf("%d",&p->data);
		p->link=NULL;
		head=p;
		ln=p;
		return;
	}
	printf("\nLinked List already created.");
	return;
}

void insert() {
	if(head!=NULL) {
		printf("\n1->front\n2->end");
		int k;
		printf("\nEnter your choice: ");
		scanf("%d",&k);
		if(k==1) {
			node* p=(node*) malloc(sizeof(node));
			printf("\nEnter your integer data: ");
			scanf("%d",&p->data);
			p->link=head;
			head=p;
			return;
		}
		else if(k==2) {
			node* p=(node*) malloc(sizeof(node));
			printf("\nEnter your integer data: ");
			scanf("%d",&p->data);
			p->link=NULL;
			ln->link=p;
			ln=p;
			return;
		}
	}
	printf("\nLinked List is not created. Create the Linked List first.");
	return;
}

void display() {
	if(head!=NULL) {
		node* p;
		p=head;
		while(p!=NULL) {
			printf("\n%d",p->data);
			p=p->link;
		}
		return;
	}
	printf("\nLinked List is not created. Create the Linked List first.");
	return;
}

void delete() {
	if(head==NULL) {
		printf("\nLinked List is not created. Create the Linked List first.");
		return;
	}
	else if((head->link)==NULL) {
		node* p;
		p=head;
		head=NULL;
		ln=NULL;
		printf("\n%d is deleted.",p->data);
		free(p);
		return;
	}
	else {
		printf("\n1->front\n2->end");
		int k;
		printf("\nEnter your choice: ");
		scanf("%d",&k);
		if(k==1) {
			node* p;
			p=head;
			head=p->link;
			printf("\n%d is deleted.",p->data);
			free(p);
			return;
		}
		else if(k==2) {
			node* p;
			node* q;
			p=ln;
			q=head;
			while(((q->link)->link)!=NULL) {
				q=q->link;
			}
			q->link=NULL;
			ln=q;
			printf("\n%d is deleted.",p->data);
			free(p);
			return;
		}
	}
}