// Ierative postorder traversal using two stack;

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

vector<int> postorederTraversal(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<node *> s1;
    stack<node *> s2;

    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);

        if (root->left != NULL)
            s1.push(root->left);

        if (root->right != NULL)
            s1.push(root->right);
    }

    while (!s2.empty())
    {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}

int main()
{ // 1 2 4 -1 -1 6 -1 -1 8 10 -1 -1 -1 ----> 4 6 2 10 8 1
    node *root = NULL;

    root = buildTree(root);

    cout << "Postorder Traversal -> " << endl;
    vector<int> postorder;
    postorder = postorederTraversal(root);

    for (int i = 0; i < postorder.size(); i++)
        cout << postorder[i] << " ";
    return 0;
}