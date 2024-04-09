#include <bits/stdc++.h>
using namespace std;

struct node
{
public:
    int data;
    node *next;
    node(int val)
    {
        next = nullptr;
        data = val;
    }
};
void insertFirst(node *&head, int val)
{
    node *newnode = new node(val);

    newnode->data = val;
    newnode->next = head;

    head = newnode;
}
void insertLast(node *&head, int val)
{
    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertAtPosition(node *&head, int val, int pos)
{
    node *newnode = new node(val);

    if (pos == 0)
    {
        insertFirst(head, val);
        return;
    }
    node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; ++i)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "out of range" << endl;
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void traverse(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int length(node *&head)
{
    int cnt = 0;
    node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
bool searchELE(node *&head, int val)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int searchELEposition(node *head, int val)
{
    node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (temp->data == val)
        {
            return cnt; // Return the position of the first occurrence
        }
        temp = temp->next;
    }
    return -1; // Return -1 if the value is not found
}

int main()
{
    node *head = NULL;

    insertFirst(head, 10);
    insertFirst(head, 20);
    insertFirst(head, 30);
    insertLast(head, 40);
    insertAtPosition(head, 55, 8);
    traverse(head);
    cout << length(head) << endl;
    cout << searchELE(head, 55) << endl;
    cout << searchELEposition(head, 77) << endl;
}
