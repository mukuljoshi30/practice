//
//  selectionSort.cpp
//  interview_prep
//
//  Created by mukuljos on 5/4/20.
//  Copyright © 2020 mukuljos. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int selectionSort(vector<int> arr)
{
    int swaps = 0;
    int len = int(arr.size());
    int j = 0, temp = arr[0] , idx = 0;
    
    for(vector<int> :: iterator itr = arr.begin(); itr != arr.end(); itr++){
        cout << *itr << "  ";
    }
    cout << endl;
    for (j = 0; j<len-1; j++) {
        temp = arr[j];
        for (int i = j; i < len; i++) {
            if(temp > arr[i]) {
                temp = arr[i];
                idx = i;
            }
        }
        if(temp < arr[j]) {
            arr[idx] = arr[j];
            arr[j]   = temp;
            swaps++;
            cout << swaps << endl;
        }
    }
    
    for(vector<int> :: iterator itr = arr.begin(); itr != arr.end(); itr++){
        cout << *itr << "  ";
    }
    cout << endl;
    return swaps;
}

int main ()
{
    vector<int> data;
    
    data.push_back(2);
    data.push_back(6);
    data.push_back(8);
    data.push_back(3);
    data.push_back(5);
    data.push_back(7);
    data.push_back(1);
    data.push_back(8);
    data.push_back(1);
    data.push_back(5);
    data.push_back(9);
    data.push_back(15);
    
    
    cout << selectionSort(data);
    return 0;
}
