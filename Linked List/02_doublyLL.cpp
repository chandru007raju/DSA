#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int p, int d)
{
    if (p == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < p - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
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

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    insertAtHead(head, 5);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    insertAtTail(tail, 20);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    insertAtTail(tail, 40);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    insertAtPosition(head, tail, 1, 1);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    insertAtPosition(head, tail, 5, 30);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    insertAtPosition(head, tail, 7, 50);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    return 0;
}