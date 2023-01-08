#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> maxHeap;
    maxHeap.push(52);
    maxHeap.push(51);
    maxHeap.push(55);
    maxHeap.push(53);
    maxHeap.push(54);

    cout << "Max Heap : ";
    while (!maxHeap.empty())
    {
        int top = maxHeap.top();
        maxHeap.pop();
        cout << top << " ";
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(52);
    minHeap.push(51);
    minHeap.push(55);
    minHeap.push(53);
    minHeap.push(54);

    cout << "Min Heap : ";
    while (!minHeap.empty())
    {
        int top = minHeap.top();
        minHeap.pop();
        cout << top << " ";
    }
    cout << endl;

    return 0;
}