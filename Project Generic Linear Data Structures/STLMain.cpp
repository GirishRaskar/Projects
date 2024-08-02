#include<iostream>
using namespace std;


/////////////////////////////////////////////////////
//
//  ********** Singly Linear LinkedList **********
//
/////////////////////////////////////////////////////
template<class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template<class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();
       
        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template<class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;

    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
    iCount++;
}

template<class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = NULL;

    newn = new nodeSL<T>;

    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template<class T>
void SinglyLL<T>::InsertAtPos(T No,int iPos)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = NULL;
    int i = 0;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn = new nodeSL<T>;

        newn -> data = No;
        newn -> next = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        iCount++;
    }

}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = NULL;
    if(First == NULL)
    {
        cout<<"Unable to delete, Linkedlist is empty..";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;

        First = First -> next;
        delete temp;
    }
    iCount--;

}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to delete, LinkedList is empty.."<<endl;
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete (temp -> next);
        temp -> next = NULL;

    }
    iCount--;
}

template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeSL<T> * temp1 = NULL;
    struct nodeSL<T> * temp2 = NULL;
    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
       temp1 = First;

       for(i = 1; i < iPos - 1; i++)
       {
          temp1 = temp1 -> next;
       }    

       temp2 = temp1 -> next;
       temp1 -> next = temp2 -> next;
       delete temp2;

       iCount--;
    }
}


////////////////////////////////////////////////////
//
//  ******** Singly Circular Linkedlist ********
//
///////////////////////////////////////////////////
template<class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;
};

template<class T>
class SinglyCLL
{
    private:
        struct nodeSC<T> * First;
        struct nodeSC<T> * Last;
        int iCount;

    public:
        SinglyCLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template<class T>
void SinglyCLL<T>::Display()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    cout<<"->";
    do
    {
        cout<<"| "<<First -> data<<" |->";
        First = First -> next;
    }while(First != Last -> next);
    
    cout<<endl;
}

template<class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn -> data = No;
    newn -> next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
    Last -> next = First;
    iCount++;
}

template<class T>
void SinglyCLL<T>::InsertLast(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn -> data = No;
    newn -> next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last -> next = newn;
        Last = newn;
    }
    Last -> next = First;
    iCount++;
}

template<class T>
void SinglyCLL<T>::InsertAtPos(T No,int iPos)
{
    struct nodeSC<T> * newn = NULL;
    struct nodeSC<T> * temp = NULL;
    int i = 0;
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position..";
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn = new nodeSC<T>;
        
        newn -> data = No;
        newn -> next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
        iCount++;
    }
}

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Unable to delete, LL is empty.."<<endl;
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First -> next;
        delete(Last -> next);
        Last -> next = First;
    }
    iCount--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    struct nodeSC<T> * temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        cout<<"Unable to delete, LL is empty..";
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;

        while(temp -> next != Last)
        {
            temp = temp -> next;
        }

        delete(temp -> next);
        Last = temp;
        Last -> next = First;
    }
    iCount--;
}

template<class T>
void SinglyCLL<T>::DeleteAtPos(int iPos)
{
    
    struct nodeSC<T> * temp1 = NULL;
    struct nodeSC<T> * temp2 = NULL;
    int i = 0;
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position.."<<endl;
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        } 
        temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        delete temp2;
        iCount--;
    }
}


///////////////////////////////////////////////////
//
//  ********Doubly Linear LinkedList*********
//
///////////////////////////////////////////////////
template<class T>
struct nodeDL
{
    int data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template<class T>
class DoublyLL
{
    private:
        struct nodeDL<T> * First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

};

template<class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T> * temp = First;

    cout<<"NULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp -> data<<" |<=>";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template<class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> * newn = NULL;

    newn = new nodeDL<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First -> prev = newn;
        First = newn;
    }
    iCount++;
}

template<class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = NULL;

    newn = new nodeDL<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
    }
    iCount++;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = NULL;
    int i = 0;

    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDL<T>;

        newn -> data = No;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = First;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        newn -> prev = temp;
        newn -> next -> prev = newn;

        iCount++;
    }
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"Unable to delete , Linkedlist is empty"<<endl;
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete(First -> prev);
        First -> prev = NULL;
    }
    iCount--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to delete, Linkedlist is empty";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> prev -> next = NULL;
        delete temp;

    }
    iCount--;
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDL<T> * temp = NULL;
    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        delete (temp -> next -> prev);
        temp -> next -> prev = temp;
        iCount--;
    }
}


