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

int height(Node *root)
{
    if (root == NULL)
        return -1;
    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

void printLevel(Node *root, int lvl)
{
    if (root == NULL)
        return;
    else if (lvl == 0)
        cout << root->data << " ";
    else if (lvl > 0)
    {
        printLevel(root->left, lvl - 1);
        printLevel(root->right, lvl - 1);
    }
}

void levelOrderTraversal(Node *root)
{
    cout << "Height Of tree : " << height(root) << endl;
    for (int lvl = 0; lvl <= height(root); lvl++)
        printLevel(root, lvl);
}
// ____

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

    // _________________________________________________________________________________________________\\

    cout << "Level order traversal using recursion" << endl;
    levelOrderTraversal(root);

    return 0;
}