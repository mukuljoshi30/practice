//
//  memoryAllocation.cpp
//  c++
//
//  Created by mukuljos on 7/30/20.
//  Copyright © 2020 mj. All rights reserved.
//

#include <iostream>
#include <new>
using namespace std;
int main()
{
    int *p;
    try {
        p = new int (87); // initialize to 87
    } catch (bad_alloc xa) {
        cout << "Allocation Failure\n";
        return 1;
    }
    cout << "At " << p << " ";
    cout << "is the value " << *p << "\n";
    delete p;
    return 0;
}

/*
 * In Standard C++ it is possible to have new return null instead of throwing an exception
 * when an allocation failure occurs.
 */
// Demonstrate nothrow version of new.

#if 0

#include <iostream>
#include <new>
using namespace std;
int main()
{
    int *p, i;
    p = new(nothrow) int[32]; // use nothrow option
    if(!p) {
        cout << "Allocation failure.\n";
        return 1;
    }
    for(i=0; i<32; i++) p[i] = i;
    for(i=0; i<32; i++) cout << p[i] << " ";
    delete [] p; // free the memory
    return 0;
}

#endif

