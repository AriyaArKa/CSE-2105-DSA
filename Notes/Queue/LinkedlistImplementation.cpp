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

class Queue
{
    node *front;
    node *rear;
    int size;

public:
    Queue()
    {
        front = rear = NULL;
        size = 0;
    }
    bool IsEmpty()
    {
        return front == NULL;
    }

    void push(int val)
    {
        node *newnode = new node(val);

        if (front == NULL) // if(IsEmpty())
        {
            front = newnode; // front=newnode(x)
            rear = front;
            return;
        }
        else
        {
            rear->next = newnode;
            rear = rear->next;
        }
    }

    // delete from first position in single linked list
    void pop()
    {
        // if (front == NULL || front->next == NULL)
        // {
        //     return NULL;
        // }
        if (IsEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        else
        {
            node *temp = front;
            front = front->next;
            free(temp);
        }
    }

    int start()
    {
        if (IsEmpty())
        {
            cout << "Queue empty" << endl;
            return -1;
        }
        else
            return front->data;
    }
};

int main()
{
    Queue q;
    q.push(2);
    q.push(3);
    q.push(4);

    q.push(5);
    cout << q.start() << endl;

    q.push(6);
    while (!q.IsEmpty())
    {
        cout << q.start() << endl;
        q.pop();
    }
}