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

void reverseLevelOrderTraversal(node *root)
{
    queue<node *> q;
    stack<int> s;
    vector<int> ans;

    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp->data);

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    for (auto i : ans)
        cout << ans[i] << " ";
}

int main()
{ // 1 2 4 -1 -1 6 -1 -1 8 10 -1 -1 -1
    node *root = NULL;

    root = buildTree(root);

    cout << "Reverse Level Order Traversal -> " << endl;
    reverseLevelOrderTraversal(root);
    return 0;
}