#include "queue.h"

// Local notations :
struct __node {
  char data;
  struct __node *next;
  struct __node *prev;
};

// Basic functions for this type :
bool is_empty(const queue queue){
  return queue->next == NULL;
}

queue create_queue(void){
  struct __node *__node;
  __node = malloc(sizeof(struct __node));
  __node->next = NULL;
  __node->prev = __node;
  return __node;
}

void delete_queue(struct __node *__node){
  if(__node->next != NULL){
    delete_queue(__node->next);
  }
  free(__node);
  __node = NULL;
}

char top(const queue queue){
  assert(queue->next != NULL); // do not work with a sentinel
  return queue->next->data;
}

struct __node * push(struct __node *__node, char a){
  struct __node *new = malloc(sizeof(struct __node));
  new->data = a;
  new->next = NULL;         // ends the queue
  new->prev = __node->prev; // changes the last in the queue
  __node->prev->next = new;
  __node->prev = new;
  return __node;
}

struct __node *  pop(struct __node *__node){
  assert(__node->next != NULL); // do not pop an empty queue
  struct __node * to_delete = __node->next;
  __node->next = __node->next->next;
  __node->prev = __node;
  free(to_delete);
  return __node;
}

/*
void display_queue(struct __node *__node){
  fprintf(stdout, "QUEUE : %c ", __node->data);
  while((__node = __node->next) != NULL){
    fprintf(stdout, "'%c' ", __node->data);
  }
  fprintf(stdout, "\n");
}
*/
