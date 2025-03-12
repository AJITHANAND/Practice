#include <iostream>



struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value), left(nullptr), right(nullptr){}
};

class BinarySearchTree{
    Node *root;
    public:
    BinarySearchTree(){
        root = nullptr;
    }
    Node* insert(Node* root, int value){
        if(root == nullptr){
            return new Node(value);
        }
        if(value < root->data){
            root->left = insert(root->left, value);
        }else{
            root->right = insert(root->right, value);
        }
        return root;
    }
    void insert(int value){
        root = insert(root, value);
    }
    /*
    * Inorder traversal of the tree
    * This function prints the nodes of the tree in ascending order.
    * left -> data -> right
    * @param root: The root of the tree
    * @return: void
    */
    void inorder(Node* root){
        if(root == nullptr){
            return;
        }
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
    void inorder(){
        inorder(root);
    }
    /*
    * Preorder traversal of the tree
    * This function prints the nodes of the tree in pre-order.
    * @param root: The root of the tree
    * @return: void
    */
    void preorder(Node* root){
        if(root == nullptr){
            return;
        }
        std::cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void preorder(){
        preorder(root);
    }
    /*
    * Postorder traversal of the tree
    * This function prints the nodes of the tree in post-order.
    * @param root: The root of the tree
    * @return: void
    */
    void postorder(Node* root){
        if(root == nullptr){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << " ";
    }
    void postorder(){
        postorder(root);
    }
    /*
    * Search for a value in the tree
    * This function searches for a value in the tree.
    * @param root: The root of the tree
    * @param value: The value to search for
    * @return: bool
    */
    bool search(Node*root ,int value){
        if(root == nullptr){
            return false;
        }
        if(root->data == value){
            return true;
        }
        if(value < root->data){
            this->search(root->left, value);
        }else{
            this->search(root->right,value);
        }
        return false;
    }
    bool search(int value){
        return search(root, value);
    }

};


int main(){
    BinarySearchTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    tree.inorder();
    std::cout << std::endl;
    tree.preorder();
    std::cout << std::endl;
    tree.postorder();
    std::cout << std::endl;
    std::cout << tree.search(15) << std::endl;
    std::cout << tree.search(20) << std::endl;
    return 0;
}