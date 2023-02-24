#include "list.h"
#include <stdio.h>

void test_init();
void test_add();
void test_find();
void test_remove();

int main() {
    test_init();
    test_add();
    test_find();
    test_remove();
    return 0;
}

void test_init() {
    struct door door = {1, 0};
    struct node* root = init(&door);
    if (root == NULL) {
        printf("INIT: FAIL\n");
        return;
    }
    if (root->doors.id != 1) {
        printf("INIT: FAIL\n");
        return;
    }
    if (root->doors.status != 0) {
        printf("INIT: FAIL\n");
        return;
    }
    if (root->next != NULL) {
        printf("INIT: FAIL\n");
        return;
    }
    printf("INIT: SUCCESS\n");
    destroy(root);
}

void test_add() {
    struct door door1 = {1, 0};
    struct node* root = init(&door1);
    struct door door2 = {2, 1};
    struct node* new_node = add_door(root, &door2);
    if (new_node == NULL) {
        printf("ADD: FAIL\n");
        return;
    }
    if (new_node->doors.id != 2) {
        printf("ADD: FAIL\n");
        return;
    }
    if (new_node->doors.status != 1) {
        printf("ADD: FAIL\n");
        return;
    }
    if (new_node->next != NULL) {
        printf("ADD: FAIL\n");
        return;
    }
    if (root->next != new_node) {
        printf("ADD: FAIL\n");
        return;
    }
    printf("ADD: SUCCESS\n");
    destroy(root);
}

void test_find() {
    struct door door1 = {1, 0};
    struct node* root = init(&door1);
    struct door door2 = {2, 1};
    add_door(root, &door2);
    struct node* found_door = find_door(2, root);
    if (found_door == NULL) {
        printf("FIND: FAIL\n");
        return;
    }
    if (found_door->doors.id != 2) {
        printf("FIND: FAIL\n");
        return;
    }
    if (found_door->doors.status != 1) {
        printf("FIND: FAIL\n");
        return;
    }
    if (found_door->next != NULL) {
        printf("FIND: FAIL\n");
        return;
    }
    printf("FIND: SUCCESS\n");
    destroy(root);
}

void test_remove() {
    struct door door1 = {1, 0};
    struct node* root = init(&door1);
    struct door door2 = {2, 1};
    struct node* new_node = add_door(root, &door2);
    root = remove_door(new_node, root);
    if (root->doors.id != 1) {
        printf("REMOVE: FAIL\n");
        return;
    }
    if (root->doors.status != 0) {
        printf("REMOVE: FAIL\n");
        return;
    }
    if (root->next != NULL) {
        printf("REMOVE: FAIL\n");
        return;
    }
    printf("REMOVE: SUCCESS\n");
    destroy(root);
}
