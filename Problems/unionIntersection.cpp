#include <bits/stdc++.h>
using namespace std;

void takeUnion(int arr1[], int arr2[], int n1, int n2, vector<int>& unionArray) {
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        // If arr1[i] is smaller
        if (arr1[i] < arr2[j]) {
            if (unionArray.empty() || unionArray.back() != arr1[i]) {
                unionArray.push_back(arr1[i]);
            }
            i++;
        }
        // If arr2[j] is smaller
        else if (arr1[i] > arr2[j]) {
            if (unionArray.empty() || unionArray.back() != arr2[j]) {
                unionArray.push_back(arr2[j]);
            }
            j++;
        }
        // If arr1[i] == arr2[j], add only one of them
        else {
            if (unionArray.empty() || unionArray.back() != arr1[i]) {
                unionArray.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    // Add remaining elements of arr1
    while (i < n1) {
        if (unionArray.empty() || unionArray.back() != arr1[i]) {
            unionArray.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements of arr2
    while (j < n2) {
        if (unionArray.empty() || unionArray.back() != arr2[j]) {
            unionArray.push_back(arr2[j]);
        }
        j++;
    }
}

void takeIntersection(int a[], int b[], int n1, int n2, vector<int> & intersectionArray){
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a[i]==b[j]){
            if(intersectionArray.empty()){
                intersectionArray.push_back(a[i]);
            }
            else if(intersectionArray.back()!=a[i]){
                intersectionArray.push_back(a[i]);
            }
            i++;
            j++;
        }
        else if(a[i]>b[j]) j++;
        else if(a[i]<b[j]) i++;
    }
}

void printVector(const vector<int>& unionArray) {
    for (int x : unionArray) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 1, 2, 3, 4, 5};
    int arr2[] = {5, 6, 7, 8, 9};
    vector<int> unionArray;
    vector<int> intersectionArray;
    int l1 = sizeof(arr1) / sizeof(arr1[0]);
    int l2 = sizeof(arr2) / sizeof(arr2[0]);

    takeUnion(arr1, arr2, l1, l2, unionArray);
    printVector(unionArray);
    takeIntersection(arr1, arr2, l1, l2, intersectionArray);
    printVector(intersectionArray);

    return 0;
}
