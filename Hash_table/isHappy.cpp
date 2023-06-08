/**
 * id: 202 easy
 * leetcode: https://leetcode.cn/problems/happy-number/
 * carl: https://programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html
 * date: 9/15
 * **/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    // 使用set记录sum是否重复出现， sum重复出现代表陷入无限循环。
    bool isHappy(int n) {
        int m = n;
        unordered_set<int> sum_set;
        while(m != 1){
            int sum = 0;
            while(m){
                int x = m % 10;
                m = m / 10;
                sum += x * x;
            }
            if(sum_set.count(sum)){
                return false;
            }
            else{
                sum_set.emplace(sum);
            }
            m = sum;
        }
        return true;
    }
};

int main(){
    int n = 1;
    Solution s;
    bool res = s.isHappy(n);
    if(res)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}