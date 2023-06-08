/**
 * 二叉树的前中后遍历
 * id: 145 easy
 * leetcode: https://leetcode.cn/problems/binary-tree-postorder-traversal/
 * carl: https://www.programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html
 * date: 9/24
*/
#include "traversal.h"
// Traversal
Traversal::Traversal(){

}

int Traversal::max_(int a, int b){
    return a > b ? a : b;
}
// vector<int> Solution::postorderTraversal(TreeNode* root) {
//     vector<int> result;
//     traversal(root, result);
//     return result;
// }

/**递归的要素
 * 1. 确定递归参数、返回值
 * 2. 确定出口条件
 * 3. 确定单层递归的逻辑
*/
void Traversal::traversal(TreeNode* cur, vector<int>& vec){
    if(cur == NULL)  return;
    this->traversal(cur->left, vec);
    this->traversal(cur->right, vec);
    vec.push_back(cur->val);
}

// 层序遍历：levelorder 非递归实现 一层一层的保存
vector<vector<int>> Traversal::levelorder(TreeNode* root){
    vector<vector<int>> result;
    queue<TreeNode*> que;
    if(root != NULL) que.push(root);
    while(!que.empty()){
        int size = que.size();
        vector<int> vec;           
        for(int i = 0; i < size; i ++){
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if(node->left) que.push(node->left); // 非空节点不入队
            if(node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}
