#include <iostream>

// Node structure for B-Tree
struct BTreeNode {
    bool isLeaf;
    int *keys;
    BTreeNode **children;
    int numKeys;
};

// B-Tree class
class BTree {
    BTreeNode *root;
    int t;  // Minimum degree

public:
    BTree(int _t) : root(nullptr), t(_t) {}

    // Function to search for a key in the B-Tree
    BTreeNode *getRoot() {
        return root;
    }

    BTreeNode* search(BTreeNode *node, int key) {
        int i = 0;
        while (i < node->numKeys && key > node->keys[i])
            i++;

        if (node->keys[i] == key)
            return node;

        if (node->isLeaf)
            return nullptr;

        return search(node->children[i], key);
    }

    // Function to insert a key into the B-Tree
    void insert(int key) {
        if (root == nullptr) {
            root = createNode(true);
            root->keys[0] = key;
            root->numKeys = 1;
        } else {
            if (root->numKeys == (2 * t) - 1) {
                BTreeNode *newRoot = createNode(false);
                newRoot->children[0] = root;
                splitChild(newRoot, 0, root);
                insertNonFull(newRoot, key);
                root = newRoot;
            } else {
                insertNonFull(root, key);
            }
        }
    }

    // Function to delete a key from the B-Tree
    void remove(int key) {
        if (root == nullptr) {
            std::cout << "B-Tree is empty." << std::endl;
            return;
        }

        if (root->numKeys == 0) {
            if (root->isLeaf) {
                delete root;
                root = nullptr;
            } else {
                BTreeNode *temp = root;
                root = root->children[0];
                delete temp;
            }
        }

        removeKey(root, key);

        if (root->numKeys == 0) {
            BTreeNode *temp = root;
            if (root->isLeaf) {
                delete root;
                root = nullptr;
            } else {
                root = root->children[0];
                delete temp;
            }
        }
    }

    // Function to display the B-Tree
    void display() {
        if (root == nullptr) {
            std::cout << "B-Tree is empty." << std::endl;
        } else {
            displayNode(root);
        }
    }

private:
    // Function to create a new B-Tree node
    BTreeNode* createNode(bool isLeaf) {
        BTreeNode *node = new BTreeNode;
        node->isLeaf = isLeaf;
        node->keys = new int[(2 * t) - 1];
        node->children = new BTreeNode *[2 * t];
        node->numKeys = 0;
        return node;
    }

    // Function to split a child node
    void splitChild(BTreeNode *parent, int index, BTreeNode *child) {
        BTreeNode *newChild = createNode(child->isLeaf);
        newChild->numKeys = t - 1;

        for (int i = 0; i < t - 1; i++)
            newChild->keys[i] = child->keys[i + t];

        if (!child->isLeaf) {
            for (int i = 0; i < t; i++)
                newChild->children[i] = child->children[i + t];
        }

        child->numKeys = t - 1;

        for (int i = parent->numKeys; i > index; i--)
            parent->children[i + 1] = parent->children[i];

        parent->children[index + 1] = newChild;

        for (int i = parent->numKeys - 1; i >= index; i--)
            parent->keys[i + 1] = parent->keys[i];

        parent->keys[index] = child->keys[t - 1];
        parent->numKeys++;
    }

