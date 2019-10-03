#ifndef _INCLUDED_BST_
#define _INCLUDED_BST_

#include<stdint.h>

typedef struct _tree_node_ TreeNode; //individual nodes of the tree
typedef struct _bst_ BST; // entire tree

struct _tree_node_{
	int32_t data;
	TreeNode *left;
	TreeNode *right;
};

struct _bst_{
	TreeNode *root;
	uint32_t mass;
};

BST bst_new();
uint32_t bst_count(BST *tree);
BST* bst_add_node(BST *tree, int32_t ele);
BST* bst_delete_node(BST *tree, int32_t ele);
uint32_t bst_lookup(BST *tree, int32_t key);
uint32_t* bst_inorder(BST *tree);
uint32_t* bst_preorder(BST *tree);
uint32_t* bst_postorder(BST *tree);
void bst_levelorder(BST *tree);
uint32_t bst_height(BST *tree);
uint32_t bst_min(BST *tree);
uint32_t bst_max(BST *tree);
uint32_t bst_leaf(BST *tree);

#endif
