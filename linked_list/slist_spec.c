/*
 *	Author : Deepak
 *	Date   : 23 August 2019 
 *	Specification file for Single Linked List
 *	Contain test cases to test various functionalities
 *	of Single Linked List.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Slist.h"

/* test case to check creation of empty slist variable */
void test_empty_list()
{
	slist s = slist_new();
	slist *list = &s;
	assert (slist_length(list) == 0);
}

/*	test case to check adding node from 'head' position
 *	finding length of list and lookup functions
*/

void print_list(slist *list){
	Node *temp;
	for(temp = list->head; temp != NULL; temp = temp->next)
		printf("%d->",temp->data);
	printf("\n");
}
void test_addition_at_head()
{
	slist s = slist_new();
	slist *list = &s;
	list = insert_front(list, 10);
	assert (slist_length(list) == 1);
	
	list = insert_front(list, 20);
	list = insert_front(list, 30);
	list = insert_front(list, 40);
	list = insert_front(list, 50);
	assert (slist_length(list) == 5);
	assert (slist_lookup(list, 30));

}

void test_addition_at_tail(){
	slist s = slist_new();
	slist *list = &s;
	list = insert_rear(list,10);
	assert(slist_length(list) == 1);

	list = insert_rear(list,20);
	list = insert_rear(list,30);
	list = insert_rear(list,40);
	assert (slist_length(list) == 4);
	assert (slist_lookup(list, 20));
}

void test_deletion_at_head(){
	slist s = slist_new();
	slist *list = &s;
	list = insert_front(list, 10);
	assert (slist_length(list) == 1);
	
	list = insert_front(list, 20);
	list = insert_front(list, 30);
	delete_front(list);
	assert (slist_length(list) == 2);
	assert (~(slist_lookup(list, 10)));
	delete_front(list);
	assert (slist_length(list) == 1);
	assert (~(slist_lookup(list, 20)));

}

void test_deletion_at_tail(){
	slist s = slist_new();
	slist *list = &s;
	list = insert_front(list, 10);
	assert (slist_length(list) == 1);
	
	list = insert_front(list, 20);
	list = insert_front(list, 30);
	delete_rear(list);
	assert (slist_length(list) == 2);
	assert (~(slist_lookup(list, 30)));
	delete_rear(list);
	assert (slist_length(list) == 1);
	assert (~(slist_lookup(list, 20)));
}

void test_max(){
	slist s = slist_new();
	slist *list = &s;

	assert(slist_max(list) == -2147483646);

	list = insert_front(list, 10);
	assert (slist_length(list) == 1);

	list = insert_rear(list,20);
	assert(slist_length(list) == 2);

	assert(slist_max(list) == 20);
}

void test_min(){
	slist s = slist_new();
	slist *list = &s;

	assert(slist_min(list) == 2147483647);

	list = insert_front(list, 10);
	assert (slist_length(list) == 1);

	list = insert_rear(list,20);
	assert(slist_length(list) == 2);

	assert(slist_min(list) == 10);

}

void test_insert_after(){
	slist s = slist_new();
	slist *list = &s;

	list = insert_front(list, 10);
	assert (slist_length(list) == 1);

	list = insert_rear(list,20);
	assert(slist_length(list) == 2);	

	assert (slist_lookup(list, 10));
	slist_insert_after(list,30,10);
	
	assert (slist_length(list) == 3);
	assert (slist_lookup(list, 30));

	assert (slist_lookup(list, 20));
	slist_insert_after(list,40,20);
	assert(list->tail->data == 40);
	assert (slist_length(list) == 4);
	assert (slist_lookup(list, 40));

}

