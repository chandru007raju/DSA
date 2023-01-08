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

void inorder(Node *root, vector<int> &ln)
{
    if (root == NULL)
        return;
    inorder(root->left, ln);
    ln.push_back(root->data);
    inorder(root->right, ln);
}
Node *flatten(Node *root)
{
    vector<int> res;
    inorder(root, res);
    int n = res.size();

    Node *newNode = new Node(res[0]);
    Node *curr = newNode;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(res[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newNode;
}
int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    takeInput(root);
    return 0;
}