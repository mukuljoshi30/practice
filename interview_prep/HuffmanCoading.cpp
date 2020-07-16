//
//  HuffmanCoading.cpp
//  interview_prep
//
//  Created by mukuljos on 9/9/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//  Problem statement: https://www.hackerrank.com/challenges/tree-huffman-decoding/problem
//

#include <iostream>
#include <string>

using namespace std;

typedef struct node {
    
    int freq;
    char data;
    node * left;
    node * right;
    
} node;

void decode_huff(node * root, string s) {
    int len = int(s.size());
    node* temp = root;
    for(int i =0; i<len; i++){
        if (s[i]=='0') {
            temp = temp->left;
        } else if(s[i] == '1') {
            temp = temp->right;
        }
        if (temp->left == NULL) {
            cout<<temp->data;
            temp = root;
        }
    }
}
