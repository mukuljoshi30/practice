//
//  cuttingRods.cpp
//  interview_prep
//
//  Created by mukuljos on 5/9/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//
/*
 * Given a rod of length nand prices P[j] for i = 1,...,n,
 * where P[i] is the price of the rod of length i.
 * Find the maximum total revenue you can make by cutting
 * and selling the rod (Assume no cost for cutting the rod).
 */

#include <iostream>
#include <vector>

using namespace std;
vector<int> value;

int max(int x, int y) {
    return (x>y)?x:y;
}
static int i2 = 0;
int maximumCost(int length)
{
    i2++;
    int maxCost = value[length-1];
    if (length == 1) {
        return value[0];
    }
    for (int i = 1; i< length; i++) {
        maxCost = max(maxCost, (maximumCost(length-i) + maximumCost(i)));
    }
    return maxCost;
}
static int i1 = 0;
int revenue(int n)
{
    i1++;
    if (n==0) {
        return 0;
    }
    int maxVal = -1;
    for (int i = 0; i< n; ++i) {
        int temp = value[n-i-1] + revenue(i);
        if(temp > maxVal) {
            maxVal = temp;
        }
    }
    return maxVal;
}

int revneueDP(int n) {
    vector<int> cost(n+1);
    cost[0] = 0;
    for (int i = 1; i<=n; i++) {
        int maxValue = -1;
        for (int j = 1; j<=i; j++) {
            int tempMax = value[j-1] + cost[i-j];
            if(tempMax > maxValue) {
                maxValue = tempMax;
            }
        }
        cost[i] = maxValue;
    }
    for(int i = 0; i<=n; i++) {
        cout << cost[i] << "\t";
    }
    cout << endl;
    return cost[n];
}

int main()
{
    value.push_back(1);
    value.push_back(5);
    value.push_back(8);
    value.push_back(9);
    value.push_back(10);
    /*for(int i =0; i<5; i++) {
        cout<< value[i];
    }*/
    int lenght = 5;
    cout << revenue(5) << "\t" << i1 << endl;
    cout << maximumCost(lenght)<< "\t" << i2 << endl;
    cout << revneueDP(lenght)<< "\t" << endl;
    return 0;
}