void test_delete_ele(){
	slist s = slist_new();
	slist *list = &s;

	list = insert_front(list, 10);
	assert (slist_length(list) == 1);

	assert(slist_lookup(list,10)); //deleting node in list with single node
	slist_delete_ele(list,10);
	assert(slist_length(list)==0);
	assert(list->head== NULL && list->tail== NULL);	
	assert(~slist_lookup(list,10));

	list = insert_rear(list,20);
	assert(slist_length(list) == 1);

	list = insert_front(list, 30);
	assert (slist_length(list) == 2);

	list = insert_rear(list,40);
	assert(slist_length(list) == 3);

	assert(slist_lookup(list,30)); // deleting head node
	slist_delete_ele(list,30);
	assert(slist_length(list)==2);
	assert(list->head->data==20);
	assert(~slist_lookup(list,30));

	list = insert_front(list, 30);
	assert (slist_length(list) == 3);

	assert(slist_lookup(list,20)); // deleting middle node
	slist_delete_ele(list,20);
	assert(slist_length(list)==2);
	assert(~slist_lookup(list,20));	

	assert(slist_lookup(list,40)); // deleting tail node
	slist_delete_ele(list,40);
	assert(slist_length(list)==1);
	assert(list->tail->data==30);
	assert(~slist_lookup(list,40));

}

void test_reverse(){
	slist s = slist_new();
	slist *list = &s;
	
	list = insert_rear(list, 10);
	assert (slist_length(list) == 1);
	
	list = insert_rear(list, 20);
	assert (slist_length(list) == 2);

	list = insert_rear(list, 30);
	assert (slist_length(list) == 3);

	list = insert_rear(list, 40);
	assert (slist_length(list) == 4);

	list = insert_rear(list, 50);
	assert (slist_length(list) == 5);
	assert (slist_lookup(list, 30));

	Node *temp;
	/*for(temp = list->head;temp!=NULL;temp = temp->next)
		printf("%d->",temp->data );
*/
	slist_reverse(list);

	int i;

	for(i = 50, temp = list->head; i<=50, temp!=NULL; i-=10, temp = temp->next){
		//printf("%d->",temp->data );
		assert(temp->data == i);
	}

}

void test_issame(){
	slist s1 = slist_new();
	slist *list1 = &s1;

	slist s2 = slist_new();
	slist *list2 = &s2;

	list1 = insert_rear(list1, 10);
	assert (slist_length(list1) == 1);
	
	list1 = insert_rear(list1, 20);
	assert (slist_length(list1) == 2);

	list1 = insert_rear(list1, 30);
	assert (slist_length(list1) == 3);

	list2 = insert_rear(list2, 10);
	assert (slist_length(list2) == 1);
	
	list2 = insert_rear(list2, 20);
	assert (slist_length(list2) == 2);

	list2 = insert_rear(list2, 30);
	assert (slist_length(list2) == 3);

	int i =slist_same(list1,list2);

	assert(i == 1);

}

void test_unique(){
	slist s1 = slist_new();
	slist *list = &s1;

	list = insert_rear(list, 10);
	assert(slist_length(list)==1);

	list = insert_rear(list,10);
	assert(slist_length(list)==2);

	list = insert_rear(list, 20);
	assert(slist_length(list)==3);

	list = insert_rear(list, 20);
	assert(slist_length(list)==4);

	list = unique(list);
	//printf("%u",list);
	assert(slist_lookup(list, 10));
	assert(slist_lookup(list,20));

	print_list(list);
	printf("%d",list->length);
	printf("%d\n", slist_length(list));			// print testing

	assert(slist_length(list)==2);

}



int main()
{
	test_empty_list();
	test_addition_at_head();
	test_addition_at_tail();
	test_deletion_at_head();
	test_deletion_at_tail();
	test_max();				// question 2
	test_min();				
	test_insert_after();	// question 3
	test_delete_ele();		// question 4
	test_reverse();			// question 5
	test_issame();
	
	return 0;
}

/*
 *	Running your programs. Assume that already you have
 *	'slist.h', 'slist.c' and 'slist_spec.c' files.
 *
 *	gcc slist.c slist_spec.c -o slist
 *
 *	If you get errors, fix them. Otherwise you have exe file
 *	with name 'slist' (due to -o slist option used during compilation)
 *	
 *	Running exe file:	./a.out slist
 *	If you don't get any message in terminal, code executed perfectly
 *	( No news good news!!!!!!!)
 *
*/
