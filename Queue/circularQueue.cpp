#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
private:
    int *arr, front, rear, size;

public:
    CircularQueue(int s)
    {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    bool push(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            return false;
        else if (front == -1)
            front = rear = 0;
        else if (rear == size - 1 && front != 0)
            rear = 0;
        else
            rear++;
        arr[rear] = data;
        return true;
    }

    int pop()
    {
        if (front == -1)
            return -1;
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;

        else
            front++;
        return ans;
    }
};
int main()
{
    CircularQueue cq(7);

    cq.push(100);
    cq.push(600);
    cq.push(500);
    cq.push(400);
    cq.push(300);
    cq.push(200);

    cout << "Pooped element " << cq.pop() << endl;
    cout << "Pooped element " << cq.pop() << endl;
    cout << "Pooped element " << cq.pop() << endl;
    cout << "Pooped element " << cq.pop() << endl;
    cout << "Pooped element " << cq.pop() << endl;
    cout << "Pooped element " << cq.pop() << endl;
    cout << "Pooped element " << cq.pop() << endl;
    return 0;
}