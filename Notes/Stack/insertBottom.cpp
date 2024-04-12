#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> temp;
    stack<int>st;

    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(8);


    while(!st.empty())
    {
        temp.push(st.top());
        st.pop();

    }
    int x= 2;

    st.push(x);
     while(!temp.empty())
    {
        st.push(temp.top());
        temp.pop();

    }

    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}