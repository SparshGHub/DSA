#include <bits/stdc++.h>

using namespace std;


//OPTIMAL
int maxProfit(vector<int> a){
    int maxProfit=0;
    int m = a[0];
    for(auto i : a){
        m = min(m, i);
        maxProfit = max(maxProfit, i - m);
    }
    return maxProfit;
}

int main(){
    vector<int> prices = {7, 1, 5, 4, 6, 3};
    cout<<"Max Profit : "<<maxProfit(prices);
}