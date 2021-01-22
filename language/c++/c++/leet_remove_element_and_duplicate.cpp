/*
 * Remove Element
 * https://leetcode.com/problems/remove-element/
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = 0;
        for(int i = 0; i<nums.size(); i++) {
            cout << nums[i] << length;
            if(nums[i]!=val){
                cout<< nums[i] << length;
                nums[length] = nums[i];
                length++;
            }
        }
        return length;
    }
};

/*
 *  Remove Duplicates from Sorted Array
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size()==1){
            return 1;
        }
        int prev = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if (prev == nums[i]) {
                nums[i] = 10001;
            } else {
                prev = nums[i];
            }
        }
        
        for (int i = 0; i<nums.size(); i++) {
            if(nums[i]==10001){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};
 