/**
 * id: 剑指offer 05 easy
 * leetcode: https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
 * carl: 
 * date: 9/21
 * **/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(char c : s){
            if(c == ' '){
                res += "%20";
            }
            else{
                res.push_back(c);
            }
        }
        return res;
    }

    // 空间高效写法：time o(n) space O(1)
    string replaceSpace_v2(string s) {
        int oldSize = s.size();
        int count = 0; // 统计空格的个数
        for(char c : s){
            if(c == ' ')
                count ++;
        }
        s.resize(s.size() + 2*count);
        int newSize = s.size();

        for(int i = newSize - 1, j = oldSize - 1; j < i; i --, j --){
            if(s[j] != ' '){
                s[i] = s[j];
            }
            else{
                s[i] = '0';
                s[i-1] = '2';
                s[i-2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

int main(){
    string s = "we are happy.";
    Solution solution;
    string res = solution.replaceSpace(s);
    cout << res << endl;
}