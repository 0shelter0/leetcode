/**
 * id: 541 easy
 * leetcode: https://leetcode.cn/problems/reverse-string-ii/
 * carl: https://www.programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html
 * date: 9/21
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int i;
        for(i = 0; i < s.size()/(2*k); ++ i){
            int p = i * 2 * k;
            int q = p + k;
            reverse(s.begin() + p, s.begin() + q);
        }

        int reminder = s.size() % (2 * k);
        if(reminder < k){
            reverse(s.end() - reminder, s.end());
        }
        else{
            int p = i * 2 * k;
            int q = p + k;
            reverse(s.begin() + p, s.begin() + q);
        }
        return s;
    }
    
    // 高效写法: 把if判断放在for里面
    string reverseStr_v2(string s, int k) {
        for(int i = 0; i < s.size(); i += (2*k)){
            if(i + k <= s.size()){
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else{
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main(){
    string s = "abcdefg";
    Solution solution;
    string res = solution.reverseStr_v2(s, 2);
    cout << res << endl;
}