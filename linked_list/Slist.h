#ifndef _INCLUDED_SLIST_
#define _INCLUDED_SLIST_
#include<stdint.h>
typedef struct _node_ Node;
typedef struct _slist_ slist;
struct _node_{
	int32_t data;
	Node *next;
};

struct _slist_ {
	Node *head;
	Node *tail;
	uint32_t length;
};

slist slist_new();
static Node* slist_new_node(int32_t ele);
slist* insert_front(slist *list, int32_t ele);
slist* insert_rear(slist *list, int32_t ele);
slist* delete_front(slist *list);
slist* delete_rear(slist *list);
uint32_t slist_length(slist *list);
uint32_t slist_lookup(slist *list, int32_t key    );
int32_t slist_max(slist *list);
int32_t slist_min(slist *list);
void slist_insert_after(slist *list, int32_t ele, int32_t key);
slist* slist_delete_ele(slist *list, int32_t ele);
slist* slist_reverse(slist *list);
uint32_t slist_same(slist *l1, slist *l2);
slist* slist_union(slist *s1, slist *s2);
slist* slist_inter(slist *s1, slist *s2);
slist* unique(slist* list);
#endif
