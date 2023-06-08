/***
 * id: 1 easy
 * leetcode: https://leetcode.cn/problems/two-sum/
 * solution: 
 * date: 9/16
 * **/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int n : nums){
            umap[n] ++;
        }

        int subValue;
        for(int n : nums){
            subValue = target - n;
            if(subValue ==  n)
                umap[subValue] --;
            if(umap[subValue] > 0){
                umap[subValue] --;
                break;
            }               
        }
        
        int index1 = -1, index2 = -1;
        for(int i = 0; i < nums.size(); ++i){
            if(subValue == nums.at(i)){
                index2 = i;
                break;
            }
        }

        for(int i = 0; i < nums.size(); ++i){
            if(target - subValue == nums.at(i) && index2 != i){
                index1 = i;
                break;
            }
        }
        vector<int> res;
        res.push_back(index1);
        res.push_back(index2);
        return res;
    }


    // 1. 使用map 存放访问过的元素
    // 2. map 中的 key 用来存放元素值，方便查询是否访问过， value 用来存放对应的 下标。
    vector<int> twoSum_v2(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); ++ i){
            // 找符合条件的数对
            int subValue = target - nums.at(i);
            // if(umap.count(subValue))
            //     return {i, umap[subValue]};
            // 替代写法
            unordered_map<int, int>::iterator it = umap.find(subValue);
            if(it != umap.end())
                return {i, it->second};

            //把访问过的元素加入map
            umap.emplace(pair<int, int>(nums.at(i), i));

        }
        // 没有找到返回空集合
        return {};
    }
};

int main(){
    vector<int> nums = {3,2,4};
    int target = 6;
    Solution s;
    vector<int> res = s.twoSum_v2(nums, target);
    for(int num : res){
        cout << num << " ";
    }
    cout << endl;
}
