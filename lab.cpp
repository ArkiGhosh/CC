#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

template<typename DataType>
class List{
        private:
                int length;
                int cursorPosition;
                int numberOfElements;
                vector<DataType> array;

        public:
                List(int listSize);
                void insert(const DataType &newDataItem);
                void remove();
                void replace(const DataType &newDataItem);
                void clear();
                bool isEmpty();
                bool isFull();
                void gotoBeginning();
                void gotoEnd();
                bool gotoNext();
                bool gotoPrior();
                DataType getCursor();
                void showStructure();
};

template<typename DataType>
List<DataType> :: List(int listSize){
        array.resize(listSize);
        length = listSize;
        cursorPosition = -1;
        numberOfElements = 0;
}

template<typename DataType>
void List<DataType> :: insert(const DataType &newDataItem){
        for(int i = numberOfElements - 1; i > cursorPosition; i--) array[i + 1] = array[i];
        array[cursorPosition + 1] = newDataItem;
        cursorPosition++;
        numberOfElements++;
}

template<typename DataType>
void List<DataType> :: remove(){
        for(int i = cursorPosition; i < numberOfElements - 1; i++) array[i] = array[i  +1];
        if (cursorPosition == numberOfElements - 1) cursorPosition--;
        //else cursorPosition++;
        numberOfElements--;
}

template<typename DataType>
void List<DataType> :: replace(const DataType &newDataItem){
        array[cursorPosition] = newDataItem;
}

template<typename DataType>
void List<DataType> :: clear(){
        array.clear();
        array.resize(length);
}

template<typename DataType>
bool List<DataType> :: isEmpty(){
        return numberOfElements == 0;
}

template<typename DataType>
bool List<DataType> :: isFull(){
        return numberOfElements == length;
}

template<typename DataType>
void List<DataType> :: gotoBeginning(){
        cursorPosition = 0;
}

template<typename DataType>
void List<DataType> :: gotoEnd(){
        cursorPosition = numberOfElements - 1;
}

template<typename DataType>
bool List<DataType> :: gotoNext(){
        if (cursorPosition == numberOfElements - 1) return false;
        else{
                cursorPosition++;
                return true;
        }
}

template<typename DataType>
bool List<DataType> :: gotoPrior(){
        if (cursorPosition == 0) return false;
        else{
                cursorPosition--;
                return true;
        }
}

template<typename DataType>
DataType List<DataType> :: getCursor(){
        return array[cursorPosition];
}

template<typename DataType>
void List<DataType> :: showStructure(){
        if (numberOfElements == 0){
                cout << "Empty List" << endl;
                return;
        }
        else{
                cout << "The number of elements in the list is " << numberOfElements << endl;
                for(int i = 0; i < numberOfElements; i++) cout << array[i] << endl;
        }
}

template<typename DataType>
vector<DataType> merge(List<DataType> l1, List<DataType> l2){
        vector<DataType> ans;
        l1.gotoBeginning();
        l2.gotoBeginning();
        ans.push_back(l1.getCursor());
        while(l1.gotoNext()){
                ans.push_back(l1.getCursor());
        }
        ans.push_back(l2.getCursor());
        while(l2.gotoNext()){
                ans.push_back(l2.getCursor());
        }
        sort(all(ans));
        return ans;
}

void solve(){
        List<string> l1(5);
        List<string> l2(3);
        l1.insert("aay");
        l1.insert("aaz");
        l1.insert("abx");
        l1.insert("aby");
        l1.insert("abz");

        l2.insert("aax");
        l2.insert("aazz");
        l2.insert("az");

        vector<string> ans = merge(l1, l2);
        for(int i = 0; i < sz(ans); i++) cout << ans[i] << endl;
}

int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int t = 1;
        //cin >> t;
        while (t--)
                solve();
        return 0;
}
