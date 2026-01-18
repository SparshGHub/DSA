#include <bits/stdc++.h>

using namespace std;

void unitCountElement(int arr[], int n){
    int x = 0;
    for(int i=0;i<n;i++){
        x^=arr[i];
    }
    cout<<endl<<"Element that appears only once when others appear twice : "<<x<<endl;
}

int main(){
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    unitCountElement(arr, n);
    return 0;
}