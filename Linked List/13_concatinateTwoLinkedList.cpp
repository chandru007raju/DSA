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

// _____Concatinate Two Linked List____

void concatinate(Node *ll1, Node *ll2)
{
    Node *temp = ll1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = ll2;
    ll2 = NULL;
}

int main()
{
    // Linnked List 1
    Node *node = new Node(70);
    Node *ll1 = node;
    // Inserting The element
    insertAtHead(ll1, 60);
    insertAtHead(ll1, 50);
    insertAtHead(ll1, 40);
    insertAtHead(ll1, 30);
    insertAtHead(ll1, 20);
    insertAtHead(ll1, 10);
    print(ll1);

    // Linked List 2
    Node *node1 = new Node(80);
    Node *ll2 = node1;
    // Inserting The element
    insertAtHead(ll2, 90);
    insertAtHead(ll2, 100);
    insertAtHead(ll2, 110);
    insertAtHead(ll2, 120);
    insertAtHead(ll2, 130);
    insertAtHead(ll2, 140);
    print(ll2);

    concatinate(ll1, ll2);
    print(ll1);
    return 0;
}