//
//  QuickSort.cpp
//  interview_prep
//
//  Created by mukuljos on 4/11/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//
#include <iostream>
#include <vector>
#include<iterator>

using namespace std;

void printVector(vector<int> arr)
{
    for (vector<int> :: iterator itr = arr.begin(); itr != arr.end(); itr++) {
        cout << *itr << "\t";
    }
    cout << endl;
}

void swap(int &i, int &j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}
/*
 * this function will work very well when all the elements are distincts
 * if 2 elements are same it will fall into the loop
 * for such scenerio we have to use partitionVectorAllCases
 */
void partitionVector(vector<int> &arr, int pivot)
{
    int left = 0;
    int right = int (arr.size())-1;
    if (arr.empty() == true) {
        cout<<"Array is empty" << endl;
        return;
    }

    do {
        if (arr[left] > pivot) {
            swap(arr[left], arr[right]);
            right --;
        }
        if (arr[right] < pivot) {
            swap(arr[left], arr[right]);
            left++;
        }
        if(arr[left] < pivot) {
            left++;
        }
        if (arr[right] > pivot ) {
            right--;
        }
        printVector(arr);
    } while(left<right);
    
}
/*
 * Partition the array if we have equal values
 * this also called dutch flag partition.
 */
void partitionVectorAllCases(vector<int> &arr, int pivot)
{
    int left = 0, equal= 0;
    int right = int (arr.size())-1;
    if (arr.empty() == true) {
        cout<<"Array is empty" << endl;
        return;
    }
    
     while (equal<=right) {
        if (arr[equal] < pivot) {
            swap(arr[left++], arr[equal++]);
        } else if (arr[equal] == pivot) {
            equal++;
        } else {
            swap(arr[right--], arr[equal]);
        }
        cout << left << "\t" << equal << "\t" << right << endl;
        printVector(arr);
     }
    
}


int partitionVectorQuickSort(vector<int> &arr, int left , int right)
{
    int pivot = arr[left];
    
    do {
        if (arr[left] > pivot) {
            swap(arr[left], arr[right]);
            right --;
        }
        if (arr[right] < pivot) {
            swap(arr[left], arr[right]);
            left++;
        }
        if(arr[left] < pivot) {
            left++;
        }
        if (arr[right] > pivot ) {
            right--;
        }
    } while(left<right);
    return left;
}

void quickSort(vector<int> &arr, int left, int right)
{
    if(left>right) {
        return;
    }
    int pivot = partitionVectorQuickSort(arr, left, right);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);
}


int main()
{
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(30);
    arr.push_back(21);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(50);
    arr.push_back(60);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(0);
    arr.push_back(10);
    printVector(arr);
    //partitionVector(arr,10);
    partitionVectorAllCases(arr, 5);
    //quickSort(arr, 0, int(arr.size()-1));
    printVector(arr);
    return 0;
}
