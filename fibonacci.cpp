#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll fiboRec(ll n){
    if (n <= 1) return 0;
    if (n == 2) return 1;
    return fiboRec(n-1)+fiboRec(n-2);
}

ll fiboIterative(ll n){
    if (n <= 1) return 0;
    if (n == 2) return 1;
    ll a = 0, b = 1, c;
    for (ll i = 3; i <= n; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    // cout << fiboRec(10) << endl;
    cout << fiboIterative(5000) << endl;
}
