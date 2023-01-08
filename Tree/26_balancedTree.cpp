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

// ____Balanced Tree____
int height(Node *root)
{
    if (root == NULL)
        return true;

    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    bool lCheck = isBalanced(root->left);
    bool rCheck = isBalanced(root->right);

    if (lCheck && rCheck)
    {
        int lh = height(root->left);
        int rh = height(root->right);
        if (abs(lh - rh) <= 1)
            return true;
    }
    return false;
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
    root->right->right->right = new Node(18);
    root->right->right->right->right = new Node(28);

    vector<int> ans;
    printTree(root, ans);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    // _________________________________________________________________________________________________\\

    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";

    return 0;
}