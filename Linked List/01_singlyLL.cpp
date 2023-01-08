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

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
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

    Node *insertToNode = new Node(d);
    insertToNode->next = temp->next;
    temp->next = insertToNode;
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

void deleteNodeAtPosition(Node *&head, int p)
{
    if (p == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < p)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void deleteNodeByValue(Node *&head, int v)
{
    Node *curr = head;
    int cnt = 1;
    while (curr != NULL)
    {
        if (curr->data == v)
        {
            cout << "Value " << curr->data << endl;
            cout << "Count " << cnt << endl;
            deleteNodeAtPosition(head, cnt);
        }
        cnt++;
        curr = curr->next;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    insertAtHead(head, 1);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;
    insertAtHead(head, 2);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;
    insertAtHead(head, 3);
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
    insertAtTail(tail, 21);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;
    insertAtTail(tail, 22);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;
    insertAtTail(tail, 24);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    insertAtPosition(head, tail, 3, 30);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    deleteNodeAtPosition(head, 2);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    deleteNodeByValue(head, 10);
    print(head);
    cout << "HEAD " << head->data << endl;
    cout << "TAIL " << tail->data << endl;

    return 0;
}