/* 
* remove-duplicates-from-sorted-array
* label: #26 /easy problem
* github: https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
* official solution: 
* data: 2022/9/11
*/
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 0, n = nums.size();
        for (int fastIndex = 0; fastIndex < n; fastIndex++){
            while(fastIndex < n && nums[fastIndex] == nums[slowIndex]){
                fastIndex ++;
            }
            nums[++slowIndex] = nums[fastIndex];
        }
        return slowIndex + 1;
    }

    int removeDuplicates_v2(vector<int>& nums){
        int i = 0;
        for(int& num: nums){
            if(i<1 || num != nums[i-1])
                nums[i++] = num;
        }
        return i;
    }

    int removeDuplicates_v3(vector<int>& nums){
        vector<int>::iterator pos = unique(nums.begin(), nums.end());
        nums.erase(pos, nums.end());
        return nums.size();
    }
};

int main(){
    vector<int> nums = {1,1,2};
    //{0,0,1,1,1,2,2,3,3,4};

    Solution solution;
    
    int new_len = solution.removeDuplicates(nums);
    cout << new_len << ", nums = ";
    for(int i = 0; i < new_len; ++i){
        cout<<nums[i]<<" ";
    }
    cout << endl;

    return 0;
}