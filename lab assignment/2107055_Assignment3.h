/*
sample test cases has been done below codes as comment
*/

#include<iostream>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node *next;
};

template <class T>
class LinkedList
{
    Node<T> *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Node<T> *cur = head, *nextNode;
        while (cur != nullptr)
        {
            nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }
        head = nullptr;
    }

    void insertFront(const T& value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(const T& value)
    {
        if(head == nullptr)
        {
            insertFront(value);
            return;
        }

        Node<T> *newNode = new Node<T>,*cur = head;
        newNode->data = value;
        newNode->next = nullptr;

        while(cur->next != nullptr)
        {


            cur = cur->next;
        }
        cur->next = newNode;
    }

    void insertAtPosition(int position, const T& value)
    {
        Node<T> *cur = head;
        Node<T> *newNode = new Node<T>;
        newNode->data = value;

        while(position != 1)
        {


            cur = cur->next;
            position--;
        }
         newNode->next = cur->next;
            cur->next = newNode;
    }

    bool Search(const T& value)
    {
        Node<T> *cur = head;

        while(cur != nullptr)
        {
            if(cur->data == value)
            {
                return true;
            }
            cur=cur->next;
        }
        return false;
    }

    void display()
    {
        Node<T> *cur = head;

        while(cur != nullptr)
        {
            cout << cur->data<<"  ";
            cur = cur->next;
        }
        cout << endl;
    }

    int getLength()
    {
        Node<T> *cur = head;
        int l = 0;

        while(cur != nullptr)
        {
            l++;
            cur = cur->next;
        }
        return l;
    }
};



/*
#include<iostream>
#include"2107055_Assignment3.h"

int main(){
    LinkedList<int> st;

    st.insertEnd(2107050);
    st.insertEnd(2107051);
    st.insertEnd(2107052);
    st.insertEnd(2107053);

    st.display();

    st.insertFront(2107059);

    st.display();

    st.insertAtPosition(2, 2114);
    st.insertAtPosition(3, 2116);
    st.insertAtPosition(6, 2115);

    st.display();

    cout << "Length of linked list : " << st.getLength() << endl;
    cout << "Search 2107050 : " << st.Search(2107050) <<endl;
    cout << "Search 2116 : " << st.Search(2110) <<endl;
}
*/
