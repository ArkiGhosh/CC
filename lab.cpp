#include "bits/stdc++.h"
using namespace std;
#define int long long 
#define endl "\n"

class Logbook{
    private:
        int logMonth;
        int logYear;
        int daysInMonth;
        vector<int> entries;
        bool isLeapYear(int year);
    
    public:
        Logbook(int month, int year);
        void putEntry(int day, int value);
        int getEntry(int day);
        int getMonth();
        int getYear();
        int getDaysInMonth();
        bool hasTargetBeenReached(int target);
        int longestConsecutiveSubsequence();
};

bool Logbook :: isLeapYear(int year){
    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0){
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

Logbook :: Logbook(int month, int year){
    logMonth = month;
    logYear = year;

    vector<int> daysList = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(logYear) == true) daysInMonth = 29;
    else daysInMonth = daysList[logMonth - 1];
    
    entries.resize(daysInMonth, 0);    
}

void Logbook :: putEntry(int day, int value){
        entries[day - 1] = value;
}

int Logbook :: getEntry(int day){
    return entries[day];
}

int Logbook :: getMonth(){
    return logMonth;
}

int Logbook :: getYear(){
    return logYear;
}

int Logbook :: getDaysInMonth(){
    return daysInMonth;
}

bool Logbook :: hasTargetBeenReached(int target){
    int sum = 0;
    for(int i = 0; i < daysInMonth; i++) sum += entries[i];
    if (sum >= target) return true;
    else false;
}

int Logbook :: longestConsecutiveSubsequence(){
    sort(entries.begin(), entries.end());
    vector<int> length;
    int ch = 1;
    for(int i = 0; i < daysInMonth; i++){
        if (entries[i] == 0) ch = 0;
    }
    if (ch){
        int l = 1;
        for(int i = 1; i < daysInMonth; i++){
            if (entries[i] == entries[i - 1] + 1) l++;
            else{
                length.push_back(l);
                l = 1;
            }
        }
        length.push_back(l);
        sort(length.begin(), length.end());
        return length[(int)length.size() - 1];
    }
    else return 0;
}

int32_t main()
{
    Logbook testLogbook(2, 2020);
    for(int i = 1;i <= 29;i += 4) testLogbook.putEntry(i, i+5);

    if (testLogbook.hasTargetBeenReached(160)) cout<< "YES" << endl;
    if (testLogbook.hasTargetBeenReached(120)) cout<< "NO" << endl;

    for(int i=1;i<=29;i++){
        if(i % 2 == 0) testLogbook.putEntry(i, i / 2);
        else testLogbook.putEntry(i, i + 100);
    }
    cout << testLogbook.longestConsecutiveSubsequence() << endl;
    return 0;
}