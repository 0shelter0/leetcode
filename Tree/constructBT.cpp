/**
 * 给一个 leetcode 标准数组，利用这个数组构建二叉树的结构。
 * ref: https://blog.csdn.net/chenzhanqi/article/details/126634332
 * date: 9.27
*/

#include<bits/stdc++.h>
#include "traversal.h"

using namespace std;

#define DEBUG

// 例：二叉树 [1,2,2,3,3,null,null,4,4]
// vector<string> nodes = { "1","2","2","3","3","null","null","4","4" };
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };

// 构造一般二叉树的算法
TreeNode* constructBT(vector<string>& vec){
    int len = vec.size();
    if(len == 0 || vec[0] == "null"){
        return nullptr;
    }
    //添加末尾省略的空右孩子节点, 方便处理
    if(len % 2 ==0){
        vec.push_back("null");
    }
    // 用队列来实现，头节点进队，按照层次遍历
    queue<TreeNode*> nodesQue;
    TreeNode* root = new TreeNode(stoi(vec[0]));
    nodesQue.push(root);

    for(int i = 1; i < len; i += 2){
        TreeNode* node = nodesQue.front();
        nodesQue.pop();
        //获取队首节点的左右孩子
        string left = vec[i];
        string right = vec[i+1];

        if(left == "null"){
            node->left = nullptr;
        }
        else{
            node->left = new TreeNode(stoi(left));
            nodesQue.push(node->left);
        }

        if(right == "null"){
            node->right = nullptr;
        }
        else{
            node->right = new TreeNode(stoi(right));
            nodesQue.push(node->right);
        }
    }
    return root;
}

// 构造完全二叉树的递归写法

int main(){
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    vector<string> vec;
    string s;
    while (cin >> s)
    {
        vec.push_back(s);
    }
    cout << "二叉树的数组表示为：" << endl;
    for(string s : vec){
        cout << s << " ";
    }
    cout << endl;

    TreeNode* root = constructBT(vec);
    Traversal traversal;
    traversal.max_(1,1);

    int _max = traversal.max_(3, 4);
    cout << "_max: " << _max << endl; 

    // vector<vector<int>> result = traversal.levelorder(root);

    // for(int i = 0; i < result.size(); i ++){
    //     for(int j = 0; j < result[0].size(); j++){
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // } 
    return 0;
}
