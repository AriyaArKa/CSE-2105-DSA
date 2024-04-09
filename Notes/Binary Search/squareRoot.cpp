#include<bits/stdc++.h>

using namespace std;

double eps = 1e-7;

void squareRoot(double a)
{
    double l=1;
    double h = a;
    double mid;

    while(h - l >eps)
    {
        mid = (h+l)/2;
        if(mid*mid < a)
        {
            l = mid;
        }
        else
        h = mid;
    }
    //cout<<setprecision(10)<<l<<endl<<h<<endl;
    cout<<floor(l)<<endl;
}

int main()
{
    double n=8;
    squareRoot(n);
}

// class Solution {
// public:
// double eps = 1e-6;

//     int mySqrt(int a) {

//     double l=1;
//     double h = a;
//     double mid;

//     while(h - l >eps)
//     {
//         mid = (h+l)/2;
//         if(mid*mid < a)
//         {
//             l = mid;
//         }
//         else
//         h = mid;
//     }
//     return floor(h);
        
//     }
// };