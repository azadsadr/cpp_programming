#include<bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cout << "Enter an integer number: ";
    while (!(cin >> num))
    {
        cout << "ERROR!, please enter an integer number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "The number is: " << num << endl;    
}