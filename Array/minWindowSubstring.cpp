/****
 * minimum-window-substring
 * id: 76 difficulty: hard
 * leetcode: https://leetcode.cn/problems/minimum-window-substring/
 * github solution:
 * date: 9/12/2022
 * */
 
#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Solution1 超时
class Solution1 {
public:
    string minWindow(string s, string t, int & sublen) {
        int bestLength = INT32_MAX;
        string minSubstring = "";
        string res = "";
        int i = 0;
        for (int j = 0; j < s.size(); ++j){
            minSubstring.push_back(s[j]);
            while(isContained(minSubstring, t)){
                int sublen = j - i + 1;
                bestLength = bestLength < sublen ? bestLength : sublen;
                res = minSubstring;
                minSubstring.erase(minSubstring.begin());
                i ++;
            }
        }
        sublen = bestLength;
        return res;
    }

private:
    bool isContained(string src, string target){
        vector<int> tag(src.size(), 0);
        int count = 0;
        for(int i = 0; i < target.size(); ++i){
            bool is_found = false;
            for (int j = 0; j < src.size(); ++j){
                if(!tag[j] && src[j] == target[i]){
                    count += 1;
                    tag[j] = 1;
                    is_found = true;
                    break;
                }
            }
            if(!is_found) return false;                
        }
        return true;
    }

    bool isContained_v2(string src, string target){
        unordered_map<char, int> m;
        for(auto c : target){
            m[c] ++;
        }
        int counter = target.size(), size = src.size();
        for(int i = 0; i < size; ++i){
            if(m[src[i]] > 0)
                counter --;
                m[src[i]] --;
        }
        return counter == 0;
    }
};


class Solution2 {
public:
    string minWindow(string s, string t) {
        int begin = 0, end = 0;
        int minLength = INT32_MAX, counter = t.size(), minStart = 0;

        unordered_map<char, int> m;
        for(auto c : t){
            m[c] ++;
        }

        while(end < s.size()){//移动滑动窗口的终点
            if(m[s[end]] > 0) // 如果终点元素在字典里面出现，代表这个元素在t里面出现了一次
                counter --;
            m[s[end]] --; //注意这里不在if里面，为了与后面的m[s[begin]] ++;对应，表示无关元素不在t里面
            end ++;
            while(counter == 0){ //counter为0，代表找到了一个子串
                int subLength = end - begin;              
                if(subLength < minLength){
                    minStart = begin;
                    minLength = subLength;
                }
                //移动滑动窗口起点，找更短子串
                m[s[begin]] ++;
                if(m[s[begin]] > 0) // 判断begin位置的值是否出现在 t 里面，如果字典对应的value=0,代表无关字符
                    counter ++;

                begin ++;
            }
        }
        return minLength == INT32_MAX ? "" : s.substr(minStart, minLength); 
    }

};

int main(){
    string s = "ADOBECODEBANC", t = "ABC";
    Solution2 solution2;
    // int sublen = -1;
    // string res = solution1.minWindow(s, t, sublen);
    string res = solution2.minWindow(s, t);
    cout << res << endl;
    // cout << sublen << endl;
}