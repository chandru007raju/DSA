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

// ___Count Nodes___

int count(Node *&head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int count2(Node *&head)
{
    Node *temp = head;
    if (temp == NULL)
        return 0;
    else
        return count2(temp->next) + 1;
}

int count3(Node *&head)
{
    Node *temp = head;
    int cnt = 0;
    if (temp)
    {
        cnt = count3(temp->next);
        return cnt + 1;
    }
    else
        cnt;
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

    cout << "Nodes in LL : " << endl;
    int cnt = count(head);
    cout << cnt << endl;

    int cnt2 = count2(head);
    cout << cnt2 << endl;

    int cnt3 = count3(head);
    cout << cnt3 << endl;
    return 0;
}