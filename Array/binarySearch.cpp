/*
binary-search.cpp
data: 2022/9/11
id: 704 easy
leetcode: https://leetcode.cn/problems/binary-search/
carl solution: https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html
*/
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right){
            int middle = left + ((right - left) >> 1);
            if (nums[middle] >= target){
                right = middle;
            }else{ //右边
                left = middle + 1;
            }
        }
        if (left == nums.size() || nums[left] != target) return -1;
        return left;
    }
};

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;

    Solution solution;
    
    int pos = solution.search(nums, target);
    
    cout<< pos << endl;

    return 0;
}