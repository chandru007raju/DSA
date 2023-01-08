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

vector<int> inorederTraversal(node *root)
{
    stack<node *> s;
    node *top = root;

    vector<int> ans;
    while (true)
    {
        if (top != NULL)
        {
            s.push(top);
            top = top->left;
        }
        else
        {
            if (s.empty() == true)
                break;
            top = s.top();
            s.pop();
            ans.push_back(top->data);
            top = top->right;
        }
    }
    return ans;
}

int main()
{ // 1 2 4 -1 -1 6 -1 -1 8 10 -1 -1 -1 --> 4 2 6 1 10 8
    node *root = NULL;

    root = buildTree(root);

    cout << "Inorder Traversal -> " << endl;
    vector<int> inoreder;
    inoreder = inorederTraversal(root);

    for (int i = 0; i < inoreder.size(); i++)
        cout << inoreder[i] << " ";
    return 0;
}