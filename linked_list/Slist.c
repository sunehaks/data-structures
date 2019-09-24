#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "Slist.h"

slist slist_new(){
	slist s = {NULL,NULL,0};
	return s;
}

static Node* slist_new_node(int32_t ele){
	Node *new_node = (Node*)malloc(sizeof(Node));

	new_node->data = ele;
	new_node->next = NULL;
	return new_node;
}

slist* insert_front(slist *list, int32_t ele){
	assert(list!=NULL);

	Node *new_node = slist_new_node(ele);
	new_node->next = list->head;
	list->head = new_node;
	if(list->tail == NULL)
		list->tail = new_node;
	++list->length;
	assert((list->length == 1 && list->head == list->tail)||(list->length > 0 && list->head != list->tail));
	return list;
}


slist* insert_rear(slist *list, int32_t ele){
	assert(list!=NULL);

	Node *new_node = slist_new_node(ele);
	
	if(list->tail!=NULL){
		list->tail->next = new_node;
		list->tail = new_node;
	}
	else
		list->tail = list->head = new_node;
	++list->length;
	return list;
}

slist* delete_front(slist *list){
	assert(list!=NULL);
	Node *temp;
	if(list->head!=NULL){
		temp = list->head;
		list->head = list->head->next;
	
		if(list->head == NULL)
			list->tail = NULL;
		--list->length;
		free(temp);
	}
	return list;
}

slist* delete_rear(slist *list){
	assert(list!=NULL);
	Node *temp, *last;
	if(list->tail!=NULL){
		temp = list->tail;
		if(list->length > 1){
			for(last = list->head; last->next!= list->tail; last = last->next);
			list->tail = last;
			last->next = NULL;
		}
		if(list->tail == NULL)
			list->head = NULL;
		--list->length;
		free(temp);
	}
	return list;
}

uint32_t slist_length(slist *list){
	if(list==NULL){
		printf("empty list\n");
		return -1;
	}
	return list->length;
}

uint32_t slist_lookup(slist *list, int32_t key){
	assert(list!=NULL);
	Node *cur;
	for(cur = list->head ; cur!= NULL ; cur = cur->next)
		if(cur->data == key)
			break;
	return (cur!=NULL);
}

int32_t slist_max(slist *list){							//question 2
	int max = -2147483646;
	Node *cur ;
	for(cur = list->head; cur!=NULL ; cur = cur->next)
		if(max < cur->data)
			max = cur->data;
	return max;
}

int32_t slist_min(slist *list){
	int min = 2147483647;
	Node *cur ;
	for(cur = list->head; cur!=NULL ; cur = cur->next)
		if(min > cur->data)
			min = cur->data;
	return min;	
}

void slist_insert_after(slist *list, int32_t ele, int32_t key){		//question 3
	Node *new = slist_new_node(ele);
	new->data = ele;
	Node *cur ;
	if(slist_lookup(list,key) == 0){
		printf("Invalid key\n");
		return;
	}
	for(cur = list->head; cur->data!=key ; cur = cur->next);
	new->next = cur->next;
	cur->next = new;
	++list->length;

	for(cur = list->head; cur->next!=NULL ; cur = cur->next);
	list->tail = cur;
	//printf("%d",list->tail->data);

}

slist* slist_delete_ele(slist *list, int32_t ele){		//question 4
	Node *cur,*temp;
	assert(list!=NULL);

	if(slist_length(list)==1){
		temp = list->head;
		list->head = list->tail = NULL;
	}

	else if(list->head->data == ele){
		temp = list->head;
		list->head = temp->next;
	}

	else if(list->tail->data == ele){
		temp = list->tail;
		for(cur = list->head; cur->next->data!=ele ; cur = cur->next);
		list->tail = cur;
	}

	else{
		for(cur = list->head; cur->next->data!=ele ; cur = cur->next);
		temp = cur->next;
		cur->next = temp->next;
	}
	--list->length;
	free(temp);

}

slist* slist_reverse(slist *list){			//question 5
	

	assert(list!=NULL);

	Node *temp;
	Node *p,*cur,*n,*d;
	p = NULL;
	
	cur = list->head;
	n = list->head->next;
	//d = cur;
	//printf("cur:%d %u, nex:%d %u\n",cur->data,cur->next,n->data,n->next );
	while(cur!=NULL){
		//printf("cur : %u\n",cur->next);
		cur->next = p;
		//printf("cur : %u\n",cur->next);
		p = cur;
		//printf("prev:%u, cur : %u\n",p->next,cur->next);
		cur = n;
		//printf("cur:%u",cur->next);
		if(n!=NULL){
			n = n->next;
			//printf("nex:%d",nex->data);
		}
	Node* temp;
	temp = list->head;
	list->head = list->tail;
	list->tail = temp;

	}
	return list;
}

uint32_t slist_same(slist *l1, slist *l2){				// question 6
	if(slist_length(l1)!=slist_length(l2))
		return 0;
	int i1, i2;
	Node *t1, *t2;
	t1 = l1->head;
	t2 = l2->head;

	for(t1 = l1->head,t2 = l2->head; t1!=NULL,t2!=NULL; t1=t1->next, t2=t2->next)
		if(t1->data!=t2->data)
			return 0;

	if(t1==NULL && t2==NULL)
		return 1;
}

slist* slist_union(slist *s1, slist *s2){
	assert(s1!=NULL);
}

slist* unique(slist* list){
	assert(list!=NULL);
	slist *ptr;
	slist uniq = slist_new();
	ptr= &uniq;
	Node *temp;
	if(list->head!=NULL){
		for(temp=list->head;temp!=NULL;temp=temp->next)
			if(slist_lookup(ptr,temp->data)==0)
				insert_rear(ptr,temp->data);
	}
	printf("%d\n", slist_length(list));
	return ptr;
}