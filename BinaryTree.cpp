#include <iostream>

using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Class to represent the binary tree
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    // Function to insert a value into the binary tree
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Function to perform in-order traversal
    void inOrder() {
        inOrderRec(root);
        cout << endl;
    }

    // Function to perform pre-order traversal
    void preOrder() {
        preOrderRec(root);
        cout << endl;
    }

    // Function to perform post-order traversal
    void postOrder() {
        postOrderRec(root);
        cout << endl;
    }

    // Function to search for a value in the binary tree
    bool search(int value) {
        return searchRec(root, value);
    }

private:
    TreeNode* root;

    // Helper function to insert a value recursively
    TreeNode* insertRec(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insertRec(node->left, value);
        } else if (value > node->value) {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    // Helper function for in-order traversal
    void inOrderRec(TreeNode* node) {
        if (node != nullptr) {
            inOrderRec(node->left);
            cout << node->value << " ";
            inOrderRec(node->right);
        }
    }

    // Helper function for pre-order traversal
    void preOrderRec(TreeNode* node) {
        if (node != nullptr) {
            cout << node->value << " ";
            preOrderRec(node->left);
            preOrderRec(node->right);
        }
    }

    // Helper function for post-order traversal
    void postOrderRec(TreeNode* node) {
        if (node != nullptr) {
            postOrderRec(node->left);
            postOrderRec(node->right);
            cout << node->value << " ";
        }
    }

    // Helper function to search for a value recursively
    bool searchRec(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        }
        if (value < node->value) {
            return searchRec(node->left, value);
        } else {
            return searchRec(node->right, value);
        }
    }
};

int main() {
    BinaryTree tree;
    int numValues;
    int value;

    cout << "Enter the number of values to insert: ";
    cin >> numValues;

    // Insert values into the binary tree
    for (int i = 0; i < numValues; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        tree.insert(value);
    }

    // Display the tree traversals
    cout << "In-order traversal: ";
    tree.inOrder();

    cout << "Pre-order traversal: ";
    tree.preOrder();

    cout << "Post-order traversal: ";
    tree.postOrder();

    // Search for a value
    cout << "Enter a value to search: ";
    cin >> value;
    if (tree.search(value)) {
        cout << value << " is found in the tree." << endl;
    } else {
        cout << value << " is not found in the tree." << endl;
    }

    return 0;
}
