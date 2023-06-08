/**
 * id: 151 medium
 * leetcode: https://leetcode.cn/problems/reverse-words-in-a-string/
 * carl: https://www.programmercarl.com/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.html
 * date: 9/21
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    /**
     * example: "the sky is blue "
     * 移除多余空格 : "the sky is blue"
     * 字符串反转："eulb si yks eht"
     *  单词反转："blue is sky the"
    */
    string reverseWords(string s) {
        removeExtraSpaces(s);// 去掉空格
        reverse(s, 0, s.size() - 1); // 整体翻转

        //找到每个单词区间进行翻转
        int start = 0; //每个单词的起始下标
        for(int i = 0; i <= s.size(); ++ i){
            if(s[i] == ' ' || i == s.size()){
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }

    // 移除s中所有的空格，然后在单词之间添加空格
    // 利用双指针法
    void removeExtraSpaces(string& s) {
        int slow = 0;
        for(int fast = 0; fast < s.size(); ++ fast){
            if(s[fast] == ' '){
                continue;
            }
            else{// 只对非空格处理，则删掉所有空格
                if(slow != 0) s[slow ++] = ' '; // 如果不是第一个单词，则在之前加上空格
                // 补上该单词, 遇到空格单词结束
                while(fast < s.size() && s[fast] != ' '){
                    s[slow ++] = s[fast ++];
                }
            }
        }
        s.resize(slow);
    }

    // 对字符串 s 指定闭区间进行翻转
    void reverse(string& s, int left, int right){
        for(int i = left, j = right; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }
}; 


int main(){
    string s = " the sky is blue.   ";
    Solution solution;
    string res = solution.reverseWords(s);
    cout << res << endl;
}