#include <stdio.h>

struct node{
	void* data;
	struct node* prev;
	struct node* next;
};

struct
linked_list{
	struct node* head;
};

struct node* ll_create(void);

void ll_destroy(struct linked_list h);

void ll_add(struct linked_list h, void* value);

void ll_set(struct linked_list h, void* value, int index);

void ll_add_index(struct linked_list h, void* value, int index);

void* ll_remove_last(struct linked_list h);

void* ll_remove_first(struct linked_list h);

void* ll_remove(struct linked_list h, int index);

int ll_length(struct linked_list h);

int ll_contains (struct linked_list h, void* value);

void** ll_to_array(struct linked_list h);

void print(struct linked_list h);

void printR(struct linked_list h);

