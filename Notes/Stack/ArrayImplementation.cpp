#include <bits/stdc++.h>

using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;

public:
    bool flag;
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[s];
        flag = 1;
    }
    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "stack overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = value;
            flag=0;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
            return;
        }
        else
        {
            top--;
            //cout << "popped " << arr[top + 1] << endl;
            if(top==-1)flag=1;
        }
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "stack empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    bool isEmpty()
    {
        return top == -1;
    }
    int IsSize()
    {
        return top+1;
    }

};

int main()
{
    Stack st(5);
    // st.push(5);
    // st.push(6);
    // st.push(7);
    // st.pop();
    // st.push(8);
    // st.push(9);

    // cout<<st.isEmpty()<<endl;
    // cout<<st.IsSize()<<endl;

    // while(!st.isEmpty())
    // {
    //     cout<<st.peek()<<endl;
    //     st.pop();
    // }

    // cout<<st.isEmpty()<<endl;
    // cout<<st.IsSize()<<endl;
   st.push(-1);
//    cout<<st.isEmpty()<<endl;
//    cout<<st.IsSize()<<endl;
//    cout<<st.peek();

   int val = st.peek();
   if(st.flag==0)
   {
    cout<<val<<endl;
   }

}
