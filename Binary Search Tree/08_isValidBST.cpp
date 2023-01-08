#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertIntoBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
        root->right = insertIntoBST(root->right, d);
    else
        root->left = insertIntoBST(root->left, d);

    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

// Is Valid Binary Search Tree
bool isvalidBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->data >= min && root->data <= max)
    {
        bool left = isvalidBST(root->left, min, root->data);
        bool right = isvalidBST(root->right, root->data, max);

        return left && right;
    }

    return false;
}

// Function to check whether a Binary Tree is BST or not.
bool isBST(Node *root)
{
    return isvalidBST(root, INT_MIN, INT_MAX);
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    takeInput(root);

    if (isBST(root))
        cout << "Tree is valid BST" << endl;
    else
        cout << "Tree is not valid BST" << endl;
    return 0;
}