#include <iostream>

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
  inline int dfs(const TreeNode *node) {
    if (!node) {
      return 0;
    }
    const int left = dfs(node->left);
    if (left == -1) {
      return -1;
    }
    const int right = dfs(node->right);
    if (right == -1) {
      return -1;
    }
    if (std::abs(left - right) > 1) {
      return -1;
    }
    return (left > right ? left : right) + 1;
  }

public:
  bool isBalanced(TreeNode *root) { return dfs(root) != -1; }
};
