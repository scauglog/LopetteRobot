/*
** Becareful while using this file because malloc 
** used without checking its success.
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "common.h"

// In order to ease the use of queues :
struct __node;
typedef struct __node * queue;

bool is_empty(const queue);
queue create_queue(void);
void delete_queue(queue);
char top(const queue);
queue push(queue, char a);
queue pop(queue);
//void display_queue(queue);

#endif
