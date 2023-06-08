/**
 * id: 344 easy
 * leetcode: https://leetcode.cn/problems/reverse-string/
 * carl: https://www.programmercarl.com/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html
 * date: 9/21 
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    // 时间复杂度：O(n) 空间：O(1)
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            //Option1: 三数交换
            // char tmp = s[left];
            // s[left] = s[right];
            // s[right] = tmp;

            //Option2：库函数
            // swap(s[left], s[right]);

            //Option3：位运算
            s[left] ^= s[right]; // a = a^b
            s[right] ^= s[left]; // b = b^a^b = a
            s[left] ^= s[right]; // a = a^b^a = b

            left ++;
            right --;
        }
    }
};

int main(){
    vector<char> s = {'h', 'e', 'l', 'l', '0'};
    Solution solution;
    solution.reverseString(s);

    for(char c : s){
        cout<<c<<" ";
    }
    cout << endl;
}