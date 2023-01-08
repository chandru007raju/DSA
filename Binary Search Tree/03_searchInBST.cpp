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

// Searcing In BST -- Recursive Way
bool searchInBST(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;

    if (root->data > x)
        return searchInBST(root->left, x);
    else
        return searchInBST(root->right, x);
}

// Searcing In BST -- Itretive Way
bool searchInBSTItretive(Node *root, int x)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
            return true;
        if (temp->data > x)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}
int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    takeInput(root);

    cout << "Inorder traversal : " << endl;
    inorederTraversal(root);

    cout << "\nSearch in BST Recursively --> " << endl;
    int x = 18;
    if (searchInBST(root, x))
        cout << x << " is Present" << endl;
    else
        cout << x << " is not Present" << endl;

    cout << "\nSearch in BST Itretively --> " << endl;
    x = 6;
    if (searchInBSTItretive(root, x))
        cout << x << " is Present" << endl;
    else
        cout << x << " is not Present" << endl;

    return 0;
}