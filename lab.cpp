// Code by Arkishman Ghosh

#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

template <typename DT>
class SinglyLinkedNode
{
public:
        // data items in the node
        DT dataItem;
        SinglyLinkedNode<DT> *next;
        // constructor
        SinglyLinkedNode(DT nodeValue, SinglyLinkedNode<DT> *nextPointer);
};

template <typename DT>
SinglyLinkedNode<DT>::SinglyLinkedNode(DT nodeValue, SinglyLinkedNode *nextPointer)
{
        dataItem = nodeValue;
        next = nextPointer;
}

template <typename DT>
class SinglyLinkedList
{
        // We declare these members protected because we will inherit this class later
private:
        // Data Members
        SinglyLinkedNode<DT> *head;
        int numberOfItems;

        // These are utility functions that the main functions will call
        void insertEndRecursive(const DT &newDataItem, SinglyLinkedNode<DT> *current);
        void deleteEndRecursive(SinglyLinkedNode<DT> *current);
        void printForwardRecursive(SinglyLinkedNode<DT> *current);
        void printBackwardRecursive(SinglyLinkedNode<DT> *current);
        void moveNodeRecursive(int oldPosition, int newPosition, int count, SinglyLinkedNode<DT> *current);

public:
        // Constructor
        SinglyLinkedList();

        void insertEnd(const DT &newDataItem);
        void deleteEnd();
        void printForward();
        void printBackward();
        void moveNode(int oldPosition, int newPosition);
};

template <typename DT>
SinglyLinkedList<DT>::SinglyLinkedList()
{
        head = NULL;
        numberOfItems = 0;
}

template <typename DT>
void SinglyLinkedList<DT>::insertEnd(const DT &newDataItem)
{
        insertEndRecursive(newDataItem, head);
}

template <typename DT>
void SinglyLinkedList<DT>::insertEndRecursive(const DT &newDataItem, SinglyLinkedNode<DT> *current)
{
        if (numberOfItems == 0)
        {
                head = new SinglyLinkedNode<DT>(newDataItem, NULL);
        }

        else if (current->next == NULL)
        {
                current->next = new SinglyLinkedNode<DT>(newDataItem, NULL);
        }
        else
        {
                insertEndRecursive(newDataItem, current->next);
        }

        numberOfItems++;
}

template <typename DT>
void SinglyLinkedList<DT>::deleteEnd()
{
        deleteEndRecursive(head);
}

template <typename DT>
void SinglyLinkedList<DT>::deleteEndRecursive(SinglyLinkedNode<DT> *current)
{
        if (numberOfItems == 1)
        {
                delete head;
                head = NULL;
        }

        else if (current->next->next == NULL)
        {
                delete current->next;
                current->next = NULL;
        }

        else
        {
                deleteEndRecursive(current->next);
        }

        numberOfItems--;
}

template <typename DT>
void SinglyLinkedList<DT>::printForward()
{
        printForwardRecursive(head);
}

template <typename DT>
void SinglyLinkedList<DT>::printForwardRecursive(SinglyLinkedNode<DT> *current)
{
        if (current == NULL)
                return;

        cout << current->dataItem << " ";
        printForwardRecursive(current->next);
        if (current == head)
                cout << endl;
}

template <typename DT>
void SinglyLinkedList<DT>::printBackward()
{
        printBackwardRecursive(head);
}

template <typename DT>
void SinglyLinkedList<DT>::printBackwardRecursive(SinglyLinkedNode<DT> *current)
{
        if (current == NULL)
                return;

        printBackwardRecursive(current->next);
        cout << current->dataItem << " ";
        if (current == head)
                cout << endl;
}

template<typename DT>
void SinglyLinkedList<DT>::moveNode(int oldPosition, int newPosition)
{      
        moveNodeRecursive(oldPosition, newPosition, 1, head);
}

template<typename DT>
void SinglyLinkedList<DT>::moveNodeRecursive(int oldPosition, int newPosition, int count, SinglyLinkedNode<DT> *current)
{
        if (count == oldPosition){
                SinglyLinkedNode<DT>* temp = current;
                if (oldPosition == newPosition) return;
                swap(temp -> dataItem, temp -> next -> dataItem);
                count++; oldPosition++; current = current -> next;
                moveNodeRecursive(oldPosition, newPosition, count, current);
                return;
        }
        count++;
        current = current -> next;
        moveNodeRecursive(oldPosition, newPosition, count, current);
}

void solve(){
        SinglyLinkedList<int> list;
        for(int i=0; i<10; i++) list.insertEnd(i+1);
        list.printForward();
        list.moveNode(2, 8);
        list.printForward();
        list.printBackward();
}

int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int t = 1;
        // cin >> t;
        while (t--)
                solve();
        return 0;
}
