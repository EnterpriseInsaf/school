#include <stdlib.h> 
#include "bst.h" 

BSTreeNode *bstree_create_node(int data) { 
    BSTreeNode *node = (BSTreeNode *) malloc(sizeof(BSTreeNode)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    
    return node; 
}