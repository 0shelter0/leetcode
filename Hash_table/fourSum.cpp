/**
 * 4sum
 * id: 18 medium
 * leetcode: https://leetcode.cn/problems/4sum/
 * carl:https://www.programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html
 * date: 9/20
 * */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    // 与三数之和思路一样，多套了一层for循环，剪枝表达式也有变化
    // 外两个层循环的和不变，内循环left和right寻找nums[k]+nums[i]+nums[left]+nums[right]==target
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size(); ++ k){
            // 剪枝
            if(nums[k] > target && nums[k] >= 0 )
                break;
            //对 nums[k] 去重
            if(k > 0 && nums[k] == nums[k-1])
                continue;
            for(int i = k + 1; i < nums.size(); ++ i){
                // 二级剪枝
                if(nums[k] + nums[i] > target && nums[k] + nums[i] >=0)
                    break;
                //对 nums[i] 去重
                if(i > k+1 && nums[i] == nums[i-1])
                    continue;

                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right){
                    // 这里相加会溢出，需要使用 long
                    if((long) nums[k] + nums[i] + nums[left] + nums[right] > target) right --;
                    else if((long) nums[k] + nums[i] + nums[left] + nums[right] < target) left ++;
                    else{
                        res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对left，right 去重
                        while(right > left && nums[left] == nums[left+1]) left ++;
                        while(right > left && nums[right] == nums[right-1]) right --;
                        left ++;
                        right --;
                    }
                }
                
            }
        }
        return res;
    }
};

int main(){
    // vector<int> nums = {1,0,-1,0,-2,2};
    // int target = 0;
    vector<int> nums = {2,2,2,2,2};
    int target = 8;
    Solution s;
    vector<vector<int>> res = s.fourSum(nums, target);

    for(int i = 0; i<res.size(); ++i){
        for(int j = 0; j<res[0].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
