/*
 * Hash Tables: Ice Cream Parlor
 *  https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem?h_l=interview&playlist_slugs%5B%5D=nutanix&page=1000
 * 
 */ 
  
#include <iostream>
#include <vector>
#include <map>

using namespace std;



// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
    map <int, int> mymap;
    for(int i = 0; i < int(cost.size()); i++){
        if (mymap.find(cost[i])!= mymap.end()){
            if(i < mymap.find(cost[i])->second) { //The comparison with i is only for priting point of view
                cout << i+1 << " " << mymap.find(cost[i])->second + 1 << endl;
            } else {
                cout <<  mymap.find(cost[i])->second + 1 << " " << i+1 << endl;
            }
            break;
        }
        int temp = money - cost[i];
        mymap.insert(pair<int, int>(temp, i));
    }
}


/*
 * Leet code:  Two Sum
 * https://leetcode.com/problems/two-sum/
 */
 class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> mymap;
        vector <int> result;
        for(int i=0; i<nums.size(); i++){
            if(mymap.find(nums[i]) != mymap.end()){
                result.push_back(i);
                result.push_back(mymap.find(nums[i])->second);
                break;
            }
            int rem = target - nums[i];
            mymap.insert(pair<int, int>(rem, i));
        }
        return result;
    }
};