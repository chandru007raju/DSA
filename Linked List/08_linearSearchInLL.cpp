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

// ____Linear Search In Linked List____
Node *linearSearch(Node *&head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (key == temp->data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

Node *recLinearSearch(Node *&head, int key)
{
    Node *p = head;
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return recLinearSearch(p->next, key);
}

int main()
{
    Node *node = new Node(70);
    Node *head = node;

    // Inserting The element
    insertAtHead(head, 60);
    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    print(head);

    int key = 40;
    Node *temp = recLinearSearch(head, key);
    if (temp)
        cout << key << " is present in Linked List";
    else
        cout << key << " is not present in Linked List";
    cout << endl;
    int key1 = 130;
    Node *temp1 = linearSearch(head, key1);
    if (temp1)
        cout << key1 << " is present in Linked List";
    else
        cout << key1 << " is not present in Linked List";

    return 0;
}