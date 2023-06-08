/**
 * minimum-size-subarray-sum
 * id: 209 difficulty: medium
 * leetcode: https://leetcode.cn/problems/minimum-size-subarray-sum/
 * carl: https://programmercarl.com/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.html
 * date: 9/11/2022
 * **/

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //采用滑动窗口的方法，时间复杂度O(N)，空间复杂度O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        int bestLength = INT32_MAX; //最短长度
        int sum = 0; // 子序列的数值和
        int subLength; //当前子序列长度
        int i = 0; //滑动窗口 的起点
        for (int j = 0; j < nums.size(); j++){
            sum += nums[j]; //累加终点值
            while(sum >= target){// 动态调整起点
                subLength = j - i + 1;
                bestLength = bestLength < subLength ? bestLength: subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置
            }
        }
        return bestLength == INT32_MAX ? 0 : bestLength;
    }
};


int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    Solution solution;
    int res = solution.minSubArrayLen(target, nums);
    cout << res << endl;
    return 0;
}