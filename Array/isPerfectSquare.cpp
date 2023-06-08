/*
valid-perfect-square
id: 367 easy
data: 9/11/2022
leetcode: https://leetcode.cn/problems/valid-perfect-square/
solution: https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0367.Valid%20Perfect%20Square/README.md
*/
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num-1;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if (mid*mid > num){
                right = mid-1;
            }
            else if (mid*mid < num){
                left = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }

    /**
     * 转换为数学问题：n^2 = 1 + 3+ 5+..+(2n-1),num不断减去i(i=1,3,5,...)，如果num==0，return true
     * 时间复杂度：O(sqrt(N))
     * **/
    bool isPerfectSquare_v2(int num){
        // for (int i=1; i<= 2*num-1; i+=2){
        //     num -= i;
        //     if(num <=0)break;
        // }
        for(int i=1; num>0; i+=2){
            num -= i;
        }
        return num == 0;
    }
};

int main(){
    int num = 255;
    Solution solution;
    bool res = solution.isPerfectSquare_v2(num);
    cout<<res<<endl;
}