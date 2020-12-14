#include<bits/stdc++.h>
using namespace std;

void get_int();
void get_double();

int main() {
    get_int();
    cin.clear();
    cin.ignore(1000, '\n');
    get_double();
}

void get_int() {
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

void get_double() {
    double num;
    cout << "Enter a double number: ";
    while (!(cin >> num))
    {
        cout << "ERROR!, please enter a double number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "The number is: " << num << endl;
}