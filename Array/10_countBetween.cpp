#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {29, 32, 46, 91, 11, 7, 84, 18, -12, 136, 22};
    int size = sizeof(arr) / sizeof(arr[0]);

    int cntArr[10] = {0}, cnt = 0;

    for (int i = 0; i < size; i++)
    {
        switch (arr[i])
        {

        case 0 ... 9:
            cntArr[0]++;
            break;

        case 10 ... 19:
            cntArr[1]++;
            break;

        case 20 ... 29:
            cntArr[2]++;
            break;

        case 30 ... 39:
            cntArr[3]++;
            break;

        case 40 ... 49:
            cntArr[4]++;
            break;

        case 50 ... 59:
            cntArr[5]++;
            break;

        case 60 ... 69:
            cntArr[6]++;
            break;

        case 70 ... 79:
            cntArr[7]++;
            break;

        case 80 ... 89:
            cntArr[8]++;
            break;

        case 90 ... 100:
            cntArr[9]++;
            break;
        default:
            cnt++;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        printf("%d - %d : %d\n", i * 10, i * 10 + 9, cntArr[i]);
    }
    printf("%d - %d : %d\n", 90, 100, cntArr[9]);
    printf("Invalid : %d\n", cnt);

    return 0;
}