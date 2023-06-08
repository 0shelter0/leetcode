/**
 * KMP 模式匹配算法
 * id: 28 medium
 * leetcode: 
 * carl: https://www.programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html
 * date: 9/22
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    // 用前缀表统一减一来实现
    int strStr(string haystack, string needle) {
        if (needle.size() == 0){
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle); // 求 模式串 的前缀表
        int j = -1; // j指向模式串的开始，并且初始化为next 的第一个元素
        for(int i = 0; i < haystack.size(); ++ i){ // i指向文本串
            // 1.不匹配则回退到上一个已经匹配的位置
            while(j >=0 && haystack[i] != needle[j+1]){
                j = next[j];
            }
            // 2. 匹配则i、j都往前一步
            if(haystack[i] == needle[j+1]){
                j ++; // i++ 在for里面
            }
            // 3. 判断结束条件
            if(j == needle.size() - 1){
                return i - needle.size() + 1;
            }
        }
        return -1;
    }

    // 求 next 数组
    void getNext(int* next, const string& s){
        // 1.初始化
        int j = -1; //前缀末尾
        next[0] = j;
        // 求每一个位置的最长相等前后缀的长度
        for(int i = 1; i < s.size(); ++ i){
            // 2. 前后缀不相等的情况
            while(j >=0 && s[i] != s[j+1]){ // 持续回退，但是j==-1时退出
                j = next[j];
            }
            // 3. 前后缀相等的情况
            if(s[i] == s[j+1]){
                j ++;
            }
            next[i] = j; // next等于前缀的长度
        }
    }
};

int main(){
    string haystack = "aabaabaafa", needle = "aabaaf";
    Solution s;
    int res = s.strStr(haystack, needle);
    cout << res << endl;
}