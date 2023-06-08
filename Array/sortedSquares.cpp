/**
 * squares-of-a-sorted-array
 * id: 977 easy
 * leetcode: https://leetcode.cn/problems/squares-of-a-sorted-array/
 * carl solution: https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html
 * data: 9/11/2022
 * **/
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
//使用头尾指针，因为最大的元素在两端，中间元素最小
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        for(int i = 0, j = nums.size()-1; i <=j;){
            if(nums[i]*nums[i] < nums[j]*nums[j]){
                res[k--] = nums[j]*nums[j];
                j--;
            }
            else{
                res[k--] = nums[i]*nums[i];
                i++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-4,-1,0,3,10}, res;
    Solution solution;
    res = solution.sortedSquares(nums);
    
    for(int i=0; i<res.size(); ++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}