#include<iostream>
#include "2107055_assignment4.hpp"

using namespace std;


int main()
{
    DoublyLinkedList<int> start;

    start.insertEnd(2107001);
    start.insertEnd(2107002);
    start.insertEnd(2107003);
    start.insertEnd(2107004);
    start.insertEnd(2107005);

    start.display();

    start.insert_Begin(5000);

    start.display();
    cout<<endl;


    start.insertAtPosition(2, 50);
    start.insertAtPosition(3, 15);
    start.insertAtPosition(6, 55);

    start.display();
    cout<<endl;


    start.deleteBegin();
    start.display();
    cout<<endl;


    start.deleteEnd();
    start.display();
    cout<<endl;


    start.deleteAtPosition(2);
    cout<<"after deleting at position 2"<<endl;
    start.display();
    cout<<endl;

    start.deleteByValue(109);
    cout<<"after deleting at position 109"<<endl;
    start.display();
    cout<<endl;


    start.deleteByValue(50);
    cout<<"after deleting at position 50"<<endl;
    start.display();
    cout<<endl;


    start.quickSort();
    cout<<"after sorting using quick sort"<<endl;
    start.display();
    cout<<endl;


    start.insertEnd(110);
    cout<<"after adding 110 at end"<<endl;
    start.display();
    cout<<endl;

    start.insertAtPosition(2, 90);
    cout<<"after adding 90 at position 2"<<endl;
    start.display();
    cout<<endl;


    start.mergeSort();
    cout<<"after sorting using merge sort"<<endl;
    start.display();
    cout<<endl;
}
