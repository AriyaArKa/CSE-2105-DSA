//   2 4 6 8 8 8 11 13
//   8    {3,5}
//   9    {-1,-1}
//   11   {6,6}
// lowerbound(80)     a[ind]>=n
// upperbound(8)-1     a[ind]>n

#include <bits/stdc++.h>

using namespace std;

// int lowerOccurence(int arr[], int n, int val)
// {
//     int l = 0;
//     int h = n - 1;
//     int mid;
//     while (h - l > 1)
//     {
//         mid = (h + l) / 2;
//         if (arr[mid] < val)
//         {
//             l = mid + 1;
//         }
//         else
//             h = mid;
//     }
//     if (arr[l] >= val)
//     {
//         return l;
//     }
//     if (arr[h] >= val)
//     {
//         return h;
//     }
//     else
//         return -1;
// }

// int upperOccurence(int arr[], int n, int val)
// {
//     int l = 0;
//     int h = n - 1;
//     int mid;
//     while (h - l > 1)
//     {
//         mid = (h + l) / 2;
//         if (arr[mid] <= val)
//         {
//             l = mid;
//         }
//         else
//             h = mid;
//     }
//     if (arr[l] > val)
//     {
//         return l;
//     }
//     if (arr[h] > val)
//     {
//         return h;
//     }
//     else
//         return -1;
// }

// void occurence(int arr[], int n, int val)
// {

//     int lb = lowerOccurence(arr, 8, val);
//     int up = upperOccurence(arr, 8, val) - 1;

//     if (lb == n || arr[lb] != val)
//     {
//         cout << "-1 -1" << endl;
//     }
//     else

//         cout << lb << " " << up << endl;
// }

//in one binary search

int lb(int arr[],int n,int val)
{
    int l = 0;
    int h = n-1;
    int mid;
    int first = -1;
    while(l <= h)
    {
        mid = (h+l)/2;

        if(arr[mid]==val)
        {
            h = mid-1;
            first = mid;
        }
        else if(arr[mid]<val)
        {
            l = mid+1;

        }
        else
         h = mid -1;

    }
    return first;
}


int ub(int arr[],int n,int val)
{
    int l = 0;
    int h = n-1;
    int mid;
    int last = -1;
   while(l <= h)
    {
        mid = (h+l)/2;

        if(arr[mid]==val)
        {
            l = mid+1;
            last = mid;
        }
        else if(arr[mid]<val)
        {
            l = mid+1;

        }
        else
         h = mid -1;

    }
    return last;
}


void finalOccurence(int arr[],int n,int val)
{
    // int l = 0;
    // int h = n-1;
    // int mid;
    // int first = -1;
    // int last = -1;
    // while(l <= h)
    // {
    //     mid = (h+l)/2;

    //     if(arr[mid]==val)
    //     {
    //         h = mid-1;
    //         first = mid;
    //     }
    //     else if(arr[mid]<val)
    //     {
    //         l = mid+1;

    //     }
    //     else
    //      h = mid -1;

    // }

    // while(l <= h)
    // {
    //     mid = (h+l)/2;

    //     if(arr[mid]==val)
    //     {
    //         l = mid+1;
    //         last = mid;
    //     }
    //     else if(arr[mid]<val)
    //     {
    //         l = mid+1;

    //     }
    //     else
    //      h = mid -1;

    // }

    int first = lb(arr, n,val);
    int last = ub(arr, n,val);

    if(first==-1)
    {
        cout<<"-1 -1"<<endl;
    }else
    cout<<first<<" "<<last<<endl;
}

int countOccurence(int arr[],int n,int val)
{
    int first = lb(arr, n,val);
    int last = ub(arr, n,val);
    if(first==-1)return 0;
    return last-first+1;

}
int main()
{
    int arr[] = {2, 4, 6, 8, 8, 8, 11, 13};
    int val1 = 8;
    int val2 = 9;
    int val3 = 11;
    int val4 = 15;

    // occurence(arr, 8, val1);
    // occurence(arr, 8, val2);
    // occurence(arr, 8, val3);
    // occurence(arr, 8, val4);

    finalOccurence(arr, 8, val1);
    finalOccurence(arr, 8, val2);
    finalOccurence(arr, 8, val3);
    finalOccurence(arr, 8, val4);

    cout<<"total : "<< countOccurence(arr, 8, val1)<<endl;
    cout<<"total : "<< countOccurence(arr, 8, val2)<<endl;
    cout<<"total : "<< countOccurence(arr, 8, val3)<<endl;
    cout<<"total : "<< countOccurence(arr, 8, val4)<<endl;
}