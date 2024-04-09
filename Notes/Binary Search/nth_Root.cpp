#include <bits/stdc++.h>

using namespace std;

double eps = 1e-6;

double multiply(double mid, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= mid;
    }
    return ans;
}

void ntimes_Root(double a, int n)
{
    double l = 1;
    double h = a;
    double mid;

    while (h - l > eps)
    {
        mid = (h + l) / 2;
        if (multiply(mid, n) < a)
        {
            l = mid;
        }
        else
            h = mid;
    }
    //log(n*(10^d))
    cout << setprecision(10) << l << endl << h << endl;
}

int main()
{
    double a = 8;
    int n = 3;
    ntimes_Root(a, n);
}