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

void allTraversal(node *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    stack<pair<node *, int>> st;
    st.push({root,
             1});
    if (root == NULL)
        return;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is part of pre
        // increment 1 to 2
        // push the left side of the tree
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left,
                         1});
            }
        }

        // this is a part of in
        // increment 2 to 3
        // push right
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right,
                         1});
            }
        }
        // don't push it back again
        else
        {
            post.push_back(it.first->data);
        }
    }
}
int main()
{ // 1 2 4 -1 -1 6 -1 -1 8 10 -1 -1 -1 ----> 4 6 2 10 8 1
    node *root = NULL;

    root = buildTree(root);

    vector<int> pre, in, post;
    allTraversal(root, pre, in, post);

    cout << "The preorder Traversal is : ";
    for (auto nodeVal : pre)
    {
        cout << nodeVal << " ";
    }
    cout << endl;
    cout << "The inorder Traversal is : ";
    for (auto nodeVal : in)
    {
        cout << nodeVal << " ";
    }
    cout << endl;
    cout << "The postorder Traversal is : ";
    for (auto nodeVal : post)
    {
        cout << nodeVal << " ";
    }
    cout << endl;
    return 0;
}