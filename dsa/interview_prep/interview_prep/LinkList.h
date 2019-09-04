//
//  link_list.h
//  interview_prep
//
//  Created by mukuljos on 4/3/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

using namespace std;

template <typename T>
struct node {
    T value;
    node<T>* next;
};

template <typename T>
class LinkList {
private:
    node<T>* head;
public:
    LinkList() {
        head = NULL;
    }
    bool insertNode(T vlaue);
    bool insertNodeWithNew(T value);
    void removeNode(T value);
    void removeNodeWithDelete(T value);
    void traverseLinkList();
    int findLengthItr();
    int findLengthRecursive(node<T> *);
    void getNthNode(int);
    void getNthNodeFromEnd(int);
    void findMiddleElement();
    bool isLoopInLinkList();
    int lengthLoopInLinkList();
    void reverseLinkList();
    node<T>* findTheBeginingOfLoop();
};

#endif /* LinkList_h */
