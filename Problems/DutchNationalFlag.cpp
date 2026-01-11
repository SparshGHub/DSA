#include <bits/stdc++.h>

using namespace std;

//SORT A GIVEN ARRAY CONTAINING ONLY 0s, 1s, 2s

//SUBOPTIMAL
void sort012(vector<int> & v){
    int a = 0 , b = 0, c = 0;
    for(auto i : v){
        if( i==0 ) a++;
        else if( i==1 )b++;
        else c++;
    }
    int i=0;
    while(a--) v[i++] = 0;
    while(b--) v[i++] = 1;
    while(c--) v[i++] = 2;
}

//OPTIMAL
void DutchNationalFlag(vector<int> & v){
    int low=0, mid=0, high = v.size()-1;
    while(low<=mid and mid<=high){
        if(v[mid] == 0) swap(v[low++], v[mid++]);
        else if(v[mid] == 1) mid++;
        else swap(v[high--], v[mid]);
    }
}

void printArray(vector<int> & v){
    for(auto i : v){
        cout<<" "<<i<<" ";
    }
}

int main(){
    vector<int> v = {2, 2, 2,1, 1, 1,0, 0, 0 };
    DutchNationalFlag(v);
    // sort012(v);
    printArray(v);
}