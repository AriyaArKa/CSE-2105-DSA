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
        if (arr[mid] < val)
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }

    // if (arr[l] >= val)
    // {
    //     cout << l << endl;
    // }
    // else if (arr[h] >= val)
    // {
    //     cout << h << endl;
    // }
    // else
    //     return -1;

    if (arr[l] >= val)
    {
        return l;
    }
    if (arr[h] >= val)
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
    cout << lowerBound(arr, 6, 4) << endl; // 4  2
    cout << lowerBound(arr, 6, 8) << endl; // 8  5
    cout << lowerBound(arr, 6, 9) << endl; // -1
}