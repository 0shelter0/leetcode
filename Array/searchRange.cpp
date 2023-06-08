/*
find-first-and-last-position-of-element-in-sorted-array
leetcode link: https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
github solution: https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0034.Find%20First%20and%20Last%20Position%20of%20Element%20in%20Sorted%20Array/README.md
example: Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4]
data: 2022.09.09
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // using STL, runtime complexity O(logn), space: O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin();
        if(l == nums.size() or l >= r) return {-1, -1};
        return {l, r-1};
    }

    // using Bisection Search naively
    vector<int> searchRange_v2(vector<int>& nums, int target) {
        int l = search_lower_bound(nums, target);
        int r = search_lower_bound(nums, target+1);
        if (l == nums.size() || l >= r) return {-1, -1};
        return {l, r-1};
    }

private:
    int search_lower_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size();
        
        while(left < right){
            int mid = (left + right) >> 1;
            cout<<mid<<endl;

            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

};

int main()
{
    vector<int> nums = {}; 
    int target = 8;
    Solution* solution = new Solution;
    vector<int> res = solution->searchRange_v2(nums, target);
    

    for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
        {
            cout << *iter << " ";
        }

    cout<<endl;
    int a = -1 >> 1;

    cout << a <<endl; //-1

    return 0;
}