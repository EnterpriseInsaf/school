#ifndef LIST_H
#define LIST_H

struct door {
  int id;
  int status;
};

struct node {
  struct door doors;
  struct node *next;
};

struct node *init(struct door *doors);
struct node *add_door(struct node *elem, struct door *doors);
struct node *find_door(int doors_id, struct node *root);
struct node *remove_door(struct node *elem, struct node *root);
void destroy(struct node *root);
#endif
