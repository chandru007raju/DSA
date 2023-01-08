#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int *arr, front, rear, size;

public:
    Queue(int s)
    {
        size = s;
        arr = new int[size];
        front = rear = 0;
    }

    // Queue is empty or not
    bool isEmpty()
    {
        if (front == rear)
            return true;
        else
            return false;
    }

    void push(int data)
    {
        if (rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int pop()
    {
        if (front == rear)
            return -1;

        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)// Queue is empty
                front = rear = 0;
            return ans;
        }
    }

    int top()
    {
        if (front == rear)
            return -1;
        else
            return arr[front];
    }
};
int main()
{
    Queue q(7);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(1);
    q.push(52);
    q.push(53);
    q.push(54);

    cout << "is Empty " << q.isEmpty() << endl;
    cout << "Top " << q.top() << endl;
    cout << "Poped element " << q.pop() << endl;

    cout << "is Empty " << q.isEmpty() << endl;
    cout << "Top " << q.top() << endl;
    cout << "Poped element " << q.pop() << endl;

    cout << "is Empty " << q.isEmpty() << endl;
    cout << "Top " << q.top() << endl;
    cout << "Poped element " << q.pop() << endl;

    cout << "is Empty " << q.isEmpty() << endl;
    cout << "Top " << q.top() << endl;
    cout << "Poped element " << q.pop() << endl;

    cout << "is Empty " << q.isEmpty() << endl;
    cout << "Top " << q.top() << endl;
    cout << "Poped element " << q.pop() << endl;

    cout << "is Empty " << q.isEmpty() << endl;
    cout << "Top " << q.top() << endl;
    cout << "Poped element " << q.pop() << endl;

    cout << "is Empty " << q.isEmpty() << endl;
    cout << "Top " << q.top() << endl;
    cout << "Poped element " << q.pop() << endl;

    cout << "is Empty " << q.isEmpty() << endl;
    cout << "Top " << q.top() << endl;
    return 0;
}