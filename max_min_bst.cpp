#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to find the maximum value in the BST
int findMax(TreeNode* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->value;
}

// Function to find the minimum value in the BST
int findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->value;
}

// Function to build the BST from user input
TreeNode* buildBST() {
    TreeNode* root = nullptr;
    int n;
    cout << "Enter the number of elements in the BST: ";
    cin >> n;
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        root = insert(root, value);
    }
    return root;
}

int main() {
    TreeNode* root = buildBST();

    // Find maximum and minimum values
    int maximum = findMax(root);
    int minimum = findMin(root);

    cout << "Maximum value in the BST: " << maximum << endl;
    cout << "Minimum value in the BST: " << minimum << endl;

    return 0;
}
