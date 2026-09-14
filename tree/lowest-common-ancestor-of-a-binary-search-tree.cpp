#include <cassert>
#include <iostream>
#include <vector>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return nullptr;
    }

    while (root) {
      if (q->val < root->val && p->val < root->val) {
        root = root->left;
      } else if (q->val > root->val && p->val > root->val) {
        root = root->right;
      } else {
        return root;
      }
    }
    return nullptr;
  }
};

int main() {

  /*
  Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    Output: 6
  */
  Solution solution;
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);

  root->right = new TreeNode(8);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  TreeNode *p = root->left;  // Node with value 2
  TreeNode *q = root->right; // Node with value 8

  TreeNode *lca = solution.lowestCommonAncestor(root, p, q);
  if (lca) {
    assert(lca->val == 6); // Expected output is 6
    std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;
  } else {
    std::cout << "Lowest Common Ancestor not found." << std::endl;
  }

  TreeNode *p2 = root->left;        // Node with value 2
  TreeNode *q2 = root->left->right; // Node with value 4

  TreeNode *lca2 = solution.lowestCommonAncestor(root, p2, q2);
  if (lca2) {
    assert(lca2->val == 2); // Expected output is 2
    std::cout << "Lowest Common Ancestor: " << lca2->val << std::endl;
  } else {
    std::cout << "Lowest Common Ancestor not found." << std::endl;
  }

  return 0;
}