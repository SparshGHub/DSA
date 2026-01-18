#include <bits/stdc++.h>

using namespace std;

//USING A HASHMAP

void unitCountElement(int arr[], int n){
    unordered_map<int, int> m;
    //better to use unordered map because sorted order of elements isn;t a requirement
    // for(int i=0;i<n;i++){
    //     m.emplace(i,0);
    // }
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto i : m){
        cout<<((i.second == 1) ? to_string(i.first) : "");
    }

}

int main(){
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    unitCountElement(arr, n);
    return 0;

}