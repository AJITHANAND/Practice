#include <bitset>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

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
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return nullptr;
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
};

TreeNode *buildTree(const std::vector<int> &vals) {
  if (vals.empty())
    return nullptr;
  TreeNode *root = new TreeNode(vals[0]);
  std::queue<TreeNode *> q;
  q.push(root);
  size_t i = 1;
  while (i < vals.size()) {
    TreeNode *node = q.front();
    q.pop();
    if (i < vals.size()) {
      node->left = new TreeNode(vals[i++]);
      q.push(node->left);
    }
    if (i < vals.size()) {
      node->right = new TreeNode(vals[i++]);
      q.push(node->right);
    }
  }
  return root;
}

std::vector<int> serializeTree(TreeNode *root) {
  std::vector<int> result;
  if (!root)
    return result;
  std::queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();
    result.push_back(node->val);
    if (node->left)
      q.push(node->left);
    if (node->right)
      q.push(node->right);
  }
  return result;
}

struct TestCaseSet {
  int id;
  std::vector<int> input;
  std::vector<int> output;
};

void TestCase(const TestCaseSet &T) {
  try {
    TreeNode *root = buildTree(T.input);
    Solution sol;
    TreeNode *inverted = sol.invertTree(root);
    std::vector<int> result = serializeTree(inverted);

    if (result.size() != T.output.size()) {
      throw std::runtime_error("Test failed");
    }

    for (size_t i = 0; i < result.size(); ++i) {
      if (result[i] != T.output[i]) {
        throw std::runtime_error("Test failed");
      }
    }
    std::cout << "Test Case Passed, TestCase ID : " << T.id << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Test Case Failed, TestCase ID : " << T.id << std::endl;
  }
}

int main() {

  TestCaseSet T1{1, {4, 2, 7, 1, 3, 6, 9}, {4, 7, 2, 9, 6, 3, 1}};
  TestCase(T1);
  TestCaseSet T2{2, {2, 1, 3}, {2, 3, 1}};
  TestCase(T2);
  return 0;
}