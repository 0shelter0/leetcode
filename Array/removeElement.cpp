/*
remove-element
id: #27
leetcode: https://leetcode.cn/problems/remove-element/
Carl: https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html
github: https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0027.Remove%20Element/README.md
data: 2022/9/10
*/
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // solution1: slow & fast pointer
    // time complexity: O(n)
    // memory complexity: O(1) in-place operation
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
            if(val != nums[fastIndex]){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }

    // solution2: count total times of val
    // time complexity: O(n)
    // memory complexity: O(1) in-place operation
    int removeElement_v2(vector<int>& nums, int val) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; ++i){
            if(nums[i] == val){
                ++count;
            }
            else{
                nums[i-count] = nums[i];
            }
        }
        return n-count;
    }

    //using Opposite pointers: left and right pointers, changed the relative order of elements in original array.
    // time complexity: O(n)
    // memory complexity: O(1) in-place operation
    int removeElement_v3(vector<int>& nums, int val){
        int left = 0, right = nums.size() - 1;
        while(left <= right ){
            // step 1: find the element equal to `val` at the left side.
            while(left <= right && val != nums[left]){
                left++;
            }
            // step 2: find the element not equal to `val` at right side.
            while(left <=right && val == nums[right]){
                right--;
            }
            // setp 3: 把右边不等于val的元素覆盖到左边等于val的位置
            if (left < right){
                nums[left++] = nums[right--];
            } 
            
        }
        
        return left;
    }
};

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution solution;
    
    int new_len = solution.removeElement(nums, val);
    cout << new_len << ", nums = ";
    for(int i = 0; i < new_len; ++i){
        cout<<nums[i]<<" ";
    }
    cout << endl;

    return 0;
}