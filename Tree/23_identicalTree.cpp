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

// ____Determine if Two Trees are Identical____

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL || r2 == NULL)
        return r1 == r2;
    return (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}

int main()
{
    // Root Node Tree1
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

    // Root Node Tree2
    Node *root1 = new Node(5);
    // Root Left
    root1->left = new Node(3);
    // Root Right
    root1->right = new Node(7);

    root1->left->left = new Node(2);
    root1->left->right = new Node(4);

    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    vector<int> ans1;
    printTree(root1, ans1);
    for (auto it : ans1)
        cout << it << " ";
    cout << endl;
    // _________________________________________________________________________________________________\\


    if (isIdentical(root, root1))
        cout << "Tree is identical.";
    else
        cout << "Tree is not identical.";

    return 0;
}