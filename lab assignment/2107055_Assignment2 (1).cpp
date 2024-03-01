#include <bits/stdc++.h>

using namespace std;

class Array
{
    int Size;
    int *arr;

public:
    Array(int initialSize) : Size(initialSize)
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
        delete[] arr;
        arr = new int[Size](); /*to initialize an array of a given size with default values (e.g., zeros)*/
    }

    void insertElement(int index, int value)
    {
        if (index < 0 || index > Size)
        {
            throw "Invalid index for insert ";
        }
        int *newArray = new int[Size + 1];

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
        if (index < 0 || index >= Size)
        {
            cout << "Invalid index for delete " << endl;
        }
        int *newArray = new int[Size - 1];

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

    bool checkSorted()
    {
        for (int i = 0; i < Size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    int Binary_Search(int val)
    {
        int l = 0, r = Size - 1, mid, ans = 0;

        if (!checkSorted())
        {
            throw "array is not sorted";
        }
        else
        {
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (arr[mid] == val)
                {
                    return mid;
                }
                else if (arr[mid] < val)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            return -1;
        }


    }

    int upper_Bound(int value)
    {
        int l = 0, r = Size - 1, mid, result = -1;

        if (!checkSorted())
        {
            throw "array is not sorted";
        }
        
            if(arr[r]<=value)
            {
                 return -1; 
            }
           
            
            while (l <= r)
            {
                mid = (l + r) / 2;

                if (arr[mid] <= value)
                {
                    l = mid + 1;
                    result = l;
                }
                else
                {
                    r = mid - 1;
                }
            }

            return result;
}


    

    int lower_Bound(int value)
    {
        
        int l = 0, r = Size - 1, mid, result = 0;
        if (!checkSorted())
        {
            throw "array is not sorted";
        }
        else
        {
            
            if(arr[r]<value || arr[l]>value)
            {
                 return -1; 
            }
            
            while (l < r)
            {
                mid = (l + r) / 2;

                if (arr[mid] < value)
                {
                    l = mid + 1;
                    result = l;
                }
                else
                {
                    r = mid;
                }
            }
            return result;
        }

    }

    int one_sided_binary(int val)
    {
        if (!checkSorted())
        {
            throw "array is not sorted";
        }
        else
        {
            int lg = log2(Size - 1) + 1;

            int pos = 0;

            for (int i = lg; i >= 0; i--)
            {
                if (arr[pos] == val)
                    return pos;

                int new_pos = pos | (1 << i);

                if ((new_pos < Size) && (arr[new_pos] <= val))
                    pos = new_pos;
            }

            return ((arr[pos] == val) ? pos : -1);
        }
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
    Array testArray(10);
    cout << "Array with previous size " << endl;
    testArray.traverseArray();
    cout << endl;

    int arraySize;
    cout << "Enter array size : ";
    cin >> arraySize;
    testArray.createArray(arraySize);
    cout << "Array with given size " << endl;
    testArray.traverseArray();
    cout << endl;

    int k;
    while (1)
    {
        cout << "enter 2 to insert an element" << endl;
        cout << "enter 3 to search an element" << endl;
        cout << "enter 4 to search an element using binary" << endl;
        cout << "enter 5 to delete an element" << endl;
        cout << "enter 6 to search lower bound of value" << endl;
        cout << "enter 7 to search upper bound of value" << endl;
        cout << "enter 8 to search using one-sided binary search" << endl;
        cout << "enter 9 to exit" << endl;
        cin >> k;
        if (k == 2)
        {
            int indexInsert, ele;
            cout << "Enter index to insert : ";
            cin >> indexInsert;

            cout << "Enter element to insert : ";
            cin >> ele;

            try
            {

                testArray.insertElement(indexInsert, ele);
            }
            catch (char const* e)
            {
                cout << e << endl;
                continue;
            }

            cout << "Array after inserting " << ele << " at index " << indexInsert << endl;
            testArray.traverseArray();

            cout << endl;
        }
        if (k == 3)
        {
            int searchEle;
            cout << "Enter element to search : ";
            cin >> searchEle;
            int index = testArray.searchElement(searchEle);
            if (index != -1)
            {
                cout << "Element " << searchEle << " found at index " << index << endl;
            }
            else
            {
                cout << "Element " << searchEle << " not found in the array" << endl;
            }
            cout << endl;
        }
        if (k == 4)
        {
            int value;
            cout << "enter value to find using binary search ";
            cin >> value;
            try
            {

                int found = testArray.Binary_Search(value);



                if (found != -1)
                {
                    cout << "value " << value << " found at index " << found << endl;
                }
                else if (found == -1)
                {
                    cout << "value " << value << " not found" << endl;
                }
            }
            catch (char const *e)
            {
                cout <<e<< endl;
                continue;
            }
        }
        if (k == 5)
        {
            int delEleIndex;
            cout << "enter index to delete : ";
            cin >> delEleIndex;

            try
            {

                testArray.deleteElement( delEleIndex);
            }
            catch (char const* e)
            {
                cout << e << endl;
                continue;
            }


            cout << "Array after deleting index " << delEleIndex << " element " << endl;
            testArray.traverseArray();

            cout << endl;
        }
        if (k == 6)
        {
            int lowerValue;
            cout << "enter lower value to find using binary search ";
            cin >> lowerValue;
            try
            {

                int lwfound = testArray.lower_Bound(lowerValue);


                if (lwfound != -1)
                {
                    cout << "value " << lowerValue << " found at index " << lwfound << endl;
                }
                else if (lwfound == -1)
                {
                    cout << "Value " << lowerValue << "  is less than the smallest element in the array or greater than the largest element in the array" << endl;
                }
            }
            catch (char const *e)
            {
                cout <<e<< endl;
                continue;
            }
        }
        if (k == 7)
        {
            int upperValue;
            cout << "enter upper value to find using binary search ";
            cin >> upperValue;
            try
            {

                int upfound = testArray.upper_Bound(upperValue);


                if (upfound != -1)
                {
                    cout << "value " << upperValue << " found at index " << upfound << endl;
                }
                else if (upfound == -1)
                {
                    cout << "Value " << upperValue << " is greater than or equal to the largest element in the array" << endl;
                }
            }
            catch (char const *e)
            {
                cout <<e<< endl;
                continue;
            }
        }
        if (k == 8)
        {
            int val;
            cout << "enter value to find using one sided binary search ";
            cin >> val;
            try
            {
                int found = testArray.one_sided_binary(val);
                if (found != -1)
                {
                    cout << "value " << val << " found at index " << found << endl;
                }
                else if (found == -1)
                {
                    cout << "value " << val << " not found" << endl;
                }
            }
            catch (char const *e)
            {
                cout <<e<< endl;
                continue;
            }
        }
        if (k == 9)
        {
            return 0;
        }
    }

    return 0;
}

/*
input
0
2 0 9
2 0 6
2 0 6
2 0 6
2 0 4
2 0 2
2 0 1
3 4
4 10
5 6
6 6
7 6
8 2
8 12
9
*/

/*
output
Array with previous size
Array elements: 0 0 0 0 0 0 0 0 0 0

Enter array size : Array with given size
Array elements:

enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
Enter index to insert : Enter element to insert : Array after inserting 9 at index 0
Array elements: 9

enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
Enter index to insert : Enter element to insert : Array after inserting 6 at index 0
Array elements: 6 9

enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
Enter index to insert : Enter element to insert : Array after inserting 6 at index 0
Array elements: 6 6 9

enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
Enter index to insert : Enter element to insert : Array after inserting 6 at index 0
Array elements: 6 6 6 9

enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
Enter index to insert : Enter element to insert : Array after inserting 4 at index 0
Array elements: 4 6 6 6 9

enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
Enter index to insert : Enter element to insert : Array after inserting 2 at index 0
Array elements: 2 4 6 6 6 9

enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
Enter index to insert : Enter element to insert : Array after inserting 1 at index 0
Array elements: 1 2 4 6 6 6 9

enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
Enter element to search : Element 4 found at index 2

enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
enter value to find using binary search value 10 not found
enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
enter index to delete : Array after deleting index 6 element
Array elements: 1 2 4 6 6 6

enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
enter lower value to find using binary search
value 6 found at index 3
enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
enter upper value to find using binary search
value 6 found at index 5
enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
enter value to find using one sided binary search
value 2 found at index 1
enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
enter value to find using one sided binary search
value 12 not found
enter 2 to insert an element
enter 3 to search an element
enter 4 to search an element using binary
enter 5 to delete an element
enter 6 to search lower bound of value
enter 7 to search upper bound of value
enter 8 to search using one-sided binary search
enter 9 to exit
*/
/*
6 10
6 0
6 6
6 3
7 10
7 6
7 5
Value 10  is less than the smallest element in the array or greater than the largest element in the array
Value 0  is less than the smallest element in the array or greater than the largest element in the array
value 6 found at index 3
value 3 found at index 2
Value 10 is greater than or equal to the largest element in the array
Value 6 is greater than or equal to the largest element in the array
value 5 found at index 3
*/