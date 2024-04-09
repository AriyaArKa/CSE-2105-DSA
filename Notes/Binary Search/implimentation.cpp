#include<bits/stdc++.h>

using namespace std;

void binarySearch(int arr[],int n,int val)
{
    int lo = 0;
    int hi = n-1;
    int mid;

    while(hi - lo >1)
    {
        mid = (hi + lo )/2;

        if(arr[mid] < val)
        {
            lo = mid + 1;
        }
        else
            hi = mid;
    }

    if(arr[lo] == val)
    {
        cout<<lo<<endl;
    }
    else if(arr[hi] == val)
    {
        cout<< hi <<endl;
    }
    else 
    {
        cout<<"NOT FOUND"<<endl;
    }

}

int main()
{

    int arr[6] = {2,3,4,5,6,7};
    binarySearch(arr,6,5);
    return 0;
    
    }