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

// ____Remove Duplicates in SLL____
void removeDuplicate(Node *head)
{
    Node *temp = head->next;
    while (temp != NULL)
    {
        if (head->data != temp->data)
        {
            head = temp;
            temp = temp->next;
        }
        else
        {
            head->next = temp->next;
            delete (temp);
            temp = head->next;
        }
    }
}

int main()
{
    Node *node = new Node(70);
    Node *head = node;

    // Inserting The element
    insertAtHead(head, 60);
    insertAtHead(head, 50);
    insertAtHead(head, 50);
    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    print(head);

    removeDuplicate(head);
    print(head);
    return 0;
}