/**
 * id: 454 medium
 * leetcode: https://leetcode.cn/problems/4sum-ii/
 * solution: https://programmercarl.com/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.html
 * date: 9/16
 * **/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // 暴力法：O(n^2) i + k + j + l == 0 => i + k = -(j+l)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int res = 0;
        int i, j, k, l;
        unordered_map<int, int> map1, map2;
        for(i  = 0; i < n; ++ i){
            for(j = 0; j < n; ++ j){
                int sum1 = nums1[i] + nums2[j];
                map1[sum1] ++;
            }
        }
         for(k  = 0; k < n; ++ k){
            for(l = 0; l < n; ++ l){
                int sum2 = nums3[k] + nums4[l];
                map2[sum2] ++;
                // alternative solution
                if(map1.find(-sum2) != map1.end()){
                    res += map1[-sum2];
                }
            }
        }
        // for(auto it = map1.begin(); it != map1.end(); ++ it){
        //     int opposite = it->first * -1;
        //     unordered_map<int, int>::iterator it2 = map2.find(opposite);
        //     if(it2 != map2.end()){
        //         res += it->second * it2->second; 
        //     }
        // }
        return res;
    }
};

int main(){
    vector<int> nums1={1,2}, nums2={-2,-1}, nums3={-1,2}, nums4={0,2};
    // vector<int> nums1={0}, nums2={0}, nums3={0}, nums4={0};
    Solution s;
    int res = s.fourSumCount(nums1, nums2, nums3, nums4);
    cout << res << endl;
}
