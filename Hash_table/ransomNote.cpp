/**
 * id: 383 easy
 * leetcode: https://leetcode.cn/problems/ransom-note/
 * solution: https://programmercarl.com/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.html
 * **/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        if(ransomNote.length() > magazine.length())
            return false;

        for(char c : magazine){
            record[c - 'a'] ++;
        }
        for(char c : ransomNote){
            record[c - 'a'] --;
            if(record[c - 'a'] < 0)
                return false;
        }
        // for(int i = 0; i < 26; ++ i){
        //     if(record[i] < 0)
        //         return false;
        // }
        return true;
    }
};

int main(){
    string ransomNote = "fihjjjjei", magazine = "hjibagacbhadfaefdjaeaebgi";
    Solution s;
    bool res = s.canConstruct(ransomNote, magazine);
    if(res)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}