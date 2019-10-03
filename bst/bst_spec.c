#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include<stdio.h>
#include "bst.h"

void test_new(){
	BST b = bst_new();
	assert(b.root==NULL && b.mass == 0);
}

void test_count(){
	BST b = bst_new();
	BST *bst = &b;

	int c = bst_count(bst);
	assert(c == 0);

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	c = bst_count(bst);
	assert(c == 1);
}

void test_add_node(){
	BST b = bst_new();
	BST *bst = &b;

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	assert(bst->mass == 1);

	bst_add_node(bst,20);
	assert(bst->root->data == 10);
	assert(bst->mass == 2);
	assert(bst_lookup(bst,20));

	bst_add_node(bst,5);
	assert(bst->root->data == 10);
	assert(bst->mass == 3);
	assert(bst_lookup(bst,5));

	bst_add_node(bst,15);
	assert(bst->root->data == 10);
	assert(bst->mass == 4);
	assert(bst_lookup(bst,15));
}

void test_delete_node(){
	BST b = bst_new();
	BST *bst = &b;

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	assert(bst->mass == 1);

	bst_add_node(bst,20);
	assert(bst->root->data == 10);
	assert(bst->mass == 2);
	assert(bst_lookup(bst,20));

	bst_add_node(bst,5);
	assert(bst->root->data == 10);
	assert(bst->mass == 3);
	assert(bst_lookup(bst,5));

	bst_add_node(bst,15);
	assert(bst->root->data == 10);
	assert(bst->mass == 4);
	assert(bst_lookup(bst,15));

	bst_delete_node(bst,10);
	assert(!(bst_lookup(bst,10)));
	assert(bst->root->data == 15);
	assert(bst->mass == 3);

	bst_delete_node(bst,20);
	assert(!(bst_lookup(bst,20)));
	assert(bst->root->data == 15);
	assert(bst->mass == 2);
}

void test_inorder(){
	BST b = bst_new();
	BST *bst = &b;

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	assert(bst->mass == 1);

	bst_add_node(bst,20);
	assert(bst->root->data == 10);
	assert(bst->mass == 2);
	assert(bst_lookup(bst,20));

	bst_add_node(bst,5);
	assert(bst->root->data == 10);
	assert(bst->mass == 3);
	assert(bst_lookup(bst,5));

	bst_add_node(bst,15);
	assert(bst->root->data == 10);
	assert(bst->mass == 4);
	assert(bst_lookup(bst,15));

	uint32_t* list = bst_inorder(bst);
	uint32_t ans[4] = {5,10,15,20};
	for(int j = 0; j<bst->mass; j++)
		assert(*(list+j) == ans[j]);
	
}

void test_preorder(){
	BST b = bst_new();
	BST *bst = &b;

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	assert(bst->mass == 1);

	bst_add_node(bst,20);
	assert(bst->root->data == 10);
	assert(bst->mass == 2);
	assert(bst_lookup(bst,20));

	bst_add_node(bst,5);
	assert(bst->root->data == 10);
	assert(bst->mass == 3);
	assert(bst_lookup(bst,5));

	bst_add_node(bst,15);
	assert(bst->root->data == 10);
	assert(bst->mass == 4);
	assert(bst_lookup(bst,15));

	uint32_t* list = bst_preorder(bst);
	uint32_t ans[4] = {10,5,20,15};
	for(int j = 0; j<bst->mass; j++)
		assert(*(list+j) == ans[j]);
	
}

void test_postorder(){
	BST b = bst_new();
	BST *bst = &b;

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	assert(bst->mass == 1);

	bst_add_node(bst,20);
	assert(bst->root->data == 10);
	assert(bst->mass == 2);
	assert(bst_lookup(bst,20));

	bst_add_node(bst,5);
	assert(bst->root->data == 10);
	assert(bst->mass == 3);
	assert(bst_lookup(bst,5));

	bst_add_node(bst,15);
	assert(bst->root->data == 10);
	assert(bst->mass == 4);
	assert(bst_lookup(bst,15));

	uint32_t* list = bst_postorder(bst);
	uint32_t ans[4] = {5,15,20,10};
	for(int j = 0; j<bst->mass; j++)
		assert(*(list+j) == ans[j]);
	
}

