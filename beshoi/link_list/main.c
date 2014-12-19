#include "list.h"
#include <stdio.h>

int
main(void){
	struct linked_list h;
	h.head = ll_create();
	
	/*********************************************/
	printf("Testing the ll_add\n");
	ll_add(h, (void*) 8);
	ll_add(h, (void*) 10);
	ll_add(h, (void*) 4);
	ll_add(h, (void*) 7);
	ll_add(h, (void*) 3);
	ll_add(h, (void*) 1);
	ll_add(h, (void*) 1);
	ll_add(h, (void*) 0);
	printf("Expected output: 8 10 4 7 3 1 1 0\n");
	print(h);
	printR(h);

	int count = ll_length(h);
	printf("Linked List length = %d \n\n", count);
	
	/*********************************************/
	void** x = ll_to_array(h);
	printf("Array Values outside of method\n");
	int i;
	for (i = 0; i < ll_length(h); i++){
		printf("%d ", x[i]);
	}printf("\n\n");
	
	/********************************************/
	printf("Testing the ll_contains\n");
	int ind = ll_contains(h, 10);
	int ind2 = ll_contains(h, 0);
	int ind3 = ll_contains(h, 20);
	printf("Expected output: 1 7 -1 \n");
	printf("Output: %d %d %d\n", ind, ind2, ind3);
	printf("\n");
	
	/********************************************/
	printf("Testing the ll_remove_last\n");
	int num = (int) ll_remove_last(h);
	int num2 = (int) ll_remove_last(h);
	int num3 = (int) ll_remove_last(h);
	printf("Expected output: 0 1 1\n");
	printf("Output: %d %d %d\n", num, num2, num3);
	printf("Linked List length = %d \n", ll_length(h));
	print(h);
	printf("\n");
	
	/********************************************/
	printf("Testing the ll_remove_first\n");
	num = (int) ll_remove_first(h);
	num2 = (int) ll_remove_first(h);
	num3 = (int) ll_remove_first(h);
	printf("Expected output: 8 10 4\n");
	printf("Output: %d %d %d\n", num, num2, num3);
	printf("Linked List length = %d \n", ll_length(h));
	print(h);
	printf("\n");
	
	/*******************************************/
	ll_destroy(h);
	print(h);

}
