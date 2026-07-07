#include <iostream>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  int diameter_ = 0;
  inline int dfs(const TreeNode *node) {
    if (!node) [[unlikely]] {
      return 0;
    }
    const int left = dfs(node->left);
    const int right = dfs(node->right);
    const int candidate = left + right;
    if (candidate > diameter_) {
      diameter_ = candidate;
    }
    return (left > right ? left : right) + 1;
  }

public:
  int diameterOfBinaryTree(TreeNode *root) noexcept {
    dfs(root);
    return diameter_;
  }
};