void test_min(){
	BST b = bst_new();
	BST *bst = &b;

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	assert(bst->mass == 1);

	bst_add_node(bst,20);
	assert(bst->root->data == 10);
	assert(bst->mass == 2);
	assert(bst_lookup(bst,20));

	bst_add_node(bst,5);
	assert(bst->root->data == 10);
	assert(bst->mass == 3);
	assert(bst_lookup(bst,5));

	bst_add_node(bst,15);
	assert(bst->root->data == 10);
	assert(bst->mass == 4);
	assert(bst_lookup(bst,15));

	assert(bst_min(bst) == 5);

}

void test_max(){
	BST b = bst_new();
	BST *bst = &b;

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	assert(bst->mass == 1);

	bst_add_node(bst,20);
	assert(bst->root->data == 10);
	assert(bst->mass == 2);
	assert(bst_lookup(bst,20));

	bst_add_node(bst,5);
	assert(bst->root->data == 10);
	assert(bst->mass == 3);
	assert(bst_lookup(bst,5));

	bst_add_node(bst,15);
	assert(bst->root->data == 10);
	assert(bst->mass == 4);
	assert(bst_lookup(bst,15));

	assert(bst_max(bst) == 20);

}

void test_asc(){
	BST b = bst_new();
	BST *bst = &b;

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	assert(bst->mass == 1);

	bst_add_node(bst,20);
	assert(bst->root->data == 10);
	assert(bst->mass == 2);
	assert(bst_lookup(bst,20));

	bst_add_node(bst,5);
	assert(bst->root->data == 10);
	assert(bst->mass == 3);
	assert(bst_lookup(bst,5));

	bst_add_node(bst,15);
	assert(bst->root->data == 10);
	assert(bst->mass == 4);
	assert(bst_lookup(bst,15));

	printf("ascending : \n");
	uint32_t* list = bst_inorder(bst);
	for(int j = 0; j<bst->mass; j++)
		printf("%d\t",*(list+j));
	printf("\n");

	uint32_t ans[4] = {5,10,15,20};
	for(int j = 0; j<bst->mass; j++)
		assert(*(list+j) == ans[j]);


}

void test_desc(){
	BST b = bst_new();
	BST *bst = &b;

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	assert(bst->mass == 1);

	bst_add_node(bst,20);
	assert(bst->root->data == 10);
	assert(bst->mass == 2);
	assert(bst_lookup(bst,20));

	bst_add_node(bst,5);
	assert(bst->root->data == 10);
	assert(bst->mass == 3);
	assert(bst_lookup(bst,5));

	bst_add_node(bst,15);
	assert(bst->root->data == 10);
	assert(bst->mass == 4);
	assert(bst_lookup(bst,15));

	uint32_t* list = bst_inorder(bst);
	printf("descending : \n");
	for(int j = (bst->mass-1); j>=0; j--)
		printf("%d\t",*(list+j));
	printf("\n");

	uint32_t ans[4] = {5,10,15,20};
	for(int j = (bst->mass-1); j>=0; j--)
		assert(*(list+j) == ans[j]);


}

void test_leaf(){
	BST b = bst_new();
	BST *bst = &b;

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	assert(bst->mass == 1);

	bst_add_node(bst,20);
	assert(bst->root->data == 10);
	assert(bst->mass == 2);
	assert(bst_lookup(bst,20));

	bst_add_node(bst,5);
	assert(bst->root->data == 10);
	assert(bst->mass == 3);
	assert(bst_lookup(bst,5));

	bst_add_node(bst,15);
	assert(bst->root->data == 10);
	assert(bst->mass == 4);
	assert(bst_lookup(bst,15));

	uint32_t l = bst_leaf(bst);
	//printf("number of leaf nodes : %d\n", l);
	assert(l == 2);	
}

void test_height(){
	BST b = bst_new();
	BST *bst = &b;

	bst_add_node(bst,10);
	assert(bst->root->data == 10);
	assert(bst->mass == 1);

	bst_add_node(bst,20);
	assert(bst->root->data == 10);
	assert(bst->mass == 2);
	assert(bst_lookup(bst,20));

	bst_add_node(bst,5);
	assert(bst->root->data == 10);
	assert(bst->mass == 3);
	assert(bst_lookup(bst,5));

	bst_add_node(bst,15);
	assert(bst->root->data == 10);
	assert(bst->mass == 4);
	assert(bst_lookup(bst,15));

	uint32_t ht = bst_height(bst);
	assert(ht == 3);
}

int main(){
	test_new();
	test_count();
	test_add_node();
	test_delete_node();
	test_inorder();
	test_preorder();
	test_postorder();
	test_min();
	test_max();
	test_asc();
	test_desc();
	test_leaf();
	test_height();
	return 1;
}
