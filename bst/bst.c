#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include<stdio.h>
#include "bst.h"

BST bst_new(){
	BST tree = {NULL,0};
	return tree;
}

TreeNode* new_node(int32_t ele){
	TreeNode *node =(TreeNode*)malloc(sizeof(TreeNode));
	node->data = ele;
	node->left = NULL;
	node->right = NULL;
	return node;
}

uint32_t bst_count(BST *tree){
	assert(tree!=NULL);
	return tree->mass;
}

uint32_t bst_lookup(BST *tree, int32_t key){
	assert(tree!=NULL);
	TreeNode *cur = tree->root;

	while(cur!=NULL && cur->data!=key)
		if(key<cur->data)
			cur = cur->left;
		else if(key>cur->data)
			cur = cur->right;
	return(cur!=NULL);
}

BST* bst_add_node(BST *tree, int32_t ele){
	assert(tree!=NULL);
	TreeNode *cur, *parent;
	cur = parent = tree->root;

	while(cur!=NULL && cur->data!=ele){
		parent = cur;
		if(ele<cur->data)
			cur = cur->left;
		else if(ele>cur->data)
			cur = cur->right;
	}

	if(cur == NULL){
		TreeNode *tnode = new_node(ele);
		if(parent == NULL)
			tree->root = tnode;
		else if(ele<parent->data)
			parent->left = tnode;
		else if(ele>parent->data)
			parent->right = tnode;
		++tree->mass;
	}
	return tree;
}

static TreeNode* _findmin_(TreeNode *node){
	if(node->left == NULL)
		return node;
	else
		return(_findmin_(node->left));
}

static TreeNode* _delete_(BST *tree, TreeNode *node, int32_t key){
	TreeNode *temp;

	if(node == NULL)
		return node;
	else if(key<node->data)
		node->left = _delete_(tree, node->left, key);
	else if(key>node->data)
		node->right = _delete_(tree, node->right, key);
	else if(node->left && node->right){
		temp = _findmin_(node->right);
		node->data = temp->data;
		node->right = _delete_(tree, node->right, node->data);
	}
	else{
		temp = node;
		if(node->right== NULL)
			node = node->left;
		else
			node = node->right;
		free(temp);
		--tree->mass;
	}
	return node;
}


BST* bst_delete_node(BST *tree, int32_t ele){
	assert(tree!=NULL);

	tree->root = _delete_(tree, tree->root, ele);

	return tree;
}

static void _inorder_(TreeNode* node, int32_t *l, int32_t *i){
	if(node){
			_inorder_(node->left, l, i);
			l[(*i)++] = node->data;
			//printf("%d\t",node->data);
			_inorder_(node->right, l, i);
	}
}

uint32_t* bst_inorder(BST *tree){
	assert(tree->root!=NULL);
	uint32_t *list = (int32_t*)malloc(tree->mass);
	uint32_t i = 0;
	_inorder_(tree->root, list, &i);
	//for(int j = 0; j<tree->mass; j++)
	//	printf("%d\t",list[j]);
	return list;
	
}

static void _preorder_(TreeNode* node, int32_t *l, int32_t *i){
	if(node){
			l[(*i)++] = node->data;
			_preorder_(node->left, l, i);
			//printf("%d\t",node->data);
			_preorder_(node->right, l, i);
	}
}

uint32_t* bst_preorder(BST *tree){
	assert(tree->root!=NULL);
	uint32_t *list = (int32_t*)malloc(tree->mass);
	uint32_t i = 0;
	_preorder_(tree->root, list, &i);
	//for(int j = 0; j<tree->mass; j++)
	//	printf("%d\t",list[j]);
	return list;
	
}

static void _postorder_(TreeNode* node, int32_t *l, int32_t *i){
	if(node){
			_postorder_(node->left, l, i);
			//printf("%d\t",node->data);
			_postorder_(node->right, l, i);
			l[(*i)++] = node->data;
	}
}

uint32_t* bst_postorder(BST *tree){
	assert(tree->root!=NULL);
	uint32_t *list = (int32_t*)malloc(tree->mass);
	uint32_t i = 0;
	_postorder_(tree->root, list, &i);
	//for(int j = 0; j<tree->mass; j++)
	//	printf("%d\t",list[j]);
	return list;
	
}

uint32_t bst_min(BST *tree){
	assert(tree->root!=NULL);
	TreeNode *t = tree->root;
	while(t->left!=NULL)
		t = t->left;
	return t->data;
}

uint32_t bst_max(BST *tree){
	assert(tree->root!=NULL);
	TreeNode *t = tree->root;
	while(t->right!=NULL)
		t = t->right;
	return t->data;
}

void _count_leaf_(TreeNode *node,uint32_t *leaf){
	if(node){
		if(node->left == NULL && node->right==NULL)
			++(*leaf);
		
		_count_leaf_(node->left,leaf);
		_count_leaf_(node->right,leaf);
	}
}

uint32_t bst_leaf(BST *tree){
	assert(tree->root!=NULL);
	uint32_t leaf =0 ;
	_count_leaf_(tree->root,&leaf);
	//printf("%d\n", leaf);
	return leaf;
}

uint32_t _height_(TreeNode *node){
	if(!node)
		return 0;
	else{
		uint32_t lheight = _height_(node->left);
		uint32_t rheight = _height_(node->right);
		
		if(lheight > rheight)
			return lheight+1;
		else
			return rheight+1;
	}
}

uint32_t bst_height(BST *tree){
	return _height_(tree->root);
}
