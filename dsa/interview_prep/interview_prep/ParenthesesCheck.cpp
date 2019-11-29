//
//  ParenthesesCheck.cpp
//  interview_prep
//
//  Created by mukuljos on 9/4/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//
//Problem description https://leetcode.com/problems/valid-parentheses/
// https://www.hackerrank.com/challenges/balanced-brackets/problem
#include <iostream>
#include <stack>

using namespace std;


    bool isValid(string s) {
        stack<char> par;
        for(int i = 0; i<s.length(); i++) {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[' ) {
                par.push(s[i]);
            } else if( (!par.empty()) && ((s[i] == '}' && par.top() == '{')
                      || (s[i] == ')' && par.top() == '(')
                      || (s[i] == ']' && par.top() == '['))){
                par.pop();
            } else {
                return false;
            }
        }
        if(par.empty()) {
            return true;
        }
        return false;
    }

int main () {
    string s = "]";
    cout << isValid(s) << endl;
    return 0;
}