///////////////////////////////////////////////////
//
//   *********Doubly Circular Linkedlist*******
//
///////////////////////////////////////////////////
template<class T>
struct nodeDC 
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template<class T>
class DoublyCLL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount = 0;

    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template<class T>
void DoublyCLL<T>::Display()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linkedlist is empty.."<<endl;
        return;
    }
    cout<<"<=>";
    do 
    {
        cout<<"| "<<First -> data<<" |<=>";
        First = First -> next;
    }while(First != Last -> next);

    cout<<endl;
}

template<class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T No)
{
    struct nodeDC<T>* newn = NULL;

    newn = new nodeDC<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        First -> prev = newn;
        newn -> next = First; 
        First = newn;
    }

    First -> prev = Last;
    Last -> next = First;

    iCount++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        First -> prev = Last;
    }
    else
    {
        Last -> next = newn;
        newn -> prev = Last;
        Last = newn;
    }
        Last -> next = First;

        iCount++;
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * newn = NULL;
    struct nodeDC<T> * temp = NULL;
    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid Position..";
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn -> data = No;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = First;

        for(i = 1 ; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
        newn -> prev = temp;
        newn -> next -> prev = newn;

        iCount++;
    }
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Unable to delete, Linkedlist is empty";
        return;
    }

    if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First -> next;
        delete(Last -> next);
        Last -> next = First;
        First -> prev = Last;
        
    }
    iCount--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Unable to Delete, Linkedlist is empty.."<<endl;
        return;
    }

    else if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last -> prev;
        delete(Last -> next);
        Last -> next = First;
        First -> prev = Last;
        
    }
    iCount--;
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;
    
    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position.."<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete(temp -> next -> prev);
        temp -> next -> prev = temp;

        iCount--;
    }
}


/////////////////////////////////////////////////
//
//      ************* Stack*************
//
/////////////////////////////////////////////////
template<class T>
struct nodeS 
{
    T data;
    struct nodeS *next;
};

template<class T>
class Stack
{
    private:
        struct nodeS<T> * First;
        int iCount;

    public:
        Stack();

        void Display();
        int Count();

        void Push(T No);
        int Pop();
};

template<class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Stack<T>::Display()
{
    struct nodeS<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp -> data<<"\n";
        temp = temp -> next;
    }
}

template<class T>
int Stack<T>::Count()
{
    return iCount;
}

template<class T>
void Stack<T>::Push(T No)
{
    struct nodeS<T> * newn = NULL;

    newn = new nodeS<T>;

    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
    iCount++;
}

template<class T>
int Stack<T>::Pop()
{
    int iValue = 0;
    struct nodeS<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop element, Stack is empty..";
        return -1;
    }
    else
    {
        iValue = First -> data;
        temp = First;
        First = First -> next;
        iCount--;
        delete temp;
    }
    return iValue;
}


/////////////////////////////////////////////
//
//     *************Queue*************
//
/////////////////////////////////////////////
template<class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template<class T>
class Queue
{
    private:
        struct nodeQ<T> * First;
        int iCount;

    public:
        Queue();

        void Display();
        int Count();

        void EnQueue(T No);
        int DeQueue();
};

template<class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Queue<T>::Display()
{
    struct nodeQ<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp -> data<<"\t";
        temp = temp -> next;
    }
    cout<<endl;
}

template<class T>
int Queue<T>::Count()
{
    return iCount;
}

template<class T>
void Queue<T>::EnQueue(T No)
{
    struct nodeQ<T> * newn = NULL;
    struct nodeQ<T> * temp = NULL;

    newn = new nodeQ<T>;

    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template<class T>
int Queue<T>::DeQueue()
{
    int iValue = 0;
    struct nodeQ<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to delete, Queue is empty..";
        return -1;
    }
    else
    {
        iValue = First -> data;
        temp = First;
        First = First -> next;
        delete temp;
        iCount--;
    }

    return iValue;
}


///////////////////////////////////////////////
//
//          Searching And Sorting
//
///////////////////////////////////////////////
template<class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int Value);
        ~ArrayX();

        void Accept();
        void Display();

        bool LinearSearch(T Value);
        bool BiDirectionalSearch(T Value);
        bool BinarySearch(T Value);

        void BubbleSort();
        void BubbleSortEfficient();

        void SelectionSort();
        void InsertionSort();
};

