//
//  New_Year_Chaos.cpp
//  interview_prep
//
//  Created by mukuljos on 9/21/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//
/*
 * Problem URL: https://www.hackerrank.com/challenges/new-year-chaos/problem
 * Problem URL: https://www.hackerrank.com/challenges/crush/problem
 */

#include <iostream>
#include <vector>


using namespace std;

void swap(vector<int> &q, int i, int j) {
    int temp = q[i];
    q[i] = q[j];
    q[j] = temp;
}

int calculateBribe() {
    int arr[] = {1, 2, 5, 3, 7, 8, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> q(arr, arr + n);
    int len = int(q.size()-1);
    int bribeCount = 0;
    for(int i = len; i>=0; i--) {
        //case 1: when everything this is fine
        // q[i] == i+1
        //do nothing in that case
        if( q[i] != i+1){
            //case 2: when 1 place difference
            if ((i-1 >= 0) && (q[i-1] == (i+1))) {
                swap(q, i, i-1);
                bribeCount++;
            } else if(((i-2) >= 0) && (q[i-2] == i+1)) { // when 2 places are different
                swap(q, i-2, i-1);
                swap(q, i, i-1);
                bribeCount += 2;
            } else {
                cout << "Too chaotic" << endl;
                return 0;
            }
        }
    }
    cout << bribeCount << endl;
    return 0;
}

template <typename T>
void printVector(vector<T> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

/*
 * Problem URL: https://www.hackerrank.com/challenges/crush/problem
 * prefix sum algorithm
 */
long arrayManipulation(int n, vector<vector<int> > queries) {
    vector<long> arr(n+1, 0);
    cout << queries.size()<<endl;
    for (int i = 0; i<= queries.size()-1; i++){
        cout << queries[i][0] << queries[i][1] << queries[i][2] << endl << i;
        arr[queries[i][0]] = arr[queries[i][0]] + queries[i][2];
        if((queries[i][1]+1) <= n)
            arr[queries[i][1]+1] = arr[queries[i][1]+1] - queries[i][2];
    }
    long max = arr[0];
    for (int i = 1; i<= n; i++) {
        arr[i] = arr[i] + arr[i-1];
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
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

    cout << arrayManipulation(10, queries);
    return 0;
}
