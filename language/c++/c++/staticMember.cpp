//
//  staticMember.cpp
//  c++
//
//  Created by mukuljos on 7/21/20.
//  Copyright © 2020 mj. All rights reserved.
//
/*
 * 1. There is only one copy of a static data member exists
 *    irrespective of the number of object created,
 * 2. When a static data member is declared in the class it is not defined.
 *    we have to define a global defination of it outrside the class globally.
 *
 */
#include <iostream>
using namespace std;
class shared {
    static int a;
    int b;
public:
    void set(int i, int j) {a=i; b=j;}
    void show();
} ;

int shared::a; // definining a static variable

void shared::show()
{
    cout << "This is static a: " << a;
    cout << "\nThis is non-static b: " << b;
    cout << "\n";
}

int main()
{
    shared x, y;
    x.set(1, 1); // set a to 1
    x.show();
    y.set(2, 2); // change a to 2
    y.show();
    x.show(); /* Here, a has been changed for both x and y
               because a is shared by both objects. */
    return 0;
}

/*
 * static member function
 * 1. only directly refer to other static members of the class
 * 2. global functions and data may be accessed by static member functions
 * 3. There cannot be a static and a non-static version of the same function
 * 4. A static member function does not have a this pointer.
 * 5. A static member function may not be virtual.
 * 6. Static function cannot be declared as const or volatile.
 */

/*
 * static member functions have limited applications, but one good use
 * for them is to "preinitialize" private static data before
 * any object is actually created.
 */
#if 0

#include <iostream>
using namespace std;
class static_type {
    static int i;
public:
    static void init(int x) {i = x;}
    void show() {cout << i;}
};
int static_type::i; // define i
int main()
{
    // init static data before object creation
    static_type::init(100);
    static_type x;
    x.show(); // displays 100
    return 0;
}

#endif

