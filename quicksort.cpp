#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll partitionDeterministic(vector<ll>& arr, ll low, ll high){
    ll pivot = arr[low];
    ll i = low;
    for (ll j = low+1; j <= high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i]);
    return i;
}

ll partitionRandom(vector<ll>& arr, ll low, ll high){
    ll pi = low + (rand())%(high-low+1);
    swap(arr[pi], arr[low]);
    ll pivot = arr[low];
    ll i = low;
    for (ll j = low+1; j <= high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i]);
    return i;
}

void quickSortDeterministic(vector<ll>& arr, ll low, ll high){
    if (low >= high) return;
    ll pi = partitionDeterministic(arr, low, high);

    quickSortDeterministic(arr, low, pi-1);
    quickSortDeterministic(arr, pi+1, high);
}

void quickSortRandom(vector<ll>& arr, ll low, ll high){
    if (low >= high) return;
    ll pi = partitionRandom(arr, low, high);

    quickSortRandom(arr, low, pi-1);
    quickSortRandom(arr, pi+1, high);
}

int main(){
    vector<ll> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    quickSortDeterministic(arr, 0, arr.size()-1);
    for (ll i : arr) cout << i << " ";
    cout << endl;
    
    vector<ll> arr1 = {4, 6, 2, 5, 7, 9, 1, 3};
    quickSortRandom(arr1, 0, arr1.size()-1);
    for (ll i : arr1) cout << i << " ";
    cout << endl;
}
