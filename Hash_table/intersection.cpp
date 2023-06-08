/**
 * id: 349 easy
 * leetcode: https://leetcode.cn/problems/intersection-of-two-arrays/
 * carl: https://programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html
 * date: 9/15
 * **/


#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset(nums1.begin(), nums1.end());
        unordered_set<int> intersection;
        for(int i = 0; i < nums2.size(); ++ i){
            if(uset.count(nums2.at(i))){
                intersection.emplace(nums2.at(i));
            }
        }
        vector<int> ans(intersection.begin(), intersection.end());
        return ans;
    }
};



int main(){
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    Solution s;
    vector<int> ans = s.intersection(nums1, nums2);

    for(auto& i : ans){
        cout << i << " "; // 2 1
    }
    cout << endl;
}