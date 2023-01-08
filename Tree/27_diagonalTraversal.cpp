/*
void solve(Node *root, queue<Node *> &q, vector<int> &ans)
{
    if (root == NULL)
        return;

    ans.push_back(root->data);
    if (root->left)
        q.push(root->left);

    solve(root->right, q, ans);
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (q.size())
    {
        auto frontNode = q.front();
        solve(frontNode, q, ans);
        q.pop();
    }
    return ans;
}*/