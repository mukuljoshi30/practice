//
//  linklist.c
//  c
//
//  Created by mukuljos on 9/28/18.
//  Copyright © 2018 mukuljos. All rights reserved.
//

#include "linklist.h"
#include <stdlib.h>

/*
 * function to add a node in a link list.
 */
node* create_node(node* head)
{
    int value;
    node* new_node;
    printf("\nenter the value of the node\n");
    scanf("%d",&value);
    new_node = (node*) malloc(sizeof(node));
    if(!new_node) {
        printf("malloc fail");
        return NULL;
    }
    new_node->value = value;
    if (!head) {
        new_node->next = NULL;
        return new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    return head;
}

/*
 * function to add a node in a link list with predefined values
 */
node* create_node_auto(node* head, int value)
{
    node* new_node;
    new_node = (node*) malloc(sizeof(node));
    if(!new_node) {
        printf("malloc fail");
        return NULL;
    }
    new_node->value = value;
    if (!head) {
        new_node->next = NULL;
        return new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    return head;
}

/*
 * function to delete the node from the linklist
 * with matching value
 */
node* delete_node(node* head, int value)
{
    node* current, *prev;
    current = prev = head;
    while(current) {
        if(current->value == value) {
            if(current == head) {
                head = head->next;
                free(current);
                return head;
            } else {
                prev->next = current->next;
                free(current);
                return head;
            }
        }
        prev = current;
        current = current->next;
    }
    return head;
}

/*
 * function to display the values in the node
 */
void display_linklist(node* head)
{
    while(head){
        printf("value = %d \n", head->value);
        head = head->next;
    }
    return;
}

/*
 * adding linklist node using double pointer
 * [struct] <--- *head (temp) <----- **head (&temp)
 */
status add_node_dp(node** head, int value)
{
    node* temp = NULL;
    
    temp = (node*)malloc(sizeof(node));
    if(!temp){
        printf("malloc fail");
        return MALLOC_FAILED;
    }
    temp->value = value;
    temp->next = *head;
    *head = temp;
    return NO_ERROR;
}
