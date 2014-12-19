#include "list.h"
#include <stdio.h>
#include <stdlib.h> /*for malloc*/

struct 
Node* ll_create(void){
	struct linked_list h;
	h.head = (struct Node*) malloc(sizeof(struct Node*));
	
	h.head -> next = NULL;
	h.head -> prev = NULL;
	h.head -> data = NULL;
	
	return h.head;
}

void 
ll_destroy(struct linked_list h){
	struct Node* temp = h.head -> next;
	struct Node* temp2;
	
	if (!(h.head -> next) && !(h.head -> prev)) return; //if its already empty
	
	while (temp != h.head -> prev){
		temp2 = temp ->next;
		free(temp);
		temp = temp2;
	}
	free(temp); //frees the last node in the list
	
	h.head -> next = NULL; //reset to ll_create status
	h.head -> prev = NULL; //reset to ll_create status
}

void 
ll_add(struct linked_list h, void* value){
	struct Node* temp = (struct Node*) malloc (sizeof(struct Node*));
	temp -> data = value;
	
	if (!(h.head -> next) && !(h.head -> prev)){
		h.head -> next = temp;
		h.head -> prev = temp;
		
		temp -> next = h.head -> next;
		temp -> prev = h.head -> prev;
		return; //conditional only done if head points to nothing
	}
	
	temp -> prev = h.head -> prev;
	temp -> next = h.head -> next;
	h.head -> prev = temp;
	
	temp -> prev -> next = temp;
	temp -> next -> prev = temp;
}

void
ll_set(struct linked_list h, void* value, int index){
	struct Node* temp = h.head -> next;
	int len = ll_length (h);
	int i = 0;
	
	if(index < 0 || index >= len)
		return;
	
	while (index > i){
		temp = temp -> next;
		i++;
	}
	
	temp -> data = value;
}

void
ll_add_index(struct linked_list h, void* value, int index){
	struct Node* temp = h.head -> next;
	struct Node* addIt = (struct Node*) malloc (sizeof(struct Node*));
	addIt -> data = value;
	int len = ll_length (h);
	int i = 0;
	
	if(index < 0 || index > len)
		return;
		
	if (index == len){
		ll_add(h, value);
		return;
	}else if (index == 0){
		addIt -> next = h.head -> next;
		h.head -> next = addIt;
		
		addIt -> prev = addIt -> next -> prev;
		addIt -> next -> prev = addIt;
		addIt -> prev -> next = addIt;
		return;
	}
		
	while (index > i){
		temp = temp -> next;
		i++;
	}

	addIt -> next = temp;
	addIt -> prev = temp -> prev;
	
	addIt -> next -> prev = addIt;
	addIt -> prev -> next = addIt;
}

int 
ll_length(struct linked_list h){
	int count = 0;
	struct Node* temp = h.head -> next;

	if (!(h.head -> next) && !(h.head -> prev)) return count; //already empty
	
	while (temp != h.head -> prev){
		count++;
		temp = temp -> next;
	}count ++; //to add the last node
	
	return count;
}

void* 
ll_remove_last(struct linked_list h){
	struct Node* temp = h.head -> prev;
	void* data = temp -> data;
	
	h.head -> prev = temp -> prev;
	temp -> prev -> next = temp -> next;
	temp -> next -> prev = temp -> prev;
	
	free(temp);
	temp = NULL;
	return data;
}

void*
ll_remove_first(struct linked_list h){
	struct Node* temp = h.head -> next;
	void* data = temp -> data;
	
	h.head -> next = temp -> next;
	temp -> prev -> next = temp -> next;
	temp -> next -> prev = temp -> prev;
	
	free(temp);
	temp = NULL;
	return data;
}

void* 
ll_remove(struct linked_list h, int index){
	struct Node* temp = h.head -> next;
	void* val;
	int len = ll_length(h);
	int i;
	
	if(index < 0 || index >= len)
		return;
		
	if (index == 0)
		return ll_remove_first(h);
	
	else if(index == len-1)
		return ll_remove_last(h);
	
	while (index > i){
		temp = temp -> next;
		i++;
	}
	
	val = temp -> data;
	temp -> next -> prev = temp -> prev;
	temp -> prev -> next = temp -> next;
	
	free(temp);
	temp = NULL;
	
	return val;
}

int 
ll_contains (struct linked_list h, void* value){
	struct Node* temp = h.head -> next;
	struct Node* temp2 = h.head -> prev;
	
	int i, j;
	for (i = 0, j = ll_length(h) -1; i <= j; i++, j--){
		if (temp -> data == value) return i; //searches forward
		if (temp2 -> data == value) return j; //searches backwards
		
		temp = temp -> next;
		temp2 = temp2 -> prev;
	}
	
	return -1;
}

void*
ll_toArray(struct linked_list h){
	void** A = (void**) malloc(sizeof(void*) * ll_length(h));
	struct Node* temp = h.head -> next;
	int i = 0;
	
	if (!(h.head -> next) && !(h.head -> prev)) return;
	while (temp != h.head -> prev){
		A[i] = temp -> data;
		temp = temp -> next;
		i++;
	}
	
	return A;
}
/*******************************************************Test Print Methods************************************************************************/
void 
print(struct linked_list h){
	struct Node* temp = h.head -> next;
	
	if (!(h.head -> next) && !(h.head -> prev)) return; //if its already empty
	
	printf("List is: ");
	while (temp != h.head -> prev){
		printf("%d ", temp->data);
		temp = temp ->next;
	}
	printf("%d ", temp->data); //to print the last number in the list
	
	printf("\n");
}

void 
printR(struct linked_list h){
	struct Node* temp = h.head -> prev;
	
	if (!(h.head -> next) && !(h.head -> prev)) return; //if its already empty
	
	printf("List is: ");
	while (temp != h.head -> next){
		printf("%d ", temp->data);
		temp = temp -> prev;
	}
	printf("%d ", temp->data); //to print the last number in the list
	
	printf("\n");
}
/*********************************************************************End Test Methods********************************************************************/
