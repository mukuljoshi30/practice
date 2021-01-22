/*
 * https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/
 */
#include <iostream>
#include <vector>
 using namespace std;
 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int tl = l1+l2;
        int midVal = 1;
        if(tl%2 == 0) {
            midVal = 2;
        }
        tl = tl/2;
        int temp1= 0, temp = 0, j = 0, k = 0;
        if(l1 == 0 && l2==0) {
            return 0;
        } else if (l1 == 0) {
            int l = l2/2;
            temp = nums2[l];
            if(l != 0) {
                temp1 = nums2[l-1]; 
            }
        } else if (l2==0) {
            int l = l1/2;
            temp = nums1[l];
            if(l != 0) {
                temp1 = nums1[l-1]; 
            } 
        } else {
            for(int i = 0; i<=tl; i++) {
                temp1 = temp;
                if (j<l1 && k<l2){
                    if(nums1[j]<nums2[k]){
                        temp = nums1[j];
                        j++;
                    } else {
                        temp = nums2[k];
                        k++;
                    }
                }else if (j<l1) {
                    temp = nums1[j++];
                }else {
                    temp = nums2[k++];
                }
                //cout << "i:" << i << " temp:" << temp<<" temp1:"<<temp1<< endl;
            }
        }
        if(midVal == 1) {
            return temp;
        }
        return ((temp +temp1)/2.0);
    }
};