#include <bits/stdc++.h>
using namespace std;

int main() {

    string previous = "";
    string current;
    int counter = 1;

    while (getline(cin, current)) {

        if (current == previous) {
            counter++;
        } else if (previous != "") {
            cout << "\t" << counter << " " << previous << endl;
            counter = 1;
        }
        
        previous = current;
    }
}