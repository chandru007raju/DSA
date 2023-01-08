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
// Two Sum in a BST
void inorederTraversal(Node *root, vector<int> &ln)
{
    if (root == NULL)
        return;
    inorederTraversal(root->left, ln);
    cout << root->data << " ";
    ln.push_back(root->data);
    inorederTraversal(root->right, ln);
}
bool twoSum(Node *root, int target)
{
    vector<int> res;
    inorederTraversal(root, res);

    int i = 0, j = res.size() - 1;
    while (i < j)
    {
        int sum = res[i] + res[j];
        if (sum == target)
            return true;
        else if (sum > target)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    takeInput(root);
    int k;
    cout << "Enter the target value : ";
    cin >> k;
    cout << endl;
    if (twoSum(root, k))
        cout << "1";
    else
        cout << "0";
    return 0;
}