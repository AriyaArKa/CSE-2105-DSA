#include <bits/stdc++.h>

using namespace std;

class Queue
{
    int *arr;
    int front, rear;
    int size;

public:
    Queue(int n)
    {
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }
    bool IsEmpty()
    {
        return front == -1;
    }
    bool IsFull()
    {
        return rear == size - 1;
    }
    void push(int val)
    {
        if (IsEmpty())
        {
            front = rear = 0;
            arr[0] = val;
        }
        else if (IsFull())
        {
            cout << "Queue overflow" << endl;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        if (IsEmpty())
        {
            cout << "empty" << endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front++;
            }
        }
    }

    int start()
    {
        if (IsEmpty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    Queue q(5);

    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    cout << q.start() << endl;
    q.push(5);
    q.push(6);
    while (!q.IsEmpty())
    {
        cout << q.start() << endl;
        q.pop();
    }
}
