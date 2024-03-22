#include<bits/stdc++.h>
using namespace std;
template<class T>
class PriorityQueue
{
    vector<T>data;
    bool comparator;
public:
    PriorityQueue(bool comp=true)
    {
        comparator=comp;
    }
    T Top()
    {
        if(data.size()>0)
            return data[0];
        else
        {
            cout<<"Empty priority queue"<<endl;
            return -1;
        }
    }
    bool Empty()
    {
        return data.size()==0;
    }
    int Size()
    {
        return data.size();
    }
    void heapify_max(int i)
    {
        int n=data.size();
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<n && data[largest]<data[l])
        {
            largest=l;
        }

        if(r<n && data[largest]<data[r])
        {
            largest=r;
        }
        if(largest != i)
        {
            swap(data[largest],data[i]);
            heapify_max(largest);
        }
    }


    void heapify_min_push(int ind)
    {
        while(ind>0 && data[(ind-1)/2]>data[ind])
        {

            swap(data[(ind-1)/2],data[ind]);
            ind=(ind-1)/2;
        }
    }
    void heapify_min_pop(int i)
    {
        while(true)
        {
            int l=2*i+1;
            int r=2*i+2;
            int small=i;
            if(l<data.size() && data[small]>data[l])
            {
                small=l;
            }

            if(r<data.size() && data[small]>data[r])
            {
                small=r;
            }

            if(small != i)
            {
                swap(data[small],data[i]);
                i=small;
            }
            else
            {
                break;
            }
        }
    }
    void Push(T value)
    {
        data.push_back(value);
        if(comparator==false)
        {
            heapify_max(0);
        }
        else
        {
            heapify_min_push(data.size()-1);
        }

    }
    void Pop()
    {
        if(data.size()==0)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        data[0]=data.back();
        data.pop_back();
        if(data.size()==0)
        {
            return;
        }

        if(comparator==false)
        {
            heapify_max(0);

        }

        else
        {
            heapify_min_pop(0);
        }

    }
    void show()
    {
        for(int i=0; i<data.size(); i++)
        {
            cout<<data[i]<<" ";
        }

        cout<<endl;
    }
};
template<class T>
class Node
{
public:
    T data;
    Node *next;
    Node *prev;
};
template<class T>
class PriorityQueueNode
{
    Node<T> *head;
    int Size;
    bool comparator;
public:
    PriorityQueueNode(bool com=true)
    {
        head=NULL;
        Size=0;
        comparator=com;
    }
    T Top()
    {
        if(head)
        {
            return head->data;
        }

        return -1;
    }
    int size()
    {
        return Size;
    }
    void Push(T value)
    {
        Size++;
        Node<T> *p=head;
        Node<T> *t=new Node<T>;
        t->data=value;
        t->next=t->prev=NULL;
        if(head==NULL)
        {
            head=t;
            return;
        }
        if(comparator==false)
        {
            if(head->data < value)
            {
                t->next=head;
                head->prev=t;
                head=t;
            }
            else
            {
                Node<T> *q=NULL;
                while(p && p->data > value)
                {
                    q=p;
                    p=p->next;
                }
                t->prev=q;
                q->next=t;
                t->next=p;
                if(p)
                {
                    p->prev=t;

                }
            }
        }
        else
        {
            if(head->data > value)
            {
                t->next=head;
                head->prev=t;
                head=t;
            }
            else
            {
                Node<T> *q=NULL;
                while(p && p->data < value)
                {
                    q=p;
                    p=p->next;
                }
                t->next=p;
                t->prev=q;
                q->next=t;
                if(p)
                {
                    p->prev=t;

                }

            }
        }
    }
    bool Empty()
    {
        return head==NULL;
    }
    void Pop()
    {
        Node<T> *t=head;
        head=head->next;
        if(head)
        {
            head->prev=NULL;
        }
        delete t;
    }
    void show()
    {
        Node<T> *p=head;
        while(p)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};
int main()
{
    cout<<"Vector : "<<endl;
    PriorityQueue<int> demo(true);
    cout<<"Size : "<<demo.Size()<<endl;
    cout<<"Is empty? : "<<demo.Empty()<<endl;
    demo.Push(2107055);
    demo.Push(2107045);
    demo.Push(2107012);
    demo.Push(2107009);
    demo.Push(2107008);
    demo.Push(2107004);
    demo.Push(2107001);

    demo.show();
    cout<<"Top : "<<demo.Top()<<endl;
    cout<<"Size : "<<demo.Size()<<endl;
    cout<<"Is empty? : "<<demo.Empty()<<endl;


    cout<<"Linked List : "<<endl;
    PriorityQueueNode<int> demo2(false);
    cout<<"Size : "<<demo2.size()<<endl;
    cout<<"Is empty? : "<<demo2.Empty()<<endl;
    demo2.Push(2107007);
    demo2.Push(2107008);
    demo2.Push(2107009);
    demo2.Push(2107003);
    demo2.Push(2107002);
    demo2.Push(2107004);
    demo2.Push(2107001);

    demo2.show();
    cout<<"Top : "<<demo2.Top()<<endl;
    cout<<"Size : "<<demo2.size()<<endl;
    cout<<"Is empty? : "<<demo2.Empty()<<endl;

}
