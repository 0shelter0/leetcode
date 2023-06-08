/**
 * spiral-matrix v1
 * id: 54 difficulty: medium
 * leecode: https://leetcode.cn/problems/spiral-matrix/
 * git solution: https://github.com/doocs/leetcode/tree/main/solution/0000-0099/0054.Spiral%20Matrix
 * date: 9/12/2022
 * **/

#include<iostream>
#include <vector>
using namespace std;

class Solution_defeat {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int count = m * n;
        vector<int> res(m * n, 0);
        int startX = 0, startY = 0;
        int i, j; //loop variables
        int offset = 1;
        while(count > 0){
            // top row: left -> row
            for(j = startY; j < n - offset; ++j){
                res.push_back(matrix[startX][j]);
                count --;
            }
            // right col: top -> bottom
            for(i = startX; i < m - offset; ++i){
                res.push_back(matrix[i][j]);
                count --;
            }
            for(; j > startY; --j){
                res.push_back(matrix[i][j]);
                count --;
            }
            for(; i > startX; --i){
                res.push_back(matrix[i][j]);
                count --;
            }
            startX ++;
            startY ++;
            offset ++;
        }
        cout << "count: " <<count<<endl;
        return res;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        vector<int> res;

        while(left <= right && top <= bottom){
            // top
            for(int j = left; j <= right; j++) res.push_back(matrix[top][j]);
            for(int i = top+1; i <= bottom; i++) res.push_back(matrix[i][right]);
            for(int j = right-1; j >= left; j--) res.push_back(matrix[bottom][j]);
            for(int i = bottom-1; i > top; i--) res.push_back(matrix[i][left]);
            ++ top;
            -- bottom;
            ++ left;
            -- right;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    vector<int> res = s.spiralOrder(matrix);
    for(int i = 0; i< res.size(); ++i){
        cout<<res[i]<<" ";
    }
    cout << endl;
}