template<class T>
ArrayX<T>::ArrayX(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template<class T>
ArrayX<T>::~ArrayX()
{
    delete []Arr;
}

template<class T>
void ArrayX<T>:: Accept()
{
    int i = 0;
    cout<<"Enter elements\n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template<class T>
void ArrayX<T>::Display()
{
    int i = 0;
    cout<<"Entered elements are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
}

template<class T>
bool ArrayX<T>::LinearSearch(T Value)
{
    int i = 0;
    bool bFlag = false;
    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

template<class T>
bool ArrayX<T>::BiDirectionalSearch(T Value)
{
    int iStart = 0;
    int iEnd = 0;
    bool bFlag = false;

    for(iStart = 0, iEnd = iSize-1; iStart <= iEnd; iStart++, iEnd--)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

template<class T>
bool ArrayX<T>::BinarySearch(T Value)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool flag = false;

    iStart = 0;
    iEnd = iSize - 1;
    while(iStart <= iEnd)
    {
        iMid = iStart +((iEnd - iStart)/2);

        if(Arr[iMid] == Value || (Arr[iStart] == Value) || (Arr[iEnd] == Value))
        {
            flag = true;
            break;
        }
        else if(Value < Arr[iMid])
        {
            iStart = iMid + 1;
        }
        else if(Value > Arr[iMid])
        {
            iEnd = iMid -1;
        }
    }

    return flag;

}

template<class T>
void ArrayX<T>::BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    for(i = 0; i < iSize - 1; i++) 
    {
        for(j = 0; j < (iSize -1) - i; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}

template<class T>
void ArrayX<T>::BubbleSortEfficient()
{
    T temp;
    bool flag = true;
    int i = 0, j = 0;

    for(i = 0; i < iSize - 1 && (flag == true); i++)
    {
        flag = true;

        for(j = 0; j < (iSize -1) - i; j++) 
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = false;
            }
        }
        
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}

template<class T>
void ArrayX<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize - 1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }   
}

template<class T>
void ArrayX<T>::InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for(i = 1; i < iSize; i++)
    {
        for(j = i-1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j+1] = selected;
    }
}

