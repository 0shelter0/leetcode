/**
 * Is valid-anagram
 * id: 242 easy
 * leetcode: https://leetcode.cn/problems/valid-anagram/
 * carl solution: https://programmercarl.com/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.html
 * date: 9/15
 * **/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // 用数组作为哈希表，每一个字符将会被映射到数组下标，假设字符串中只有小写字符
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for(int i  = 0; i < s.size(); i++){
            int index = s[i] - 'a';
            record[index] ++;
        }
        
        for(int i = 0; i < t.size(); ++i){
            int index = t[i] - 'a';
            record[index] --;
        }

        for(int i = 0; i < sizeof(record)/sizeof(record[0]); ++ i){
            if(record[i] != 0)
                return false;
        }
        return true;
    }

    // 使用 unordered_map
    bool isAnagram_v2(string s, string t) {
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); ++ i){
            m[s[i]] ++;
        }
        for(int i = 0; i < t.size(); ++ i){
            m[t[i]] --;
        }
        for(auto it = m.begin(); it != m.end(); ++ it){
            if(it->second != 0) return false;
        }
        return true;
    }
};

int main(){
    string s = "anagram", t = "nagaram";
    Solution solution;
    bool res = solution.isAnagram(s, t);
    cout << res << endl;
    bool res2 = solution.isAnagram_v2(s, t);
    cout << res2 << endl;
}
