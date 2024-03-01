#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& value)
    {
        data=value;
        next=NULL;
        prev=NULL;
    }
};

template <typename T>
class Deque
{
private:
    Node<T>* Front;
    Node<T>* head;

public:
    Deque() : Front(nullptr), head(nullptr)
    {
        Front=NULL;
        head=NULL;
    }

    ~Deque()
    {
        while (!empty())
        {
            Pop_front();
        }
    }

    void Push_front(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (empty())
        {
            Front = head = newNode;
        }
        else
        {
            newNode->next = Front;
            Front->prev = newNode;
            Front = newNode;
        }
    }

    void Push_back(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (empty())
        {
            Front = head = newNode;
        }
        else
        {
            newNode->prev = head;
            head->next = newNode;
            head = newNode;
        }
    }

    void Pop_front()
    {
        if (empty())
        {
            return;
        }
        Node<T>* temp = Front;
        Front = Front->next;
        if (Front)
        {
            Front->prev = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
    }

    void Pop_back()
    {
        if (empty())
        {
            return;
        }
        Node<T>* temp = head;
        head = head->prev;
        if (head)
        {
            head->next = nullptr;
        }
        else
        {
            Front = nullptr;
        }
        delete temp;
    }

    bool empty() const
    {
        return Front == nullptr;
    }

    void display() const
    {
        Node<T>* current = Front;
        while (current)
        {
            cout << current->data <<"  ";
            current = current->next;
        }
        cout <<endl;
    }

    int Size() const
    {
        int Count = 0;
        Node<T>* current = Front;
        while (current)
        {
            Count++;
            current = current->next;
        }
        return Count;
    }
};

template <typename T>
class Queue : public Deque<T>
{
public:
    Queue() {}

    ~Queue() {}

    void push(const T& value)
    {
        Deque<T>::Push_back(value);
    }

    void pop()
    {
        Deque<T>::Pop_front();
    }

    bool empty() const
    {
        return Deque<T>::empty();
    }

    void display() const
    {
        Deque<T>::display();
    }

    int Size() const
    {
        return Deque<T>::Size();
    }
};

template <typename T>
class Stack : public Deque<T>
{
public:
    Stack() {}

    ~Stack() {}

    void push(const T& value)
    {
        Deque<T>::Push_front(value);
    }
    void pop()
    {
        Deque<T>::Pop_front();
    }
    bool empty() const
    {
        return Deque<T>::empty();
    }
    void display() const
    {
        Deque<T>::display();
    }
    int Size() const
    {
        return Deque<T>::Size();
    }
};
/*


#include <bits/stdc++.h>
#include"2107055_assignment5.h"

using namespace std;

int main()
{
    Deque<int> obj;
    obj.Push_front(2107055);
    obj.Push_front(2107056);
    obj.Push_front(2107057);
    obj.Push_front(2107058);
    cout << "Deque: ";
    obj.display();
    cout << "Size before push back: " << obj.Size() << endl;
    obj.Push_back(420);
    cout << "Size after push back: " << obj.Size() << endl;
    obj.Push_front(440);
    cout << "Deque: ";
    obj.display();
    cout << "Size: " << obj.Size() << endl;
    obj.Pop_front();
    cout << "Deque after pop front: ";
    obj.display();
    obj.Pop_back();
    cout << "Deque after pop back: ";
    obj.display();
    cout<<endl;



    Queue<int> obj2;
    obj2.push(2107055);
    obj2.push(2107056);
    obj2.push(2107057);
    obj2.push(2107058);
    obj2.push(2107059);
    cout << "Queue: ";
    obj2.display();
    cout << "Size: " << obj2.Size() << endl;
    obj2.pop();
    cout << "Queue after popping: ";
    obj2.display();
    cout << "Size: " << obj2.Size() << endl;
    cout<<endl;


    Stack<int> obj3;
    obj3.push(2107055);
    obj3.push(2107056);
    obj3.push(2107057);
    obj3.push(2107058);
    obj3.push(2107059);
    cout << "Stack: ";
    obj3.display();
    cout << "Size: " << obj3.Size() <<endl;
    obj3.pop();
    cout << "Stack after popping: ";
    obj3.display();
    cout << "Size: " << obj3.Size() <<endl;

    return 0;
}

*/
