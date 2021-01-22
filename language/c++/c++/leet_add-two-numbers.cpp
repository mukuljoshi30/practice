//
//  leet_add-two-numbers.cpp
//  c++
//
//  Created by mukuljos on 1/5/21.
//  Copyright © 2021 mj. All rights reserved.
//

#include <iostream>

using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        struct ListNode* temp = l1, *temp1 = nullptr;
        while (l1 || l2) {
            if (l1 && l2) {
                l1->val+= l2->val;
                l1->val+= carry;
                l2 = l2->next;
            } else if (!l1) {
                l2->val+= carry;
                temp1->next = l2;
                l1 = l2;
                l2 = nullptr;
            } else if (!l2) {
                l1->val+= carry;
            }
            if(l1->val > 9) {
                l1->val = l1->val%10;
                carry = 1;
            } else {
                carry = 0;
            }
            temp1 = l1;
            cout << l1->val;
            l1=l1->next;
        }
        cout << carry;
        if (carry) {
            ListNode* x = new ListNode(carry);
            cout << x->val;
            temp1->next = x;
        }
        return temp;
    }
};
