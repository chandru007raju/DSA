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
void inorederTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorederTraversal(root->left);
    cout << root->data << " ";
    inorederTraversal(root->right);
}

// LCA in BST
Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    return root;
}

Node *LCAinBST(Node *root, int n1, int n2)
{
    while (root != NULL)
    {
        if (root->data < n1 && root->data < n2)
            root = root->right;
        else if (root->data > n1 && root->data > n2)
            root = root->left;
        else
            return root;
    }
}
int main()
{
    // 23 21 17 8 14 25 9 3 7 2 -1
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    takeInput(root);
    int n1, n2;
    cout << "\nEnter the value of N1 and N2 --> ";
    cin >> n1 >> n2;

    cout << "\nInorder Traversal --> ";
    inorederTraversal(root);
    cout << "\nLCA in BST --> " << LCA(root, n1, n2)->data;
    cout << "\nLCA in BST --> " << LCAinBST(root, n1, n2)->data;
    return 0;
}