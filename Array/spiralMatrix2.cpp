/**
 * spiral-matrix-ii
 * id: 59 difficulty: medium
 * leetcode: https://leetcode.cn/problems/spiral-matrix-ii/
 * carl solution: https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html
 * date: 9/12/2022
 * **/
//知识点： 构造for循环，坚持循环不变量原则, 坚持统一处理区间：左闭右开
// 1、处理流程：上行（从左到右）-> 右列（从上到下）->下行(right to left) -> 左列（down to up）,都是左闭右开原则，
// 每条边的最后一个元素作为下一个for的起点
// 2、注意：分奇偶去处理。if n is even: 直接执行 n/2 圈填数字。otherwise n is odd, 也执行 n/2 次 大圈循环，中间位置的元素单独处理
// 3、还需要定义每一圈的起点位置。

#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // initial result array
        int startX = 0, startY = 0; //start location of each loop
        int count = 1; // the values to fill
        int i, j; //loop variable, idx of row and column
        int loop = n / 2; // the number of rounds
        int offset = 1; // offset to right boundary

        while(loop --){
            // fill the top row: left to right
            for(j = startY; j < n - offset; ++j){ // n - offset is the Loop Invariant
                res[startX][j] = count ++;
            }
            // fill the right column: top to bottom
            for(i = startX; i < n - offset; ++i){
                res[i][j] = count ++;    
            }
            // fill the bottom row: right to left
            for(; j > startY; --j){
                res[i][j] = count ++;
            }
            // fill the left column: bottom to top
            for(; i > startX; --i){
                res[i][j] = count ++;
            }
            startX += 1;
            startY += 1;
            offset += 1;
        }
        // for n is odd: need to fill the single value at the center of martix   
        if (n % 2 != 0){
            int mid = n / 2; // center element coordinate is: (mid, mid)
            res[mid][mid] = n * n;
        }        
    return res;
    }
};

int main(){
    int n = 5;
    Solution s;
    vector<vector<int>> res = s.generateMatrix(n);

    int h = res.size(), w = res[0].size();
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}