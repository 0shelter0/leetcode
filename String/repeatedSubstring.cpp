/**
 * id: 454 easy
 * leetcode: https://leetcode.cn/problems/repeated-substring-pattern/
 * carl: https://www.programmercarl.com/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.html
 * date: 9/27
 * 
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 方法一：s+s 掐头去尾，寻找s
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        if(t.find(s) != std::string::npos) return true;
        return false;
    }

    // 方法二：最长相等前后缀不包含的子串就是最小重复子串 利用 next 数组
    void getNext(int* next, const string& s){//统一减一法
        // 初始化
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); ++ i){
            // 不相等的情况，j 回退
            while(j >= 0 && s[i] != s[j + 1]){
                j = next[j];
            }
            if(s[i] == s[j + 1]){
                j ++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern_v2(string s) {
        if(s.size() == 0){
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        int maxPostPre = next[len - 1] + 1;
        if (next[len - 1] != -1 && len % (len - maxPostPre) == 0) return true;
        return false;
    }
};

int main(){
    string s = "abababab";
    Solution sol;
    bool res = sol.repeatedSubstringPattern(s);
    cout << (res ? "true" : "false") << endl;
    return 0;
}