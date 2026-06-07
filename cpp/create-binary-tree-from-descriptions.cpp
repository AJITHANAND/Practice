#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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
  TreeNode *getOrCreateNode(std::unordered_map<int, TreeNode *> &store,
                            int value) {
    auto it = store.find(value);
    if (it != store.end()) {
      return it->second;
    } else {
      TreeNode *newNode = new TreeNode(value);
      store[value] = newNode;
      return newNode;
    }
  }

public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> store;
    unordered_set<int> children;

    for (const vector<int> &description : descriptions) {
      int parentValue = description[0];
      int childValue = description[1];
      bool isLeftChild = description[2];

      TreeNode *parent = getOrCreateNode(store, parentValue);
      TreeNode *child = getOrCreateNode(store, childValue);

      if (isLeftChild) {
        parent->left = child;
      } else {
        parent->right = child;
      }

      children.insert(childValue);
    }

    for (const auto &entry : store) {
      if (children.find(entry.first) == children.end()) {
        return entry.second;
      }
    }

    return nullptr;
  }
};

/*
Test Case 1 :
    Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
    Output: [50,20,80,15,17,19]
*/

int main() {
  Solution s;
  vector<vector<int>> descriptions = {
      {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
  TreeNode *root = s.createBinaryTree(descriptions);
  // check results
  vector<int> expected = {50, 20, 80, 15, 17, 19};
  vector<int> result;

  queue<TreeNode *> nodes;
  nodes.push(root);
  while (!nodes.empty()) {
    TreeNode *node = nodes.front();
    nodes.pop();

    result.push_back(node->val);
    if (node->left) {
      nodes.push(node->left);
    }
    if (node->right) {
      nodes.push(node->right);
    }
  }

  // Compare result with expected
  if (result == expected) {
    std::cout << "Test Case 1 Passed!" << std::endl;
  } else {
    std::cout << "Test Case 1 Failed!" << std::endl;
  }
  return 0;
}