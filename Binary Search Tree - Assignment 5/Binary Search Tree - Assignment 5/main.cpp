#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct TreeNode {
    int val; // Value stored in the node
    TreeNode* left; // Pointer to the left child
    TreeNode* right; // Pointer to the right child
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Initialize node with value x, set left and right pointers to nullptr
};



class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {} // Initialize BST with root set to nullptr

    // ADD FUNCTION
    void add(int key) {
        root = add(root, key);
    }

    TreeNode* add(TreeNode* node, int key) { // Finds correct position to insert node
        if (node == nullptr) return new TreeNode(key);
        if (key < node->val)
            node->left = add(node->left, key);
        else
            node->right = add(node->right, key);
        return node;
    }

    // FIND FUNCTION
    TreeNode* find(int key) {
        return find(root, key);
    }

    TreeNode* find(TreeNode* node, int key) {
        if (node == nullptr || node->val == key) return node;
        if (key < node->val)
            return find(node->left, key);
        return find(node->right, key);
    }

    // REMOVE FUNCTION
    void remove(int key) {
        root = remove(root, key);
    }

    TreeNode* remove(TreeNode* node, int key) {
        if (node == nullptr) return node; // If node is null, return
        if (key < node->val)
            node->left = remove(node->left, key);
        else if (key > node->val)
            node->right = remove(node->right, key);
        else { // Node to be deleted found
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minimum(node->right);
            node->val = temp->val;
            node->right = remove(node->right, temp->val);
        }
        return node;
    }      

    // MINIMUM FUNCTION
    TreeNode* minimum(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    // MAXIMUM FUNCTION
    int maximum() {
        TreeNode* maxNode = maximum(root);
        return maxNode ? maxNode->val : -1; // Return -1 if the tree is empty
    }

    TreeNode* maximum(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->right != nullptr)
            current = current->right;
        return current;
    }

    // IN ORDER TRAVERSE FUNCTION
    void inorder_traverse() {
        inorder_traverse(root);
        cout << endl;
    }

    void inorder_traverse(TreeNode* node) { // In-order traversal (recursive)
        if (node != nullptr) {
            inorder_traverse(node->left);
            cout << node->val << " ";
            inorder_traverse(node->right);
        }
    }

private:
    TreeNode* root; // Declaration of root
};

	//MAIN FUNCTION  -the BST class by adding nodes, performing an in-order traversal, finding a node, removing a node, and finding the maximum value.
int main()
{
    BinarySearchTree bst;//data collection
    bst.add(100);
    bst.add(1000);
    bst.add(10000);
    bst.add(100000);


    cout << "Inorder traversal: ";
    bst.inorder_traverse();

    cout << "Maximum value: " << bst.maximum() << endl;

    TreeNode* found = bst.find(40);
    cout << "Find 40: " << (found ? "Found" : "Not Found") << endl;

    bst.remove(20);
    cout << "Inorder traversal after removing 20: ";
    bst.inorder_traverse();

    return 0;
 
};