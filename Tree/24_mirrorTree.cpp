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

void printTree(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);

        ans.push_back(temp->data);
    }
}

// ____Mirror Tree____
void mirror(Node *root)
{
    if (root)
    {
        mirror(root->left);
        mirror(root->right);
        std::swap(root->left, root->right);
    }
}

int main()
{
    // Root Node
    Node *root = new Node(5);
    // Root Left
    root->left = new Node(3);
    // Root Right
    root->right = new Node(7);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(8);

    vector<int> ans;
    printTree(root, ans);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    // _________________________________________________________________________________________________\\

    mirror(root);
    vector<int> mirrorTree;
    printTree(root, mirrorTree);
    for (auto it : mirrorTree)
        cout << it << " ";
    cout << endl;

    return 0;
}