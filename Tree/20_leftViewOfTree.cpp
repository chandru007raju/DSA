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

void print(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////

void recursion(node *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->data);
        recursion(root->left, level+1, res);
        recursion(root->right, level+1, res);
    }
    
    vector<int> leftSideView(node *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }

//////////////////////////////////////////////////////////////////////////////////////////
int main()
{ // 1 2 4 -1 -1 6 -1 -1 8 10 -1 -1 -1
    node *root = NULL;

    root = buildTree(root);

    print(root);

    vector<int> ans = leftSideView(root);
    cout << "\nTop View Of Tree" << endl;
    for (auto it : ans)
        cout << it << " ";
    return 0;
}