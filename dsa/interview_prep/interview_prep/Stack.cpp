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

