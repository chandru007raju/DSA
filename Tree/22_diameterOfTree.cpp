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

// ____Diameter Of Tree____
int height(Node *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter, lh + rh);
    return max(lh, rh) + 1;
}
int diameter(Node *root)
{
    int d = 0;
    height(root, d);
    return d + 1;
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

    cout << "Diameter Of Tree : " << diameter(root) << endl;
    return 0;
}