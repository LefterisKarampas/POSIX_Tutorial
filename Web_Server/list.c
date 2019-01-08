#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void List_Initialize(List *l){
	l->Head = NULL;
	l->Last = NULL;
	l->count = 0;
}

void List_Push(List *l,int fd){
	if(l->Head == NULL){
		l->Head = malloc(sizeof(Node));
		l->Head->fd = fd;
		l->Head->next = NULL;
		l->Last = l->Head;
	}
	else{
		Node *x = malloc(sizeof(Node));
		x->fd = fd;
		x->next = NULL;
		l->Last->next = x;
		l->Last = x;
	}
	l->count++;
}

int List_Pop(List *l){
	if(l->Head != NULL){
		Node *temp = l->Head;
		int fd;
		fd = l->Head->fd;
		l->Head = l->Head->next;
		free(temp);
		l->count--;
		return fd;
	}
	else{
		return -1;
	}
}

void List_Free(List *l){
	while(l->Head){
		List_Pop(l);
	}
}
