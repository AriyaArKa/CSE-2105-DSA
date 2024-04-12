#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<char> st;
    string s = "hello";

    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }
    int i = 0;
    while (!st.empty())
    {
        s[i] = st.top();
        st.pop();
        i++;
    }
    cout << s << endl;
    return 0;
}