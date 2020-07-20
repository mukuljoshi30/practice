//
//  main.c
//  c
//
//  Created by mukuljos on 9/28/18.
//  Copyright © 2018 mukuljos. All rights reserved.
//

#include <stdio.h>
#include "linklist.h"
int main(int argc, const char * argv[]) {
    node* head = NULL;
    int i;
    // insert code here...
    printf("Creating the linklist!\n");
    for(i=0; i<=10; i++){
        //head = create_node_auto(head, i);
        add_node_dp( &head, i);
    }
    printf("Display original linklist \n");
    display_linklist(head);
    printf("Deleting 7 from the list \n");
    head = delete_node(head, 7);
    printf("Linklist after deletion \n");
    display_linklist(head);
    return 0;
}
