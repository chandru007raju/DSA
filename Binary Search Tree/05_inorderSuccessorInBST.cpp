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
void inorederTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorederTraversal(root->left);
    cout << root->data << " ";
    inorederTraversal(root->right);
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

// Inorder Successor In BST
Node *inorderSuccessor(Node *root, int x)
{
    Node *temp = root;
    Node *successor = NULL;
    while (temp != NULL)
    {
        if (x >= temp->data)
            temp = temp->right;
        else
        {
            successor = temp;
            temp = temp->left;
        }
    }
    return successor;
}
int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    takeInput(root);
    cout << "Inorder Traversal --> ";
    inorederTraversal(root);

    int x = 7;
    cout << "\nInorder Successor Of " << x << " is --> ";
    cout << inorderSuccessor(root, x)->data;
    return 0;
}