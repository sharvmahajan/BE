#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fibRec(ll n) {
    if (n <= 1) return n;
    return fibRec(n-1) + fibRec(n-2);
}

ll fibIterate(ll n) {
    if (n <= 1) return n;

    ll a = 0, b = 1, c = 0;

    for (ll i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    string choice;
    ll n;

    while (true) {
        cout << "\n1. Recursive\n";
        cout << "2. Iterative\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == "1" || choice == "2"){
            cout << "Enter n: ";
            cin >> n;

            if (n < 0) {
                cout << "Invalid input\n";
                continue;
            }

            if (choice == "1") cout << fibRec(n) << endl;
            else cout << fibIterate(n) << endl;
        }
        else if (choice == "3") {
            break;
        }
        else{
            cout << "Invalid choice\n";
        }
    }
    return 0;
}