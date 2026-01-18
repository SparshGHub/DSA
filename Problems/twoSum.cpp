#include <bits/stdc++.h>

using namespace std;

bool checkTwoSum(int arr[], int size, int target){
    multiset<int> m; //map of target-num and index
    for(int i=0;i<size;i++){
        if(m.find(arr[i]) == m.end()) {
            m.insert(target - arr[i]);
        }
        else return true;
    }
    return false;
}


int main(){
    int arr[] = {2, 6, 4, 7, 3, 7, 9, 1, 3, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 10;
    cout<< (checkTwoSum(arr, size, target) ? "YES" : "NO");
}