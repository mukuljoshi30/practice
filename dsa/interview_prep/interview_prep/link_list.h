//
//  link_list.h
//  interview_prep
//
//  Created by mukuljos on 4/3/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//

#ifndef link_list_h
#define link_list_h

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
};
/*
 * Insert a node in a link list
 */
template <typename T>
bool LinkList<T>:: insertNode(T value)
{
    node<T>* tempNode = malloc(sizeof(node<T>));
    if (!tempNode) {
        cout<< "malloc failed" << endl;
        return false;
    }
    tempNode->value = value;
    if (head == NULL) {
        head = tempNode;
        tempNode->next = NULL;
    } else {
        node<T> *temp = head;
        head = tempNode;
        tempNode->next = temp;
    }
    return true;
}
/*
 * Insert a linklist with alloc mentod
 * this function is halpful to handle the excetions
 */
template <typename T>
bool LinkList<T>:: insertNodeWithNew(T value)
{
    try {
        node<T>* tempNode = new node<T>;
        /*
         * for array allocation statemnt should be
         * node<T>* tempNode = new node<T> [10];
         * array size of 10 mentioned above
         */
        
        tempNode->value = value;
        if (head == nullptr) {
            head = tempNode;
            tempNode->next = nullptr;
        } else {
            node<T> *temp = head;
            head = tempNode;
            tempNode->next = temp;
        }
        return true;
    } catch(std:: bad_alloc &ba) {
        cout << "Can't allocate the memory" << ba.what();
        return false;
    }
}
/*
 * remove a node from the link list
 */
template <typename T>
void LinkList<T>:: removeNode(T value)
{
    if (!head) {
        cout << "LinkList is empty!" << endl;
    }
    node<T>* tempNode = head;
    node<T>* prevNode = head;
    while (tempNode) {
        if (tempNode->value == value) {
            prevNode->next = tempNode->next;
            free(tempNode);
            return;
        }
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
}
/*
 * removal with delete keyword
 */
template <typename T>
void LinkList<T>:: removeNodeWithDelete(T value)
{
    if (head == nullptr) {
        cout << "LinkList is empty!" << endl;
    }
    node<T>* tempNode = head;
    node<T>* prevNode = head;
    while (tempNode) {
        if (tempNode->value == value) {
            prevNode->next = tempNode->next;
            delete tempNode; //in case of array delete [] tempnode.
            return;
        }
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
}
/*
 * Link list traversal
 */
template <typename T>
void LinkList<T> :: traverseLinkList()
{
    node<T>* tempNode = head;
    while (tempNode) {
        cout << tempNode->svalue;
        tempNode = tempNode->next;
    }
}
/*
 * count the number of the nodes in the linklist
 * using for loop
 */
template <typename T>
int LinkList<T>:: findLengthItr()
{
    node<T>* tempNode = head;
    int count = 0;
    while (tempNode) {
        count++;
        tempNode = tempNode->next;
    }
    return count;
}
/*
 * count the number of the nodes in the linklist
 * using recursion
 */
template <typename T>
int LinkList<T>:: findLengthRecursive(node<T>* tempNode)
{
    if (!tempNode) {
        return 1;
    }
    return findLengthRecursive(tempNode->next) + 1;
}
/*
 * find the nth node from the begining
 */
template <typename T>
void LinkList<T>::getNthNode(int n)
{
    node<T>* node = head;
    int count = 1;
    while (node) {
        if (count++ == n) {
            cout << "find the n'th node \t value = " << node->value << endl;
            return;
        }
        node = node->next;
    }
    cout<< "there are less than n nodes in the list";
}
/*
 * find the nth node from the end
 */
template <typename T>
void LinkList<T>::getNthNodeFromEnd (int n)
{
    node<T>* tempNode = head;
    node<T>* node = head;
    int count = 1;
    while (tempNode) {
        if (count++ == n) {
           break;
        }
    }
    while (tempNode->next) {
        tempNode = tempNode->next;
        node = node->next;
    }
    cout << "n'th node from the end \t value = " << node->value << endl;
}
/*
 * HARE and Tortoise
 */
/*
 * find the mid node of the linklist
 */
template <typename T>
void LinkList<T>:: findMiddleElement()
{
    node<T>* fastNode = head;
    node<T>* slowNode = head;
    while (fastNode->next->next) {
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
    }
    cout << "Middle row value = " << slowNode->value;
}
/*
 * is loop present in the linklist
 */
template <typename T>
bool LinkList<T>:: isLoopInLinkList()
{
    node<T>* fastNode = head;
    node<T>* slowNode = head;
    while (fastNode->next->next) {
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
        if (fastNode == slowNode) {
            return true;
        }
    }
    return false;
}
/*
 * count the leangth of the loop
 */
template <typename T>
int LinkList<T>:: lengthLoopInLinkList()
{
    node<T>* fastNode = head;
    node<T>* slowNode = head;
    bool isLoop = false;
    while (fastNode->next->next) {
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
        if (fastNode == slowNode) {
            isLoop = true;
            break;
        }
    }
    int count = 0;
    if (isLoop) {
        do {
            count++;
            slowNode = slowNode->next;
        } while(slowNode != fastNode);
    }
    return count;
}
/*
 * reverse the linklist
 */
template <typename T>
void LinkList<T> :: reverseLinkList()
{
    node<T>* currentNode = head;
    node<T>* prevNode = NULL;
    node<T>* nextNode;
    while (currentNode) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
}
#endif /* link_list_h */
