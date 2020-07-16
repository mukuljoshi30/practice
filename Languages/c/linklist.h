//
//  linklist.h
//  c
//
//  Created by mukuljos on 9/28/18.
//  Copyright © 2018 mukuljos. All rights reserved.
//

#ifndef linklist_h
#define linklist_h

#include <stdio.h>
typedef struct node_ {
    int value;
    struct node_* next;
} node;

typedef enum {
    NO_ERROR,
    NODE_NOT_EXIST,
    MALLOC_FAILED
} status;

node* create_node (node* head);
node* delete_node (node* head, int value);
void display_linklist (node* head);
node* create_node_auto (node* head, int value);

status add_node_dp(node** head, int value);
#endif /* linklist_h */
