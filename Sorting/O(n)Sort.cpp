#include <bits/stdc++.h>

using namespace std;

int findMax(int arr[], int length){
    int m= arr[0];
    for(int i=0;i<length;i++){
        if(arr[i]>m) m = arr[i];
    }
    return m;
}

void fillArr(int arr[], int arr1[], int length){
    for(int i=0;i<length;i++){
        arr1[arr[i]]++;
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}

void sortOrderN(int arr1[], int sortedArray[], int m, int length){
    int ind=0;
    for(int i=0;i<m+1;i++){
        while(arr1[i]){
            sortedArray[ind] = i;
            ind++;
            arr1[i]--;
        }
    }
}

int main(){
    int arr[] = {1, 4, 3, 7, 9, 7, 5, 13, 54, 7, 6, 3, 4, 5};
    int length = sizeof(arr)/sizeof(arr[0]);
    int m = findMax(arr, length);
    // cout<<"Max is - "<<m<<endl;
    int arr1[m+1] = {0};
    fillArr(arr, arr1, length);
    printArray(arr1, m+1);    
    int sortedArray[length] = {0};
    sortOrderN(arr1, sortedArray, m, length);
    cout<<"Sorted\n";
    printArray(sortedArray, length);
    return 0;
}