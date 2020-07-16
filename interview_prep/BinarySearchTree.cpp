//
//  BinarySearchTree.cpp
//  interview_prep
//
//  Created by mukuljos on 9/9/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

/*
 * to check if a given binary tree is BST
 */
vector<int> data;
void inorderTraversal(Node* root){
    if(!root){
      return;
    }
    inorderTraversal(root->left);
    data.push_back(root->data);
    inorderTraversal(root->right);
}

bool checkisVectorSorted() {
    for(int i = 0; i < data.size()-1; i++) {
        if(data[i] > data[i+1]) {
            return false;
        }
    }
    return true;
}

bool localProp(Node* root) {
    Node* temp = root;
    if(!temp) {
        return true;
    }
    if(temp->left) {
        if(temp->left->data > temp->data)
            return false;
    }
    if(temp->right){
        if(temp->right->data < temp->data)
            return false;
    }
    if (!localProp(temp->left)){
        return false;
    }
    if(!localProp(temp->right)){
        return false;
    }
    return true;
}
#if 0
bool checkBST(Node* root) {
    if(!localProp(root)) {
        return false;
    }
    if(!checkisVectorSorted()){
        return false;
    }
    return true;
}
#endif
/*
 * Problem statement: https://www.hackerrank.com/challenges/is-binary-search-tree/problem
 */

bool checkBST(Node* root, int minValue, int maxValue) {
    if (root == NULL) {
        return true;
    }
    
    if (root->data < minValue || root->data > maxValue) {
        return false;
    }
    
    return (    checkBST(root->left, minValue, root->data - 1)
            &&  checkBST(root->right, root->data + 1, maxValue)
            );
}

bool checkBST(Node* root) {
    return checkBST(root, 0, 10000);
}
