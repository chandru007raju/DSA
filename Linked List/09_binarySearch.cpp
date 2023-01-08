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
// ____Binary Search in Linked List____
Node *middle(Node *start, Node *last)
{
    if (start == NULL)
        return NULL;

    Node *slow = start;
    Node *fast = start->next;

    while (fast != last)
    {
        fast = fast->next;
        if (fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

Node *binarySearch(Node *&head, int key)
{
    Node *temp = head;
    Node *start = temp;
    Node *last = NULL;

    do
    {
        Node *mid = middle(start, last);

        if (mid == NULL)
            return NULL;

        if (mid->data == key)
            return mid;
        else if (mid->data < key)
            start = mid->next;
        else
            last = mid;

    } while (last == NULL || last != start);
    return NULL;
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

    Node *temp = binarySearch(head, 110);
    if (temp)
        cout << "Key is present" << endl;
    else
        cout << "Key is not present" << endl;

    return 0;
}