/**
 * id: 15 medium
 * leetcode: https://leetcode.cn/problems/3sum/
 * solution: 
 * date: 9/16
 * **/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    /**时间复杂度 O(n^2)
     * 1、将数组升序
     * 2、i是循环变量，left = i+1, right = size - 1
     * 3、a = nums[i] b = nums[left] c = nums[right] 对 a 去重
     * 4、a + b + c < 0  left ++
     * 5、a + b + c > 0  right --
     * 6、a + b + c = 0 保存结果 对 b 和 c 去重
     * **/
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int left = 0, right = nums.size() - 1;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0) // 对 a > 0 剪枝
                return result;
            // 对 a 去重
            if(i > 0 && nums[i] == nums[i-1])
                continue;
    
            left = i + 1;
            right = nums.size() - 1;
            // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
            // while(left < right && nums[i] + nums[left] + nums[right] > 0) right --;
            // while(left < right && nums[i] + nums[left] + nums[right] < 0) left ++;
            while(left < right){
                // while(left < right && nums[i] + nums[left] + nums[right] > 0) right --;
                // while(left < right && nums[i] + nums[left] + nums[right] < 0) left ++;
                if(nums[i] + nums[left] + nums[right] > 0) right --;
                else if(nums[i] + nums[left] + nums[right] < 0) left ++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 对 b 和 c 去重
                    while(left < right && nums[left] == nums[left+1]) left ++;
                    while(left < right && nums[right] == nums[right-1]) right --;

                    // 找到答案，同时缩减 left 和 right
                    left ++;
                    right --;
                }
            }
            
        }
        return result;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> res;
    res = s.threeSum(nums);

    for(int i = 0; i<res.size(); ++i){
        for(int j = 0; j<res[0].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}