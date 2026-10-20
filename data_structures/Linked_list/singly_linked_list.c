/*
 * This is a simple implementation of a singly linked list.
 *
 * So, what is a singly linked list?
 * Unlike an array, a linked list does not store its elements
 * in one contiguous block of memory. Each element (node) is
 * allocated separately and holds a single pointer to the next
 * node, so the list can only be traversed in one direction,
 * from head to tail.
 *
 * In this example, each node stores a Task (priority, id, and
 * description). The list keeps track of both its head and tail,
 * so adding data at either end takes constant time. There is no
 * fixed capacity: the list grows one node at a time, and memory
 * is allocated only when a new task is added.
 *
 * This implementation demonstrates:
 * - Initializing a singly linked list
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
  struct Node *next;
} Node;

typedef struct {
  Node *head, *tail;
} SinglyLinkedList;

Node *create_node(int priority, int id, char desk[]) {
  Node *node = (Node*)malloc(sizeof(Node));
  if (node == NULL) {
    fprintf(stderr, "allocation memory has failed!\n");
    exit(EXIT_FAILURE);
  }

  node->task.priority = priority;
  node->task.id = id;

  strncpy(node->task.desk, desk, sizeof(node->task.desk) - 1);
  node->task.desk[sizeof(node->task.desk) - 1] = '\0';

  node->next = NULL;

  return node;
}

void append(SinglyLinkedList *sll, int priority, int id, char desk[]) {
  Node *new_node = create_node(priority, id, desk);
  if (!new_node) return;

  if (sll->head == NULL) {
    sll->head = new_node;
    sll->tail = new_node;

    return;
  }

  sll->tail->next = new_node;
  sll->tail = new_node;
}

void prepend(SinglyLinkedList *sll, int priority, int id, char desk[]) {
  Node *new_node = create_node(priority, id, desk);
  if (!new_node) return;

  if (sll->head != NULL) {
    new_node->next = sll->head;
    sll->head = new_node;

    return;
  }

  sll->head = new_node;
  sll->tail = new_node;
}

void show_list(SinglyLinkedList *sll) {
  Node *curr = sll->head;
  if (curr == NULL) {
    fprintf(stderr, "Node is NULL!\n"); return;
  }

  while (curr != NULL) {
    Node *next = curr->next;
    printf("priority: %d | id: %d | desk: %s\n",
        curr->task.priority, curr->task.id, curr->task.desk);

    curr = next;
  }
}

void delete_node(SinglyLinkedList *sll, int id) {
  Node *curr = sll->head;
  Node *prev = NULL;
  
  while (curr != NULL && curr->task.id != id) {
    prev = curr;
    curr = curr->next;
  }
  if (curr == NULL) return;

  if (curr == sll->head) {
    sll->head = curr->next;
    if (sll->head == NULL) {
      sll->tail = NULL;
    }
  }else if (curr == sll->tail) {
    sll->tail = prev;
    curr->next = NULL;
  }else {
    prev->next = curr->next;
  }
  free(curr);
}

void insert_at(SinglyLinkedList *sll, int priority, int id, int position, char desk[]) {
  if (position <= 0 ) {
    prepend(sll, priority,id, desk);
    return;
  }

  Node *curr = sll->head;
  int idx = 0;
  while (curr->next != NULL && idx < position - 1) {
    curr = curr->next;
    idx++;
  }

  if (curr == NULL) {
    append(sll, priority, id, desk);
    return;
  }

  Node *new_node = create_node(priority, id, desk);
  new_node->next = curr->next;
  curr->next = new_node;
  
  if (curr == sll->tail) {
    sll->tail = new_node;
  }
 }

void free_node(SinglyLinkedList *sll) {
  Node *curr = sll->head;

  while (curr != NULL) {
    Node *next = curr->next;
    free(curr);
    curr = next;
  }
  sll->head = NULL;
  sll->tail = NULL;

  printf("free node succesfully!\n");
}

int main(void) {

  SinglyLinkedList sll;
  //initialize node
  sll.head = NULL;
  sll.tail = NULL;

  append(&sll, 0, 1023, "hai ganteng");
  prepend(&sll, 1, 1024, "ini prepend");
  append(&sll, 2, 1022, "main yuu");
  insert_at(&sll, 1, 1045, 2, "ayuu");
  delete_node(&sll, 1024);
  show_list(&sll);

  free_node(&sll);

  return 0;
}
