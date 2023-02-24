#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node *init(struct door *doors) {
  struct node *root = (struct node *)malloc(sizeof(struct node));
  root->doors = *doors;
  root->next = NULL;
  return root;
}

struct node *add_doors(struct node *elem, struct door *doors) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->doors = *doors;
  new_node->next = elem->next;
  elem->next = new_node;
  return new_node;
}

struct node *find_doors(int doors_id, struct node *root) {
  struct node *current = root;
  while (current != NULL) {
    if (current->doors.id == doors_id) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

struct node *remove_doors(struct node *elem, struct node *root) {
  struct node *current = root;
  struct node *previous = NULL;
  while (current != elem) {
    previous = current;
    current = current->next;
  }
  if (previous != NULL) {
    previous->next = current->next;
  } else {
    root = current->next;
  }
  free(current);
  return root;
}

void destroy(struct node *root) {
  struct node *current = root;
  struct node *next = current->next;
  while (current != NULL) {
    free(current);
    current = next;
    if (next != NULL) {
      next = next->next;
    }
  }
}
