#include <bits/stdc++.h>

using namespace std;

int maxConsecutive1(int arr[], int l){
    int m = 0;
    int currM = 0;
    for(int i=0;i<l;i++){
        if(arr[i]){
            currM+=1;
            if(currM>m) m = currM;
        }
        else currM = 0;
    }
    return m;
}

void printArray(int arr[], int l){
    cout<<endl;
    for(int i=0;i<l;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1};
    int l = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, l);
    cout<<maxConsecutive1(arr, l)<<endl;
}