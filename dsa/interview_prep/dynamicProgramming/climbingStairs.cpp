//
//  climbingStairs.cpp
//  interview_prep
//
//  Created by mukuljos on 5/9/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//
#include <iostream>
#include <vector>
#include<iterator>

#define TOTALSTAIRS  6

using namespace std;

static vector<int> mem(TOTALSTAIRS+1);
static int steps = 0;

int stepCalculaor(int walkedSteps)
{
    steps++;
    if (walkedSteps == TOTALSTAIRS) {
        return 1;
    } else if (walkedSteps > TOTALSTAIRS) {
        return 0;
    }
    return stepCalculaor(walkedSteps + 1) + stepCalculaor(walkedSteps + 2);
}

int stepCalculaorMem(int walkedSteps)
{
    steps++;
    for (int i = 0; i<=6; i++){
        cout<< mem[i] << "\t";
    }
    cout << "\n";
    if (walkedSteps == TOTALSTAIRS) {
        mem[walkedSteps] = 1;
        return 1;
    } else if (walkedSteps > TOTALSTAIRS) {
        return 0;
    }
    if(mem[walkedSteps] == 0) {
        mem[walkedSteps] = stepCalculaorMem(walkedSteps + 1) + stepCalculaorMem(walkedSteps + 2);
    }
    return mem[walkedSteps];
}

int stairs (int n)
{
    if (n==1) return 1;
    if (n==2) return 2;
    return stairs(n-1) + stairs(n-2);
}

int main ()
{
    int totalNoOfWays = 0;
    totalNoOfWays = stepCalculaor(0);
    cout << "Total number of ways to cover the stairs 1: " << totalNoOfWays << "\t" << steps << endl;
    steps = 0;
    cout << "Total number of ways to cover the stairs 2: " << stairs(6) << endl;
    cout << "Total number of ways to cover the stairs 3: " << stepCalculaorMem(0) << "\t" << steps <<endl;
}
