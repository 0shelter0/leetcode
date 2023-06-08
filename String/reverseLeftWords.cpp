/**
 * id: 剑指offer 58 easy
 * leetcode: https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 * carl: https://www.programmercarl.com/%E5%89%91%E6%8C%87Offer58-II.%E5%B7%A6%E6%97%8B%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html
 * date: 9/22
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    // 先整体翻转，再局部翻转
    string reverseLeftWords(string s, int n) {
        reverse(s, 0, s.size() - 1);
        reverse(s, 0, s.size() - n - 1);
        reverse(s, s.size() - n, s.size() - 1);
        return s;
    }

    // reverse 闭区间
    void reverse(string& s, int left, int right){
        for(int i = left, j = right; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }
};

int main(){
    string s = "abcdefg";
    int n = 2;
    Solution solution;
    string res = solution.reverseLeftWords(s, n);
    cout << res << endl;
}



