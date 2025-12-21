#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l , int m, int h){
    int p1 = l, p2 = m+1;
    int arrCopy[h-l+1];
    int count=0;
    while (p1 <= m && p2 <= h) {
        if(arr[p1] <= arr[p2]) {
            arrCopy[count++] = arr[p1++];
        } 
        else{
            arrCopy[count++] = arr[p2++];
        }
    }

    while (p1 <= m) {
        arrCopy[count++] = arr[p1++];
    }

    while (p2 <= h) {
        arrCopy[count++] = arr[p2++];
    }

    for (int i = 0; i < count; i++) {
        arr[l + i] = arrCopy[i];
    }

}

void mergeSort(int arr[], int low, int high){
    int m = (low+high)/2;
    if(low>=high) return;
    mergeSort(arr, low, m);
    mergeSort(arr, m+1, high);
    merge(arr, low, m, high);
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}

int main(){
    int arr[] = {3,1};
    printArray(arr, 2);
    mergeSort(arr, 0, 1);
    cout<<endl;
    printArray(arr, 2);
    return 0;
}