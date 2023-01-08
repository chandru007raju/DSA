#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;

    root = new node(data);
    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in left " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void preorederTraversal(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorederTraversal(root->left);
    preorederTraversal(root->right);
}

int main()
{ // 1 2 4 -1 -1 6 -1 -1 8 10 -1 -1 -1
    // output -> 1 2 4 6 8 10
    node *root = NULL;

    root = buildTree(root);

    cout << "Preorder Traversal -> " << endl;
    preorederTraversal(root);
    return 0;
}