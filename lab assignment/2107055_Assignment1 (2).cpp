/*
sample output is given below after the code
*/


#include<iostream>

using namespace std;

class Array
{
    int Size;
    int *arr;
public:
    Array(int initialSize):Size(initialSize)
    {
        arr = new int[Size]();
    }
    ~Array()
    {
        delete[] arr;
    }
    void createArray(int newSize)
    {

        Size = newSize;
        arr = new int[Size]();/*to initialize an array of a given size with default values(e.g.zeros)*/
    }
    void insertElement(int index, int value)
    {
        int* newArray = new int[Size + 1];

        for (int i = 0; i < index; ++i)
        {
            newArray[i] = arr[i];
        }

        newArray[index] = value;

        for (int i = index; i < Size; ++i)
        {
            newArray[i + 1] = arr[i];
        }
        delete[] arr;
        arr = newArray;
        ++Size;

    }
    void deleteElement(int index)
    {
        int* newArray = new int[Size - 1];

        for (int i = 0; i < index; ++i)
        {
            newArray[i] = arr[i];
        }

        for (int i = index + 1; i < Size; ++i)
        {
            newArray[i - 1] = arr[i];
        }

        delete[] arr;
        arr = newArray;

        --Size;

    }
    int searchElement(int value)
    {
        for (int i = 0; i < Size; ++i)
        {
            if (arr[i] == value)
            {
                return i;
            }
        }

        return -1;
    }
    void traverseArray()
    {
        cout << "Array elements: ";
        for (int i = 0; i < Size; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    Array testArray(5);
    cout<<"Array with previous size "<<endl;
    testArray.traverseArray();
    cout<<endl;





    int arraySize;
    cout<<"Enter array size : ";
    cin>>arraySize;
    testArray.createArray(arraySize);
    cout<<"Array with given size "<<endl;
    testArray.traverseArray();
    cout<<endl;





    int indexInsert,ele;
    cout<<"Enter index to insert : ";
    cin>>indexInsert;

    if (indexInsert < 0 || indexInsert > arraySize)
    {
        cout << "Invalid index for insert " << endl;

    }
    else
    {
        cout<<"Enter element to insert : ";
        cin>>ele;
        testArray.insertElement(indexInsert, ele);
        cout<<"Array after inserting "<<ele<<" at index "<<indexInsert<<endl;
        testArray.traverseArray();
    }
    cout<<endl;








    int delEleIndex;
    cout<<"enter index to delete : ";
    cin>>delEleIndex;
    if (indexInsert < 0 || indexInsert > arraySize)
    {
        cout << "Invalid index for delete " << endl;

    }
    else
    {
        testArray.deleteElement(delEleIndex);
        cout<<"Array after deleting index "<<delEleIndex<<" element "<<endl;
        testArray.traverseArray();
    }
    cout<<endl;






    int searchEle ;
    cout<<"Enter element to search : ";
    cin>>searchEle;




    int index = testArray.searchElement(searchEle);
    if (index != -1)
    {
        cout << "Element "<<searchEle<<" found at index " << index << endl;
    }
    else
    {
        cout << "Element "<<searchEle<<" not found in the array" << endl;
    }

    return 0;
}


/*
Array with previous size
Array elements: 0 0 0 0 0

Enter array size : 6
Array with given size
Array elements: 0 0 0 0 0 0

Enter index to insert : 3
Enter element to insert : 55
Array after inserting 55 at index 3
Array elements: 0 0 0 55 0 0 0

enter index to delete : 1
Array after deleting index 1 element
Array elements: 0 0 55 0 0 0

Enter element to search : 55
Element 55 found at index 2
*/


/*
Array with previous size
Array elements: 0 0 0 0 0

Enter array size : 6
Array with given size
Array elements: 0 0 0 0 0 0

Enter index to insert : 7
Invalid index for insert

enter index to delete : 9
Invalid index for insert

Enter element to search : 3
Element 3 not found in the array
*/
