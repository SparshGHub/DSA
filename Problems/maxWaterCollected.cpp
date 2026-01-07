#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int l = 0, r = height.size()-1;
    long maxA = 0;
    while(l<r){
        maxA = max(maxA,(long)((min(height[l], height[r]))*(r-l)));
        if(height[l] >= height[r]) r--;
        else l++;
    }
    return maxA;
}

int main(){
    vector<int> heights = {1, 6, 4, 9,6, 5, 3,10, 1, 13};
    cout<<maxArea(heights);
}