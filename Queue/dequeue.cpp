#include <bits/stdc++.h>
using namespace std;

class Dequeue
{
private:
    int *arr, front, rear, size;

public:
    Dequeue(int s)
    {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            return true;

        else
            return false;
    }

    // Push the element in dequeue
    bool pushFront(int d)
    {
        if (isFull())
            return false;
        else if (isEmpty())
            front = rear = 0;
        else if (front == 0 && rear != size - 1)
            front = size - 1;
        else
            front--;
        arr[front] = d;
        return true;
    }

    bool pushRear(int d)
    {
        if (isFull())
            return false;
        else if (isEmpty())
            front = rear = 0;
        else if (rear == size - 1 && front != 0)
            rear = 0;
        else
            rear++;

        arr[rear] = d;
        return true;
    }

    // Pop the element

    int popFront()
    {
        if (isEmpty())
            return -1;

        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
            front = rear = -1;
        else if (front = size - 1)
            front = 0;
        else
            front++;
        return ans;
    }

    int popRear()
    {
        if (isEmpty())
            return -1;
        int ans = arr[rear];
        arr[rear] = -1;
        if (front = rear)
            front = rear = -1;
        else if (rear = size - 1)
            rear = 0;
        else
            rear--;
        return ans;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return arr[rear];
    }
};

int main()
{
    Dequeue dq(6);

    dq.pushFront(10);
    dq.pushFront(20);
    dq.pushFront(30);
    dq.pushRear(40);
    dq.pushRear(60);
    dq.pushRear(50);

    cout << endl
         << endl;
    cout << "Pooped front " << dq.popFront() << endl;
    cout << "get front " << dq.getFront() << endl;
    cout << "get Rear " << dq.getRear() << endl;
    cout << "is Empty " << dq.isEmpty() << endl;
    cout << "is Full " << dq.isFull() << endl;
    cout << "Pooped Rear " << dq.popRear() << endl;

    return 0;
}