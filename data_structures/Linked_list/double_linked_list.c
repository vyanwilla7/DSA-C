/*
 * This is a simple implementation of a doubly linked list.
 *
 * So, what is a doubly linked list?
 * Unlike an array, a linked list does not store its elements
 * in one contiguous block of memory. Each element (node) is
 * allocated separately and holds pointers to both the next
 * and the previous node, so the list can be traversed in
 * either direction.
 *
 * In this example, each node stores a Task (priority, id, and
 * description). The list keeps track of both its head and tail,
 * so adding data at either end takes constant time. There is no
 * fixed capacity: the list grows one node at a time, and memory
 * is allocated only when a new task is added.
 *
 * This implementation demonstrates:
 * - Initializing a doubly linked list
 * - Creating nodes
 * - Adding data (append, prepend, insert at a position)
 * - Displaying data
 * - Deleting data by id
 * - Freeing allocated memory
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int priority, id;
  char desk[128];
} Task;

typedef struct Node {
  Task task;
  struct Node *next, *prev;
} Node;

typedef struct {
  Node *head, *tail;
} DoubleLinkedList;

Node *create_node(int priority, int id, const char desk[]) {
  Node *node = (Node*)malloc(sizeof(Node));
  if (node == NULL) {
    fprintf(stderr, "allocation memort has failed!\n");
    exit(EXIT_FAILURE);
  }

  node->task.priority = priority;
  node->task.id = id;

  strncpy(node->task.desk, desk, sizeof(node->task.desk) - 1);
  node->task.desk[sizeof(node->task.desk) - 1] = '\0';

  node->next = NULL;
  node->prev = NULL;

  return node;
}

void append(DoubleLinkedList *dll, int priority, int id, const char desk[]) {
  Node *new_node = create_node(priority, id, desk);
  if (!new_node) return;

  if (dll->head == NULL) {
    dll->head = new_node;
    dll->tail = new_node;

    return;
  }

  new_node->prev = dll->tail;
  dll->tail->next = new_node;
  dll->tail = new_node;
}

void prepend(DoubleLinkedList *dll, int priority, int id, const char desk[]) {
  Node *new_node = create_node(priority, id, desk);
  if (!new_node) return;

  if (dll->head != NULL) {
    new_node->next = dll->head;
    dll->head->prev = new_node;
    dll->head = new_node;

    return;
  }

  dll->head = new_node;
  dll->tail = new_node;
}

void show_list(DoubleLinkedList *dll) {
  Node *curr = dll->head;

  if (curr == NULL) {
    fprintf(stderr, "list is NULL!\n"); return;
  }

  while (curr != NULL) {
    printf("prio: %d | id: %d | desk: %s\n",
        curr->task.priority, curr->task.id, curr->task.desk);

    curr = curr->next;

  }
}

void delete_node(DoubleLinkedList *dll, int id) {
  Node *curr = dll->head;

  while (curr != NULL && curr->task.id != id) {
    curr = curr->next;
  }

  if (curr == NULL) return;

  if (curr->next != NULL) {
    curr->next->prev = curr->prev;
  }else {
    dll->tail = curr->prev;
  }

  if (curr->prev != NULL) {
    curr->prev->next = curr->next;
  }else {
    dll->head = curr->next;
  }

  free(curr);
}

void insert_at(DoubleLinkedList* dll, int position, int priority, int id, const char desk[]) {
  if (position <= 0) {
    prepend(dll, priority, id, desk);
    return;
  }

  Node *curr = dll->head;
  int i = 0;

  while  (curr != NULL && position > i) {
    curr = curr->next;
    i++;
  }

  if (curr == NULL) {
    append(dll, priority, id, desk);
    return;
  }

  Node *new_node = create_node(priority, id, desk);
  new_node->next = curr;
  new_node->prev = curr->prev;

  if (curr->prev != NULL) {
    curr->prev->next = new_node;
  }
  curr->prev = new_node;
}

void free_node(DoubleLinkedList *dll) {
  Node *curr = dll->head;

  while (curr != NULL) {
    Node *next = curr->next;
    free(curr);
    curr = next;
  }

  dll->head = NULL;
  dll->tail = NULL;

  printf("free node succesfully!\n");

}

int main(void) {

  DoubleLinkedList dll;
  dll.head = NULL;
  dll.tail = NULL;

  append(&dll, 1, 123, "makan duls");
  prepend(&dll, 2, 124, "udah mas");
  prepend(&dll, 0, 125, "makan lagi");
  insert_at(&dll, 1, 4, 126, "insert node");
  delete_node(&dll, 123);
  show_list(&dll);

  free_node(&dll);

  return 0;
}
