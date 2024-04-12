#include <bits/stdc++.h>
using namespace std;

struct node
{
public:
    int data;
    node *next, *prev;
    node(int val)
    {
        next = nullptr;
        data = val;
        prev = nullptr;
    }
};
void insertFirst(node *&head, int val)
{
    node *temp = new node(val);
    if (head != NULL) // head->prev = temp;   otherwise segmentation fault
    {
        temp->next = head;
        head->prev = temp;
    }
    head = temp;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

// O(2N)  reverse in terms of data;
// space = O(N)  for using stack
void reverse(node *&head)
{
    stack<int> st;

    node *temp = head;
    while (temp != NULL) // O(N)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;

    while (temp != NULL) // O(N)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
}

// }
// void reverse(node *&head)
// {
//     if (head == NULL || head->next == NULL)
//         return;

//     node *current = head;
//     node *prevNode = NULL;
//     while (current != NULL)
//     {
//         node *nextNode = current->next;
//         current->next = prevNode;
//         current->prev = nextNode; // Reversing prev pointer
//         prevNode = current;
//         current = nextNode;
//     }
//     head = prevNode;
// }

void Reversetemp(node *&head)
{
    if (head == NULL || head->next == NULL)
        return;

    node *last = NULL, *cur = head;
    while (cur != NULL)
    {
        last = cur->prev;
        cout<<"last : "<<last<<endl;
        cur->prev = cur->next;
        cout<<"cur->prev : "<<cur->prev<<endl;
        cur->next = last;
        cout<<"cur->next : "<<cur->next<<endl;
        cur = cur->prev;
        cout<<"cur : "<<cur<<endl;
    }
    head = last->prev;
    cout<<"head: "<<head<<endl;
}

int main()
{
    node *head = NULL;
    insertFirst(head, 2);
    insertFirst(head, 3);
    insertFirst(head, 4);
    //insertFirst(head, 5);
    //insertFirst(head, 6);
    //print(head);

    cout << endl;

    Reversetemp(head);
    print(head);
}