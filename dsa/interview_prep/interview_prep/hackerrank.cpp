//
//  hackerrank.cpp
//  interview_prep
//
//  Created by mukuljos on 9/28/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * Problem: Minimum distances
 * URL: https://www.hackerrank.com/challenges/minimum-distances/problem
 */
int minimumDistances(vector<int> a) {
    map<int, int> values;
    int minDistance = -1;
    int i = 0;
    for (vector<int>::iterator itr = a.begin(); itr != a.end(); itr++, i++) {
        if(values.find(*itr) != values.end()){
            //not found
            int distance = i - values.find(*itr)->second;
            if(minDistance > distance || minDistance == -1) {
               minDistance = distance;
            }
        }
        values[*itr] = i;
    }
    return minDistance;
}

/*
 * Problem: Arrays: Left Rotation
 * URL: https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
 */
vector<int> rotLeft(vector<int> a, int d) {
    vector<int> temp(d);
    long n = a.size();
    long i;
    for(i=0; i<d; i++){
        temp[i] = a[i];
    }
    for(long j = d, i=0; j< n; j++,i++) {
        a[i] = a[j];
    }
    for(long i = 1; i<= d; i++){
        a[n-i] = temp[d-i];
    }
    return a;
}

#if 0
/*
 * Problem: Bigger is Greater
 * URL: https://www.hackerrank.com/challenges/bigger-is-greater/problem
 */
string biggerIsGreater(string w) {
    int length = int (w.size());
    for (int i = length-2; i>=0; i--) {
        if(w[i] < w[i+1]) {
            sort(i+1, length-1, ); //complete this function
        }
    }
    return NULL;
}
#endif

/*
 * Problem: Sherlock and Array
 * URL: https://www.hackerrank.com/challenges/sherlock-and-array/problem?h_r=internal-search
 * logic: suppose each side's sum = X
 *        total sum of the array = sum and middle element = Y
 *        2x + y = sum
 *        so we need to findout X and Y solution for this sum
 */
string balancedSums(vector<int> arr) {
    int sum = 0;
    int len = int(arr.size());
    /*
     * Calculate sum
     */
    for(int i=0; i<len; i++) {
        sum += arr[i];
    }
    int x = 0;
    int y;
    for(int i=0; i<len; i++) {
        y = arr[i];
        if((sum-y)==(2*x)) {
            return "YES";
        }
        x = x + arr[i];
    }
    return "NO";
}

int main ()
{
    vector<vector<int> > queries;
    vector<int> data;
    vector<int> data1;
    vector<int> data2;
    vector<int> data3;
    data.push_back(2);
    data.push_back(6);
    data.push_back(8);
    data1.push_back(3);
    data1.push_back(5);
    data1.push_back(7);
    data2.push_back(1);
    data2.push_back(8);
    data2.push_back(1);
    data3.push_back(5);
    data3.push_back(9);
    data3.push_back(15);
    queries.push_back(data);
    queries.push_back(data1);
    queries.push_back(data2);
    queries.push_back(data3);
    
    vector<int> minDist;
    minDist.push_back(7);
    minDist.push_back(1);
    minDist.push_back(3);
    minDist.push_back(4);
    minDist.push_back(1);
    minDist.push_back(7);
    //cout << minimumDistances(minDist);
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    cout << balancedSums(arr1) << endl;
    vector<int> arr2;
    arr2.push_back(1);
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(3);
    cout << balancedSums(arr2) << endl;
    
    return 0;
}
