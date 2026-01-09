#include <iostream>
#include <map>
#include <vector>

using namespace std;

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
  int height(TreeNode *root) {
    if (!root)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }

  TreeNode *lca(TreeNode *root, int level, int targetLevel) {
    if (!root) {
      return nullptr;
    }
    if (level == targetLevel) {
      return root;
    }
    TreeNode *left = lca(root->left, level + 1, targetLevel);
    TreeNode *right = lca(root->right, level + 1, targetLevel);
    if (left && right) {
      return root;
    }
    return left ? left : right;
  }

public:
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    int maxLevel = height(root);
    return lca(root, 1, maxLevel);
  }
};

int main() {

  // root = [3,5,1,6,2,0,8,null,null,7,4]
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  Solution sol;
  TreeNode *res = sol.subtreeWithAllDeepest(root);
  cout << "The value of the smallest subtree with all the deepest nodes is: "
       << res->val << endl;

  return 0;
}