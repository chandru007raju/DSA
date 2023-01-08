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

// ____Sum Of Elementes Of Singly Linked List____

int sumOfLL(Node *&head)
{
    Node *temp = head;
    int sum = 0;
    while (temp)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int recSumOfLL(Node *&head)
{
    Node *temp = head;
    if (temp == NULL)
        return 0;
    else
        return recSumOfLL(temp->next) + temp->data;
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

    cout << "Sum of the element : " << endl;
    cout << sumOfLL(head) << endl;
    cout << recSumOfLL(head) << endl;
    return 0;
}