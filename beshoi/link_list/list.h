#include <stdio.h>
#include <stdlib.h> /*for malloc*/
struct Node{
	void* data;
	struct Node* prev;
	struct Node* next;
};

struct
linked_list{
	struct Node* head;
};

struct Node* ll_create(void);

void ll_destroy(struct linked_list h);

void ll_add(struct linked_list h, void* value);

void ll_set(struct linked_list h, void* value, int index);

void ll_add_index(struct linked_list h, void* value, int index);

void* ll_remove_last(struct linked_list h);

void* ll_remove_first(struct linked_list h);

void* ll_remove(struct linked_list h, int index);

int ll_length(struct linked_list h);

int ll_contains (struct linked_list h, void* value);

void* ll_toArray(struct linked_list h);

void print(struct linked_list h);

void printR(struct linked_list h);

