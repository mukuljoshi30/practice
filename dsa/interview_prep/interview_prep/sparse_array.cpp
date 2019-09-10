//
//  sparse_array.cpp
//  interview_prep
//
//  Created by mukuljos on 9/4/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//
// Problem statement: https://www.hackerrank.com/challenges/sparse-arrays/problem

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    map<string, int> stringCounts;
    std::map<string,int>::iterator it;
    vector<int> results;
    for(vector<string> :: iterator itr = strings.begin(); itr != strings.end(); itr++) {
        it = stringCounts.find(*itr);
        if(it != stringCounts.end()){
            int count = it->second;
            stringCounts.erase(it);
            stringCounts.insert(pair<string, int>(*itr, ++count));
            //stringCounts[*itr] = ++count;
        } else {
            stringCounts.insert(pair<string, int>(*itr, 1));
            //stringCounts[*itr] = 1;
        }
    }
    for(vector<string> :: iterator itr = queries.begin(); itr != queries.end(); itr++) {
        results.push_back( stringCounts[*itr]);
    }
    return results;
}

