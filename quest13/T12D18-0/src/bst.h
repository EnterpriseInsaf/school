#ifndef BST_H 
#define BST_H 

typedef struct BSTreeNode { int data; struct BSTreeNode *left; struct BSTreeNode *right; } BSTreeNode; 
BSTreeNode *bstree_create_node(int data); 

#endif