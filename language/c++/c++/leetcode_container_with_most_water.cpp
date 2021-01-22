/*
 * Container With Most Water
 * https://leetcode.com/problems/container-with-most-water/
 * */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = height.size()-1;
        int i = 0;
        int max = 0;
        while(i<j){
            int area = min(height[i], height[j])*(j-i);
            max = (max > area)? max : area;
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max;        
    }
};