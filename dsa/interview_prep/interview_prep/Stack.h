//
//  Stack.h
//  interview_prep
//
//  Created by mukuljos on 9/3/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include <vector>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> stack;
    int top;
public:
    Stack() {
        top = -1;
    }
    void inline push(T element) {
        //stack[++top] = element;
        stack.push_back(element);
        top++;
        cout << "element pushed:: "<< element << endl << "Top:: "<< top << endl;
    }
    void inline pop() {
        if(top == -1) {
            cout << "Stack is empty, nothing to pop.";
            return;
        }
        stack.pop_back();
        cout << "element popped out:: " << stack[top] << endl << "Top:: " << top << endl;
        top--;
    }
    void traverse() {
        cout << "Top to Bottom traversal of the Stack" << endl;
        for(int i=top; i>=0 ;i--) {
            cout << stack[i] << endl;
        }
    }
    
};

#endif /* Stack_h */
