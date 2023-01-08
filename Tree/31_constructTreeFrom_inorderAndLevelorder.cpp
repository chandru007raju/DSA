/*

unordered_map<int,int>nodeToIndex;
Node*solve(int level,int in[],int levelorder[],int s,int e,int n){
    if(s > e)
        return NULL;
   
    int index = nodeToIndex[levelorder[level]];
    
    Node*root = new Node(levelorder[level]);
    
    root->left = solve(2*level+1, in, levelorder, s, index-1, n);
    root->right = solve(2*level+2, in, levelorder, index+1, e, n);
    
    return root;
   
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    for(int i=0; i<n; i++){
        nodeToIndex[inorder[i]] = i;
    }
    Node* root= solve(0, inorder, levelOrder, iStart, iEnd, n);
    return root;
}

*/