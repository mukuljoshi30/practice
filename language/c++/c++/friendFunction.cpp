//
//  friendFunction.cpp
//  c++
//
//  Created by mukuljos on 7/20/20.
//  Copyright © 2020 mukuljos. All rights reserved.
//

/*
 * A friend function has access to all private and protected members
 * of the class for which it is a friend
 * 1. friends can be useful when you are overloading certain types of operators
 * 2. friend functions make the creation of some types of I/O functions easier
 * 3. two or more classes may contain members that are interrelated relative to other parts of the program.
 */
#include <iostream>
using namespace std;
class myclass {
    int a, b;
public:
    friend int sum(myclass x);
    void set_ab(int i, int j);
};
void myclass::set_ab(int i, int j)
{
    a = i;
    b = j;
}
// Note: sum() is not a member function of any class.
int sum(myclass x)
{
    /* Because sum() is a friend of myclass, it can
     directly access a and b. */
    return x.a + x.b;
}
int main()
{
    myclass n;
    n.set_ab(3, 4);
    cout << sum(n);
    return 0;
}

