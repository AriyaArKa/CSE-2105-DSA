
#include<iostream>

using namespace std;

template <class T>

struct Node
{
    T data;
    Node *next,*prev;
};


template <class T>

class DoublyLinkedList
{
    Node<T> *head,*tail;

public:

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    ~DoublyLinkedList()
    {
        Node<T> *cur = head, *nextNode;
        while (cur != NULL)
        {
            nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }
        head = NULL;
        tail = NULL;
    }

    void insert_Begin(const T& value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        newNode->next = head;
        newNode->prev = NULL;
        if (head)
        {
            head->prev = newNode;
        }
        if(tail == NULL)
        {
            tail = newNode;
        }
        head = newNode;
    }

    void insertEnd(const T& value)
    {
        if(head == NULL)
        {
            insert_Begin(value);
            return;
        }

        Node<T> *newNode = new Node<T>, *cur = head;
        newNode->data = value;
        newNode->prev = tail;
        newNode->next = NULL;

        if (tail)
        {
            tail->next = newNode;
        }
        if(head == NULL)
        {
            head = newNode;
        }
        tail = newNode;
    }

    void insertAtPosition(int position, const T& value)
    {

        if( position < 0 || position > getLength())
        {
            cout << "Wrong position.Value can not be inserted at this position" << endl;
            return;
        }
        else if(position == 0)
        {
            insert_Begin(value);
            return;
        }

        Node<T> *cur = head;

        Node<T> *newNode = new Node<T>;

        newNode->data = value;

        while(position != 1)
        {
            cur = cur->next;
            position--;
        }

        newNode->next = cur->next;

        newNode->prev = cur;

        if(cur->next != NULL)
        {
            cur->next->prev=newNode;
        }
        else
        {
            tail=newNode;
        }

        cur->next = newNode;
    }

    void deleteBegin()
    {
        if(head == NULL)
        {
            return;
        }

        Node<T> *cur = head;

        head = head->next;

        head->prev = NULL;

        if(head != NULL)
        {
            head->prev=NULL;

        }
        else
            tail=NULL;

        delete cur;
    }

    void deleteEnd()
    {
        if(tail == NULL)
            return;

        Node<T> *cur = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete cur;

        if(tail == NULL)
        {
            head = NULL;
        }
    }

    void deleteAtPosition(int position)
    {
        if(head == NULL)
            return;

        Node<T> *cur = head;
        while(cur!=NULL && position != 0)
        {
            cur = cur->next;
            position--;
        }

        if(cur==NULL)
        {
            cout << "Error" << endl;
            return;
        }

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;

    }

    void deleteByValue(const T& value)
    {
        if(head == NULL)
            return;

        Node<T> *cur = head, *temp;

        while(cur!=NULL)
        {
            if(cur->data == value)
            {
                temp = cur->next;
                if(cur->prev)
                {
                    cur->prev->next=cur->next;
                }
                else
                {
                    head=head->next;
                }

                if(cur->next)
                {
                    cur->next->prev=cur->prev;
                }
                else
                {
                    tail=tail->prev;
                }
                delete cur;
                cur = temp;
            }
            else
            {
                cur = cur->next;
            }
        }
    }

    Node<T>* dividing(Node<T> *l, Node<T> *h)
    {
        T pivot = h->data;
        Node<T> *cur = l->prev;

        for (Node<T> *j = l; j != h; j = j->next)
        {
            if (j->data <= pivot)
            {
                cur = (cur == NULL) ? l : cur->next;
                swap(cur->data, j->data);
            }
        }
        cur = (cur == NULL)? l : cur->next;
        swap(cur->data, h->data);
        return cur;
    }

    void qSort(Node<T>* l, Node<T> *h)
    {
        if (h != NULL && l != h && l != h->next)
        {
            Node<T> *p = dividing(l, h);
            qSort(l, p->prev);
            qSort(p->next, h);
        }
    }

    void quickSort()
    {
        qSort(head, tail);
    }

    void display()
    {
        Node<T> *cur = head;
        while(cur != NULL)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    Node<T>* midPoint(Node<T> *head)
    {
        Node<T> *sl = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            sl = sl->next;
            fast = fast->next->next;
        }
        Node<T>* temp = sl->next;
        sl->next = NULL;
        return temp;
    }

    Node<T>* Merge(Node<T> *first, Node<T> *last)
    {
        if(first == NULL)
        {
            return last;
        }
        if(last == NULL)
        {
            return first;
        }

        if(first->data < last->data)
        {
            first->next = Merge(first->next, last);
            first->next->prev = first;
            first->prev = NULL;
            return first;
        }
        else
        {
            last->next = Merge(first, last->next);
            last->next->prev = last;
            last->prev = NULL;
            return last;
        }
    }

    Node<T>* MergeSort(Node<T> *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        Node<T> *mid = midPoint(head);
        head = MergeSort(head);
        mid = MergeSort(mid);

        return Merge(head, mid);
    }

    void mergeSort()
    {
        head=MergeSort(head);
        tail=head;
        while(tail->next)
        {
            tail = tail->next;
        }
    }

    int getLength()
    {
        int l = 0;
        for(auto cur = head; cur != NULL; cur = cur->next, l++);
        return l;
    }
};
