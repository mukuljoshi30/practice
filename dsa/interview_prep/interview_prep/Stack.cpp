//
//  Stack.cpp
//  interview_prep
//
//  Created by mukuljos on 9/3/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//

#include <iostream>
#include "Stack.h"
int main() {
    Stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.traverse();
    st.pop();
    st.traverse();
    return 0;
}


vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    map<string, int> stringCounts;
    std::map<string,int>::iterator it;
    for(vector<string> :: iterator itr = strings.begin(); itr != strings.end(); itr++) {
        it = stringCounts.find(*itr);
        if(it != stringCounts.end()){
            int count = it->second;
            stringCounts.erase(it);
            stringCounts.insert(pair<string, int>(*itr, ++count));
        } else {
            stringCounts.insert(pair<string, int>(*itr, 1));
        }
    }
    
}