    // Function to insert a key into a non-full node
    void insertNonFull(BTreeNode *node, int key) {
        int i = node->numKeys - 1;

        if (node->isLeaf) {
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }

            node->keys[i + 1] = key;
            node->numKeys++;
        } else {
            while (i >= 0 && key < node->keys[i])
                i--;

            i++;

            if (node->children[i]->numKeys == (2 * t) - 1) {
                splitChild(node, i, node->children[i]);

                if (key > node->keys[i])
                    i++;
            }

            insertNonFull(node->children[i], key);
        }
    }

    // Function to remove a key from the B-Tree
    void removeKey(BTreeNode *node, int key) {
        int i = 0;
        while (i < node->numKeys && key > node->keys[i])
            i++;

        if (i < node->numKeys && key == node->keys[i]) {
            if (node->isLeaf) {
                for (int j = i; j < node->numKeys - 1; j++)
                    node->keys[j] = node->keys[j + 1];

                node->numKeys--;
            } else {
                BTreeNode *pred = node->children[i];
                BTreeNode *succ = node->children[i + 1];

                if (pred->numKeys >= t) {
                    int predKey = getPredecessor(pred);
                    node->keys[i] = predKey;
                    removeKey(pred, predKey);
                } else if (succ->numKeys >= t) {
                    int succKey = getSuccessor(succ);
                    node->keys[i] = succKey;
                    removeKey(succ, succKey);
                } else {
                    mergeChildren(node, i, pred, succ);
                    removeKey(pred, key);
                }
            }
        } else {
            if (node->isLeaf) {
                std::cout << "Key " << key << " not found in the B-Tree." << std::endl;
                return;
            }

            BTreeNode *child = node->children[i];

            if (child->numKeys < t) {
                BTreeNode *leftSibling = (i > 0) ? node->children[i - 1] : nullptr;
                BTreeNode *rightSibling = (i < node->numKeys) ? node->children[i + 1] : nullptr;

                if (leftSibling && leftSibling->numKeys >= t) {
                    borrowFromLeftSibling(node, i, leftSibling, child);
                } else if (rightSibling && rightSibling->numKeys >= t) {
                    borrowFromRightSibling(node, i, rightSibling, child);
                } else if (leftSibling) {
                    mergeChildren(node, i - 1, leftSibling, child);
                    child = leftSibling;
                } else if (rightSibling) {
                    mergeChildren(node, i, child, rightSibling);
                }
            }

            removeKey(child, key);
        }
    }

    // Function to get the predecessor key from a node
    int getPredecessor(BTreeNode *node) {
        while (!node->isLeaf)
            node = node->children[node->numKeys];

        return node->keys[node->numKeys - 1];
    }

    // Function to get the successor key from a node
    int getSuccessor(BTreeNode *node) {
        while (!node->isLeaf)
            node = node->children[0];

        return node->keys[0];
    }

    // Function to merge two child nodes of a parent node
    void mergeChildren(BTreeNode *parent, int index, BTreeNode *leftChild, BTreeNode *rightChild) {
        leftChild->keys[t - 1] = parent->keys[index];

        for (int i = 0; i < rightChild->numKeys; i++)
            leftChild->keys[i + t] = rightChild->keys[i];

        if (!leftChild->isLeaf) {
            for (int i = 0; i <= rightChild->numKeys; i++)
                leftChild->children[i + t] = rightChild->children[i];
        }

        for (int i = index; i < parent->numKeys - 1; i++)
            parent->keys[i] = parent->keys[i + 1];

        for (int i = index + 1; i < parent->numKeys; i++)
            parent->children[i] = parent->children[i + 1];

        parent->numKeys--;
        delete rightChild;
    }

    // Function to borrow a key from the left sibling
    void borrowFromLeftSibling(BTreeNode *parent, int index, BTreeNode *leftSibling, BTreeNode *child) {
        for (int i = child->numKeys; i > 0; i--)
            child->keys[i] = child->keys[i - 1];

        if (!child->isLeaf) {
            for (int i = child->numKeys + 1; i > 0; i--)
                child->children[i] = child->children[i - 1];
        }

        child->keys[0] = parent->keys[index - 1];
        parent->keys[index - 1] = leftSibling->keys[leftSibling->numKeys - 1];

        if (!child->isLeaf)
            child->children[0] = leftSibling->children[leftSibling->numKeys];

        child->numKeys++;
        leftSibling->numKeys--;
    }

    // Function to borrow a key from the right sibling
    void borrowFromRightSibling(BTreeNode *parent, int index, BTreeNode *rightSibling, BTreeNode *child) {
        child->keys[child->numKeys] = parent->keys[index];
        parent->keys[index] = rightSibling->keys[0];

        for (int i = 0; i < rightSibling->numKeys - 1; i++)
            rightSibling->keys[i] = rightSibling->keys[i + 1];

        if (!child->isLeaf) {
            child->children[child->numKeys + 1] = rightSibling->children[0];

            for (int i = 0; i < rightSibling->numKeys; i++)
                rightSibling->children[i] = rightSibling->children[i + 1];
        }

        child->numKeys++;
        rightSibling->numKeys--;
    }

    // Function to display a B-Tree node
    void displayNode(BTreeNode *node) {
        for (int i = 0; i < node->numKeys; i++) {
            if (!node->isLeaf)
                displayNode(node->children[i]);

            std::cout << node->keys[i] << " ";
        }

        if (!node->isLeaf)
            displayNode(node->children[node->numKeys]);

        if (node == root)
            std::cout << std::endl;
    }

    BTreeNode *findParent(BTreeNode *node, BTreeNode *child) {
        if (node == nullptr || node->isLeaf || node->children[0] == child)
            return nullptr;

        for (int i = 0; i < node->numKeys + 1; i++) {
            if (node->children[i] == child)
                return node;
            
            if (!node->isLeaf && i < node->numKeys && child->keys[0] < node->keys[i])
                return findParent(node->children[i], child);
        }

        return nullptr;
    }
};
int main() {
    // Create a B-Tree with minimum degree 3
    BTree bTree(3);

    // Insert keys into the B-Tree
    bTree.insert(10);
    bTree.insert(20);
    bTree.insert(5);
    bTree.insert(15);
    bTree.insert(30);
    bTree.insert(12);
    bTree.insert(7);

    // Display the B-Tree
    std::cout << "B-Tree after insertion:" << std::endl;
    bTree.display();
    std::cout << std::endl;

    // Search for a key in the B-Tree
    int keyToSearch = 15;
    BTreeNode *searchResult = bTree.search(bTree.getRoot(), keyToSearch);
    if (searchResult)
        std::cout << "Key " << keyToSearch << " found in the B-Tree." << std::endl;
    else
        std::cout << "Key " << keyToSearch << " not found in the B-Tree." << std::endl;

    // Delete a key from the B-Tree
    int keyToDelete = 20;
    bTree.remove(keyToDelete);

    // Display the B-Tree after deletion
    std::cout << "B-Tree after deletion of key " << keyToDelete << ":" << std::endl;
    bTree.display();
    std::cout << std::endl;

    return 0;
}
