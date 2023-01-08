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

// ____Symmetric Tree____
bool mirror(Node *a, Node *b)
{
    if (!a && !b)
        return true;
    if (a && b && a->data == b->data)
        return mirror(a->left, b->right) && mirror(a->right, b->left);
    else
        return false;
}

bool isSymmetric(Node *root)
{
    return mirror(root, root);
}
int main()
{
    // Root Node
    Node *root = new Node(5);
    // Root Left
    root->left = new Node(1);
    // Root Right
    root->right = new Node(1);

    root->left->left = new Node(2);
    // root->left->right = new Node(4);

    // root->right->left = new Node(6);
    root->right->right = new Node(2);

    vector<int> ans;
    printTree(root, ans);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    // _________________________________________________________________________________________________\\

    if (isSymmetric(root))
        cout << "Tree is symmetric";
    else
        cout << "Tree is not symmetric";

    return 0;
}