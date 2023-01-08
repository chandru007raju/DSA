// Eg --> 1 2 3 4 5 6 7 <-- Given Array
// int d = 2; that means rotation by first 2 element.
// Output Arrat --> 3 4 5 6 7 1 2

#include <bits/stdc++.h>
using namespace std;

void rotateArray(int arr[], int size, int d)
{
    cout << " : " << size << endl;
    cout << " : " << d << endl;
    int gcd = __gcd(size, d);
    cout << " : " << gcd << endl;
    for (int i = 0; i < gcd; i++)
    {
        int temp = arr[i];
        int j = i;

        while (1)
        {
            int k = j + d;
            if (k >= size)
                k = k - size;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int d;
    cin >> d;
    rotateArray(arr, size, d);
    printArray(arr, size);
    return 0;
}