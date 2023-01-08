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
void inorederTraversal(Node *root, int &cnt)
{
    if (root == NULL)
        return;
    inorederTraversal(root->left, cnt);
    cnt++;
    cout << root->data << " ";
    inorederTraversal(root->right, cnt);
}
// Kth smallest element in BST

int solve(Node *root, int &i, int k)
{
    if (root == NULL)
        return -1;
    int left = solve(root->left, i, k);
    if (left != -1)
        return left;

    i++;
    if (i == k)
        return root->data;

    return solve(root->right, i, k);
}
// Return the Kth largest element in the given BST
int KthLargestElement(Node *root, int K)
{
    int i = 0;
    int ans = solve(root, i, K);
    return ans;
}

int main()
{
    // 23 21 17 8 14 25 9 3 7 2 -1
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    takeInput(root);
    int k;
    cout << "\nEnter the value of K --> ";
    cin >> k;
    int n = 0;
    cout << "\nInorder Traversal --> ";
    inorederTraversal(root, n);
    cout << "\nThe Value of n : " << n;
    k = (n - k) + 1;
    cout << "\nKth Largest Element in BST --> " << KthLargestElement(root, k);
    return 0;
}