#include <iostream>
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
    std::unordered_map<int, TreeNode *> store;
    std::unordered_set<TreeNode *> rootsList;
    std::unordered_set<TreeNode *> childrenList;
    for (size_t i = 0; i < descriptions.size(); i++) {
      int node_value = descriptions[i][0];
      int child_value = descriptions[i][1];
      bool isleftChild = descriptions[i][2];

      TreeNode *node = getOrCreateNode(store, node_value);
      TreeNode *child = getOrCreateNode(store, child_value);
      if (isleftChild) {
        node->left = child;
      } else {
        node->right = child;
      }
      // Update rootsList
      if (rootsList.find(node) == rootsList.end() &&
          childrenList.find(node) == childrenList.end()) {
        rootsList.insert(node);
      }
      if (rootsList.find(child) != rootsList.end()) {
        rootsList.erase(child);
      }
      childrenList.insert(child);
    }
    TreeNode *root = *rootsList.begin();
    return root;
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
  // Implement a function to traverse the tree and collect values in order
  vector<int> result;
  std::function<void(TreeNode *)> inorder = [&](TreeNode *node) {
    if (!node)
      return;
    inorder(node->left);
    result.push_back(node->val);
    inorder(node->right);
  };
  inorder(root);
  // Compare result with expected
  if (result == expected) {
    std::cout << "Test Case 1 Passed!" << std::endl;
  } else {
    std::cout << "Test Case 1 Failed!" << std::endl;
  }
  return 0;
}