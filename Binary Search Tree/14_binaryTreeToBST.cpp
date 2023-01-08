/*
void inorder(Node *root, vector<int> &v)
{
    if (!root)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void inorderToBST(Node *root, vector<int> v, int &i)
{
    if (!root)
        return;
    inorderToBST(root->left, v, i);
    root->data = v[i];
    i++;
    inorderToBST(root->right, v, i);
}
Node *binaryTreeToBST(Node *root)
{

    vector<int> v;
    inorder(root, v);
    sort(v.begin(), v.end());
    int i = 0;
    inorderToBST(root, v, i);
    return root;
}
*/