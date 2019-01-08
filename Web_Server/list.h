#ifndef _LIST_H_
#define _LIST_H_

typedef struct node{
	int fd;
	struct node * next;
}Node;


typedef struct list{
	Node * Head;
	Node * Last;
	int count;
}List;

void List_Initialize(List *);
void List_Push(List *,int);
int List_Pop(List *);
void List_Free(List *l);

#endif