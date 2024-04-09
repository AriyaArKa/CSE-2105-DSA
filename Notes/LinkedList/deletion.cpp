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
node *deleteFirst(node *&head)
{
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
node *deleteLast(node *&head)
{
    node *temp = head;
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
node *deleteByPosition(node *&head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    if (k == 1)
    {
        deleteFirst(head);
    }
    int cnt = 0;
    node *temp = head, *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}
node *deleteByVal(node *&head, int ele)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->data == ele)
    {
        deleteFirst(head);
    }
    int cnt = 0;
    node *temp = head, *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == ele)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}
int main()
{
    node *head = NULL;

    insertFirst(head, 10);
    insertFirst(head, 20);
    insertFirst(head, 30);
    insertFirst(head, 40);
    insertFirst(head, 50);
    insertFirst(head, 60);
    traverse(head);
    cout << length(head) << endl;
    // deleteFirst(head);
    // traverse(head);
    // cout << length(head) << endl;
    // deleteLast(head);
    // traverse(head);
    // cout << length(head) << endl;
    deleteByPosition(head, 4);
    traverse(head);
    cout << length(head) << endl;
    deleteByVal(head, 20);
    traverse(head);
    cout << length(head) << endl;
}
