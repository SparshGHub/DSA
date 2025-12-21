#include <bits/stdc++.h>

using namespace std;

// int findMax(int arr[]){
//     int m = 0;
//     int length = sizeof(arr) / sizeof(arr[0]);

//     for(int i=0;i<length;i++){
//         if(arr[i]>m) m = arr[i];
//     }
//     return m;
// }

// // int findMinIndex(int l, int r, int arr[]){
//     int m = findMax(arr);
//     int ind;
//     for(int i=l;i<=r;i++){
//         if(arr[i]<m){
//             ind = i;
//             m = arr[i];
//         }
//     }
//     return ind;
// }


void selectionSort(int arr[], int length){
    // int length = sizeof(arr) / sizeof(arr[0]);
    int minInd=0;
    int min;
    for(int i=0;i<length;i++){
        min=arr[i];
        minInd = i;
        for(int j=i+1;j<length;j++){
            if(arr[j]<min){
                minInd = j;
                min = arr[j];
            }     
        }
        swap(arr[minInd], arr[i]);
    }
}

void printArray(int arr[], int length){
    // int length = sizeof(arr) / sizeof(arr[0]);

    for(int i=0;i<length;i++){
        cout<<arr[i]<<endl;
    }
}

int find2Max(int arr[], int n){
    int m = arr[0];
    int m2 = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            m = arr[i];
        } 
        if(arr[i]<m2){
            m2 = arr[i];
        }
    }
    //now we have the max and the min element in m and m2
    int currMax = m2;
    for(int i=0;i<n;i++){
        if(arr[i]>m2 && arr[i]<m && arr[i]>currMax) currMax = arr[i];
    }
    return currMax;
}

int main(){
    int arr[] = {1, 4, 3, 67, 9, 12, 2, 3, 6 ,77, 77};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout<<"Second largest - "<<find2Max(arr, length)<<endl;
    selectionSort(arr, length);
    printArray(arr, length);
}