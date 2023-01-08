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

vector<int> preorederTraversal(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        node *topNode = s.top();
        ans.push_back(topNode->data);
        s.pop();

        if (topNode->right != NULL)
            s.push(topNode->right);
        if (topNode->left != NULL)
            s.push(topNode->left);
    }
    return ans;
}

int main()
{ // 1 2 4 -1 -1 6 -1 -1 8 10 -1 -1 -1
    // output -> 1 2 4 6 8 10
    node *root = NULL;

    root = buildTree(root);

    cout << "Preorder Traversal -> " << endl;
    vector<int> preOrder;
    preOrder = preorederTraversal(root);

    for (int i = 0; i < preOrder.size(); i++)
        cout << preOrder[i] << " ";
    return 0;
}