#include <bits/stdc++.h>

using namespace std;

int lowerBound(int arr[], int n, int val)
{
    int l = 0;
    int h = n - 1;
    int mid;

    while (h - l > 1)
    {
        int mid = (h + l) / 2;
        if (arr[mid] <= val)
        {
            l = mid;
        }
        else
        {
            h = mid;
        }
    }

    if (arr[l] > val)
    {
        return l;
    }
    if (arr[h] > val)
    {
        return h;
    }
    else
        return -1;
}

int main()
{

    int arr[6] = {2, 3, 4, 6, 7, 8};

    cout << lowerBound(arr, 6, 5) << endl; // 6  3
    cout << lowerBound(arr, 6, 4) << endl; // 4  3
    cout << lowerBound(arr, 6, 8) << endl; // -1
    cout << lowerBound(arr, 6, 9) << endl; // -1
}