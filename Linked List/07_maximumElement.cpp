#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//____Maximum Element____
int maxElement(Node *&head)
{
    Node *temp = head;
    int mx = INT_MIN;
    while (temp)
    {
        if (temp->data > mx)
            mx = temp->data;
        temp = temp->next;
    }
    return mx;
}

int recMaxElement(Node *&head)
{
    Node *temp = head;
    int mx = 0;

    if (temp == NULL)
        return INT_MIN;

    mx = recMaxElement(temp->next);

    if (mx > temp->data)
        return mx;
    else
        return temp->data;
}

int main()
{
    Node *node = new Node(70);
    Node *head = node;

    // Inserting The element
    insertAtHead(head, 60);
    insertAtHead(head, 150);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    print(head);

    int maxEl = maxElement(head);
    cout << maxEl << endl;
    cout << recMaxElement(head) << endl;
    return 0;
}