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
  inline bool isSame(const TreeNode *src, const TreeNode *dest) {
    if (!src && !dest) {
      return true;
    }
    if (!src || !dest) {
      return false;
    }
    return (src->val == dest->val) && (isSame(src->left, dest->left)) &&
           isSame(src->right, dest->right);
  }

public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!root) {
      return false;
    }
    return isSame(root, subRoot) || isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
  }
};