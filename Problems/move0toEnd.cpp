#include <bits/stdc++.h>

using namespace std;

int findPositiveAfter(int arr[], int n, int ind){
    for(int i=ind+1;i<n;i++){
        if(arr[i]){
            return i;
        }
    }
    return ind;
}

void move0toEnd(int arr[], int n){
    int ind;
    for(int i=0;i<n-1;i++){
        if(!arr[i]){
            
            ind = findPositiveAfter(arr, n, i);
            
            if(ind == i) return;
            
            else{
                swap(arr[i], arr[ind]);
            }
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1,2, 3, 4, 4,1};
    int length = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, length);
    cout<<endl;
    move0toEnd(arr, length);
    printArray(arr, length);
    cout<<endl;
    return 0;
}