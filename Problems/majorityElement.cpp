#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> arr){
    unordered_map<int, int> countArr ;

    for(auto i : arr) countArr[i]++;
    
    // for(auto i : countArr) cout<<i<<endl;
    
    for(auto i : countArr) if (i.second > arr.size()/2) return i.first;
    return -1;
}

int optimalMajorityElement(vector<int> arr){
    int el;
    int count=0;
    for(int i = 1;i<arr.size();i++){
        if(count == 0) {
            el = arr[i];
            count = 1;
        }
        else if(el == arr[i])count++;
        else count--;
    }
    int c=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == el) c++;
    }
    return (c>= arr.size()/2) ? el : -1;
}

int main(){
    vector<int> arr ={2, 2, 3, 3, 1, 2, 2};
    int m = majorityElement(arr);
    cout<<"Majority Element here - "<<((m != -1) ? m : 0)<<endl;
    cout<<"Optimal Majority Element here - "<<optimalMajorityElement(arr);

}