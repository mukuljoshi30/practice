//
//  MaxProductOfThreeNums.cpp
//  interview_prep
//
//  Created by mukuljos on 9/4/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//
//Problem https://leetcode.com/problems/maximum-product-of-three-numbers/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //O(nlg(n)) solution
        int len = int(nums.size());
        sort(nums.begin(), nums.end());
        int prod1 = nums[0]*nums[1]*nums[len-1];
        int prod2 = nums[len-1]*nums[len-2]*nums[len-3];
        if(prod1 > prod2) {
            return prod1;
        }
        return prod2;
    }
    int maximumProductN(vector<int>& nums) {
        //O(n) solution
        int max1, max2, max3;
        int min1, min2;
        min1 = nums[0];
        min2 = nums[0];
        max1 = nums[0];
        max2 = nums[0];
        max3 = nums[0];
        for(vector<int> :: iterator itr = nums.begin(); itr != nums.end(); itr++) {
            if(*itr > max1) {
                max3 = max2;
                max2 = max1;
                max1 = *itr;
            } else if(*itr > max2) {
                max3 = max2;
                max2 = *itr;
            } else if(*itr > max3) {
                max3 = *itr;
            } else if(*itr < min1) {
                min2 = min1;
                min1 = *itr;
            } else if(*itr < min2) {
                min2 = *itr;
            }
        }
        int prod1 = max1*max2*max3;
        int prod2 = min1*min2*max1;
        if(prod1 > prod2) {
            return prod1;
        }
        return prod2;
    }
};