int main()
{

    cout<<endl<<"*********** Singly Linear Linkedlist ************"<<endl<<endl;

    SinglyLL<int> *obj = new SinglyLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);
    obj->Display();
    iRet = obj->Count();
    cout<<"The number of elements after using InsertFirst() are : "<<iRet<<endl<<endl;

    obj->InsertLast(61);
    obj->InsertLast(71);
    obj->InsertLast(81);
    obj->Display();
    iRet = obj->Count();
    cout<<"The number of elements after using InsertLast() are : "<<iRet<<endl<<endl;

    obj->InsertAtPos(31,3);
    obj->InsertAtPos(41,4);
    obj->Display();
    iRet = obj->Count();
    cout<<"The number of elements after using InsertAtPos() for position 3 and 4 are : "<<iRet<<endl<<endl;

    obj->DeleteFirst();
    obj->Display();
    iRet = obj->Count();
    cout<<"The number of elements after using DeleteFirst() are : "<<iRet<<endl<<endl;

    obj->DeleteLast();
    obj->Display();
    iRet = obj->Count();
    cout<<"The number of elements after using DeleteLast() are : "<<iRet<<endl<<endl;

    obj->DeleteAtPos(4);
    obj->Display();
    iRet = obj->Count();
    cout<<"The number of elements after using DeleteAtPos() for position 4 are : "<<iRet<<endl<<endl;


    cout<<endl<<endl<<"*********** Singly Circular Linkedlist ************"<<endl<<endl;
    SinglyCLL<int> *scobj = new SinglyCLL<int>();
    iRet = 0;
    scobj->InsertFirst(51);
    scobj->InsertFirst(21);
    scobj->InsertFirst(11);
    scobj->Display();
    iRet = scobj->Count();
    cout<<"The number of elements after using InsertFirst() are : "<<iRet<<endl<<endl;

    scobj->InsertLast(61);
    scobj->InsertLast(71);
    scobj->InsertLast(81);
    scobj->Display();
    iRet = scobj->Count();
    cout<<"The number of elements after using InsertLast() are : "<<iRet<<endl<<endl;

    scobj->InsertAtPos(31,3);
    scobj->InsertAtPos(41,4);
    scobj->Display();
    iRet = scobj->Count();
    cout<<"The number of elements after using InsertAtPos() for position 3 and 4 are : "<<iRet<<endl<<endl;

    scobj->DeleteFirst();
    scobj->Display();
    iRet = scobj->Count();
    cout<<"The number of elements after using DeleteFirst() are : "<<iRet<<endl<<endl;

    scobj->DeleteLast();
    scobj->Display();
    iRet = scobj->Count();
    cout<<"The number of elements after using DeleteLast() are : "<<iRet<<endl<<endl;

    scobj->DeleteAtPos(4);
    scobj->Display();
    iRet = scobj->Count();
    cout<<"The number of elements after using DeleteAtPos() for position 4 are : "<<iRet<<endl<<endl;


    cout<<endl<<endl<<"*********** Doubly Linear Linkedlist ************"<<endl<<endl;
    DoublyLL<int> *dlobj = new DoublyLL<int>();
    iRet = 0;
    dlobj->InsertFirst(51);
    dlobj->InsertFirst(21);
    dlobj->InsertFirst(11);
    dlobj->Display();
    iRet = dlobj->Count();
    cout<<"The number of elements after using InsertFirst() are : "<<iRet<<endl<<endl;

    dlobj->InsertLast(61);
    dlobj->InsertLast(71);
    dlobj->InsertLast(81);
    dlobj->Display();
    iRet = dlobj->Count();
    cout<<"The number of elements after using InsertLast() are : "<<iRet<<endl<<endl;

    dlobj->InsertAtPos(31,3);
    dlobj->InsertAtPos(41,4);
    dlobj->Display();
    iRet = dlobj->Count();
    cout<<"The number of elements after using InsertAtPos() for position 3 and 4 are : "<<iRet<<endl<<endl;

    dlobj->DeleteFirst();
    dlobj->Display();
    iRet = dlobj->Count();
    cout<<"The number of elements after using DeleteFirst() are : "<<iRet<<endl<<endl;

    dlobj->DeleteLast();
    dlobj->Display();
    iRet = dlobj->Count();
    cout<<"The number of elements after using DeleteLast() are : "<<iRet<<endl<<endl;

    dlobj->DeleteAtPos(4);
    dlobj->Display();
    iRet = dlobj->Count();
    cout<<"The number of elements after using DeleteAtPos() for position 4 are : "<<iRet<<endl<<endl;


    cout<<endl<<endl<<"*********** Doubly Circular Linkedlist ************"<<endl<<endl;
    DoublyCLL<int> *dcobj = new DoublyCLL<int>();
    iRet = 0;
    dcobj->InsertFirst(51);
    dcobj->InsertFirst(21);
    dcobj->InsertFirst(11);
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The number of elements after using InsertFirst() are : "<<iRet<<endl<<endl;

    dcobj->InsertLast(61);
    dcobj->InsertLast(71);
    dcobj->InsertLast(81);
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The number of elements after using InsertLast() are : "<<iRet<<endl<<endl;

    dcobj->InsertAtPos(31,3);
    dcobj->InsertAtPos(41,4);
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The number of elements after using InsertAtPos() for position 3 and 4 are : "<<iRet<<endl<<endl;

    dcobj->DeleteFirst();
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The number of elements after using DeleteFirst() are : "<<iRet<<endl<<endl;

    dcobj->DeleteLast();
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The number of elements after using DeleteLast() are : "<<iRet<<endl<<endl;

    dcobj->DeleteAtPos(4);
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The number of elements after using DeleteAtPos() for position 4 are : "<<iRet<<endl<<endl;


    cout<<endl<<endl<<"********************* Stack **********************"<<endl<<endl;
    Stack<char> *sobj = new Stack<char>();

    sobj->Push('E');
    sobj->Push('D');
    sobj->Push('C');
    sobj->Push('B');
    sobj->Push('A');

    sobj->Display();
    iRet = sobj->Count();
    cout<<"The count of Stack elements is : "<<iRet<<endl<<endl;

    char sRet = sobj->Pop();
    sobj->Display();
    cout<<"The Popped element is : "<<sRet<<endl;
    iRet = sobj->Count();
    cout<<"The count of Stack elements is : "<<iRet<<endl;


    cout<<endl<<endl<<endl<<"********************* Queue **********************"<<endl<<endl;
    Queue<char> *qobj = new Queue<char>();

    qobj->EnQueue('A');
    qobj->EnQueue('B');
    qobj->EnQueue('C');
    qobj->EnQueue('D');
    qobj->EnQueue('E');

    qobj->Display();
    iRet = qobj->Count();
    cout<<"The count of Queue elements is : "<<iRet<<endl<<endl;

    char qRet = qobj->DeQueue();
    qobj->Display();
    cout<<"The DeQueued element is : "<<qRet<<endl;
    iRet = qobj->Count();
    cout<<"The count of Queue elements is : "<<iRet<<endl<<endl;

    delete obj;
    delete scobj;
    delete dlobj;
    delete dcobj;
    delete sobj;
    delete qobj;

    return 0;
    
}