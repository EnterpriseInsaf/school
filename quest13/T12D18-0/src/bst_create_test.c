#include <stdio.h>
#include "bst.h"

int main() {
    BSTreeNode *node1 = bstree_create_node(5);
    printf("Node 1 data: %d\n", node1->data);

    BSTreeNode *node2 = bstree_create_node(10);
    printf("Node 2 data: %d\n", node2->data);

    return 0;
}