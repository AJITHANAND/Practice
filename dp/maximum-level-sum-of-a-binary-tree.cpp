#include <iostream>
#include <vector>
using namespace std;

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
  void levelOrderRec(TreeNode *root, int level, vector<int> &levelSum) {
    if (root == nullptr) {
      return;
    }
    if (level == levelSum.size()) {
      levelSum.push_back(0);
    }

    levelSum[level] += root->val;
    levelOrderRec(root->left, level + 1, levelSum);
    levelOrderRec(root->right, level + 1, levelSum);
  }

public:
  int maxLevelSum(TreeNode *root) {
    vector<int> levelSum;
    levelOrderRec(root, 0, levelSum);

    int maxSum = levelSum[0];
    int idx = 0;
    for (int i = 0; i < levelSum.size(); i++) {
      if (levelSum[i] > maxSum) {
        maxSum = levelSum[i];
        idx = i;
      }
    }
    return idx;
  }
};

int main() {

  // root = [1,7,0,7,-8,null,null]

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(7);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(-8);
  Solution sol;
  int result = sol.maxLevelSum(root);
  cout << "Result: " << result << endl;
  return 0;
}