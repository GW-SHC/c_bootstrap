#include "list.h"
#include <stdio.h>
/*
	Experimantal methods not yet fully tested
*/
int
main(void){
	struct linked_list h;
	h.head = ll_create();
	
	/*********************************************/
	printf("Testing the ll_add\n");
	ll_add(h, (void*)8);
	ll_add(h, (void*)10);
	ll_add(h, (void*)4);
	ll_add(h, (void*)7);
	ll_add(h, (void*)3);
	ll_add(h, (void*)1);
	ll_add(h, (void*)1);
	ll_add(h, (void*)0);
	printf("Expected output: 8 10 4 7 3 1 1 0\n");
	print(h);
	printR(h);
	/********************************************/
	printf("Testing the ll_set\n");
	ll_set (h, (void*)9, 1);
	ll_set (h, (void*)12, 0);
	ll_set (h, (void*)2, 4);
	ll_set (h, (void*)2, -4);
	ll_set (h, (void*)2, 24);	
	printf("Expected output: 12 9 4 7 2 1 1 0\n");
	print(h);
	printR(h);
	/*********************************************/
	ll_add_index(h, (void*)4, 0);
	ll_add_index(h, (void*)25, 9);
	ll_add_index(h, (void*)122, 5);
	printf("Expected output: 4 12 9 4 7 122 2 1 1 0 25\n");
	print(h);
	printR(h);
	/********************************************/
	printf("Testing the ll_remove");
	ll_remove(h, 0);
	ll_remove(h, 9);
	ll_remove(h, 4);
	ll_remove(h, -12);
	ll_remove(h, 14);
	printf("Expected output: 12 9 4 7 2 1 1 0\n");
	print(h);
		
	return 0;
}
