#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

template<typename DT>
class Node{

        public:
                DT item;
                Node<DT> *next;
                Node(DT val, Node<DT> *nextp);
};

template<typename DT>
Node<DT>::Node(DT val, Node<DT> *nextp){
        item = val;
        next = nextp;
}

template<typename DT>
class LinkedList{

        protected:
                Node<DT> *head;
                Node<DT> *cursor;
                int n;
        public:
                LinkedList();
                void insert(const DT &item);
                void remove();
                void replace(const DT &item);
                void clear(); 
                void gotoBeginning();           
                bool gotoNext();    
                DT getCursor();
                void gotoEnd();
                bool gotoPrior();
}; 

//Constructor init
template<typename DT>
LinkedList<DT>::LinkedList(){
        head = NULL;
        cursor = NULL;
        n = 0;
}

template<typename DT>
void LinkedList<DT>::insert(const DT &item){
        if (!(n)){
                head = new Node<DT>(item, NULL);
                cursor = head;
        }
        else{
                Node<DT> *newnode = new Node<DT>(item, cursor -> next);
                cursor -> next = newnode;
                cursor = cursor -> next;
        }
        n++;
}

template<typename DT>
void LinkedList<DT>::remove(){
        if (cursor == head){
                head = head -> next;
                delete cursor;
                cursor = head;
                n--;
                return;
        }
        Node<DT> *prev = head;
        while(prev -> next != cursor){
                prev = prev -> next;
        }

        //last
        if (cursor -> next = NULL){
                prev -> next = NULL;
                delete cursor;
                cursor = head;
        }

        //general
        else{
                prev -> next = cursor -> next;
                delete cursor;
                cursor = prev -> next;
        }
        n--;
}

template<typename DT>
void LinkedList<DT>::replace(const DT &item){
        cursor -> item = item;
}

template<typename DT>
void LinkedList<DT>::clear(){
        cursor = head;
        while(cursor -> next != NULL){
                Node<DT> *temp = cursor -> next;
                delete cursor;
                cursor = temp;
        }
        n = 0;
        head = NULL;
        cursor = NULL;
}

template<typename DT>
void LinkedList<DT>::gotoBeginning() {
        cursor = head;
}

template<typename DT>
bool LinkedList<DT>::gotoNext() {
        if(cursor->next==NULL) return false;
        else {
                cursor = cursor->next;
                return true;
        }
}

template<typename DT>
DT LinkedList<DT>::getCursor(){
        return cursor -> item;
}

template<typename DT>
void LinkedList<DT>::gotoEnd(){
        while(cursor -> next != NULL) cursor = cursor -> next;
}

template<typename DT>
bool LinkedList<DT>::gotoPrior(){
        if (cursor == head) return false;
        Node<DT> *prev = head;
        while(prev -> next != cursor) prev = prev -> next;
        cursor = prev;
        return true;
}

int32_t main(){
        int n; int i;
        cin >> n;
        LinkedList<int> list;
        while(n--){
                cin >> i;
                list.insert(i);
        }
        int carry = 1;
        list.gotoEnd();
        int a = carry + list.getCursor();
        list.replace(a % 10);
        carry = a / 10;
        while(list.gotoPrior()){
                int a = carry + list.getCursor();
                list.replace(a % 10);
                carry = a / 10;
        }
        if (carry) cout << carry;
        cout << list.getCursor();
        while(list.gotoNext()) cout << list.getCursor();
}