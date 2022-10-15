#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 50;
    int arr[num + 1] = {0};
    int k = 2;

    while (k)
    {
        int p = k * k;
        if (p > num)
            break;
        while (p <= num)
        {
            arr[p] = 1;
            p += k;
        }
        k++;
    }

    // printing prime number;
    for (int i = 2; i <= num; i++)
    {
        if (arr[i] == 0)
            cout << i << " ";
    }
    return 0;
}