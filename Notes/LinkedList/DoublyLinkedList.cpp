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
    newnode->prev = temp;
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
    // while(--pos)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "out of range" << endl;
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
    newnode->next->prev = newnode;
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
node *deleteFirst(node *&head)
{
    if (head == nullptr)
        return nullptr;
    node *temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    free(temp);
    return head;
}

node *deleteLast(node *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        free(head);
        return nullptr;
    }
    node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

node *deleteByPosition(node *&head, int k)
{
    if (head == nullptr)
        return nullptr;

    if (k == 1)
    {
        return deleteFirst(head);
    }

    int cnt = 1;
    node *temp = head;
    while (temp != nullptr && cnt < k - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr || temp->next == nullptr)
        return head; // Position k is out of range

    node *toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next != nullptr)
        toDelete->next->prev = temp;
    free(toDelete);
    return head;
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

int main()
{
    node *head = NULL;
    insertFirst(head, 2);
    insertFirst(head, 3);
    insertFirst(head, 4);
    insertFirst(head, 5);
    insertLast(head, 55);
    insertAtPosition(head, 234, 3);
    print(head);
    cout << length(head) << endl;

    cout << endl;

    deleteFirst(head);
    print(head);
    cout << length(head) << endl;

    cout << endl;

    deleteLast(head);
    print(head);
    cout << length(head) << endl;

    cout << endl;

    deleteByPosition(head, 3);
    print(head);
    cout << length(head) << endl;
}
