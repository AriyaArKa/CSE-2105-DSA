#include <bits/stdc++.h>

using namespace std;

struct node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
    node *top;
    int size;

public:
    Stack()
    {
        top = NULL; // head = null   now head = top
        size = 0;
    }
    void push(int val)
    {
        // if (top == NULL)
        // {
        //     cout << "stack overflow" << endl;
        //     return;
        // }
        
            node *newnode = new node(val);
            newnode->data = val;
            newnode->next = top;
            top = newnode;
            size++;
        
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            node *temp = top;
            top = top->next;
            free(temp);
            size--;
        }
    }
    int peek()
    {
        if (top == NULL)
        {
            cout << "stack empty" << endl;
            return -1;
        }
        else
            return top->data;
    }
    int isSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return top==NULL;
    }
};

int main()
{
    Stack st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);

    cout<<st.isEmpty()<<endl;  //0 means ace
    cout<<st.isSize()<<endl;
    cout<<st.peek()<<endl;

    while(!st.isEmpty())
    {
        cout<<st.peek()<<endl;
        st.pop();
    }

}