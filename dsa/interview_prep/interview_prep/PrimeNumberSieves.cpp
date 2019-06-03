//
//  PrimeNumberSieves.cpp
//  interview_prep
//
//  Created by mukuljos on 6/2/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//
//for(vector<int>::iterator itr = numbers.begin()+1; itr != numbers.end(); itr++) {
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    int range;
    cout << endl << "enter the range :: ";
    cin >> range;
    vector<int> numbers(range+1, 0);
    for(int i = 2; i <= numbers.size(); i++) {
        if (numbers[i] == 0) {
            for(int j = i + i; j<= numbers.size(); j += i) {
                numbers[j] = 1;
            }
        }
    }
    /*
     * Printing the prime numbers in the given range
     */
#if 0
    for(vector<int>::iterator itr = numbers.begin()+1; itr != numbers.end(); itr++) {
        if (*itr != 0) {
            cout << *itr << "\t";
        }
     }
#endif
    for (int i = 1; i<= numbers.size(); i++) {
        if (numbers[i] == 0) {
            cout << i << "\t";
        }
    }
    cout << endl;
     
    return 0;
}



