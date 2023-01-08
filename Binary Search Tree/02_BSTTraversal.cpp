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

// Level Order Traversal
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inorederTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorederTraversal(root->left);
    cout << root->data << " ";
    inorederTraversal(root->right);
}

void postorederTraversal(Node *root)
{
    if (root == NULL)
        return;
    postorederTraversal(root->left);  // Left call
    postorederTraversal(root->right); // Right call
    cout << root->data << " ";        // Print the data
}

void preorederTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorederTraversal(root->left);
    preorederTraversal(root->right);
}
int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    takeInput(root);

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root);

    cout << "\n\nPrerder Traversal : " << endl;
    preorederTraversal(root);

    cout << "\n\nInorder Traversal : " << endl;
    inorederTraversal(root);

    cout << "\n\nPostorder Traversal : " << endl;
    postorederTraversal(root);
    return 0;
}