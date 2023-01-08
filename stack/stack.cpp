#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Push the element in the stack
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
            cout << "Stack OverFlow" << endl;
    }

    void pop()
    {
        if (top >= 0)
            top--;
        else
            cout << "Stack UnderFlow" << endl;
    }

    int peak()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        // cout << "Stack is Empty" << endl;
        else
            return false;
        // cout << "Stack is not Empty" << endl;
    }
};

int main()
{
    Stack st(5);

    st.push(9);
    cout << st.peak() << endl;
    st.push(18);
    cout << st.peak() << endl;
    st.push(27);
    cout << st.peak() << endl;
    st.push(36);
    cout << st.peak() << endl;
    st.push(45);

    cout << st.peak() << endl;

    st.pop();
    cout << st.peak() << endl;

    st.pop();
    cout << st.peak() << endl;

    st.pop();
    cout << st.peak() << endl;

    st.pop();
    cout << st.peak() << endl;

    st.pop();
    cout << st.peak() << endl;

    if (st.isEmpty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;

    return 0;
}