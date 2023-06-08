#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Traversal {
public:
    Traversal();
    std::vector<int> postorderTraversal(TreeNode* root);
    void traversal(TreeNode* cur, std::vector<int>& vec);
    std::vector<std::vector<int>> levelorder(TreeNode* root);
    int max_(int a, int b);
};

#endif