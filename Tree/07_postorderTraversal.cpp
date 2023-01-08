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

void postorederTraversal(node *root)
{
    if (root == NULL)
        return;
    postorederTraversal(root->left); // Left call
    postorederTraversal(root->right); // Right call
    cout << root->data << " "; // Print the data
}

int main()
{ // 1 2 4 -1 -1 6 -1 -1 8 10 -1 -1 -1
    node *root = NULL;

    root = buildTree(root);

    cout << "Postorder Traversal -> " << endl;
    postorederTraversal(root);
    return 0;
}