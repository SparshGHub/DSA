#include <bits/stdc++.h>

using namespace std;

void print(vector<int> & arr);


int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size()-1;
        int count = 0;
        for(auto i : nums){
            if(i == val) count++;
        }
        while(l < r){
            if(nums[l] == val and nums[r]!=val) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            else if(nums[l] == val and nums[r] == val){
                r--;
            }
            else if(nums[l]!=val and nums[r]!=val){
                l++;
                // r--;
            }
            else l++;
        }
        print(nums);
        return nums.size() - count;
}

void print(vector<int> & arr){
    cout<<endl;
    for(auto i : arr){
        cout<<" "<<i<<" ";
    }
    cout<<endl;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr = {1, 4, 3, 2, 5, 3,2 , 2, 3, 4,2 };
    print(arr);
    removeElement(arr, n);
    // print(arr);
    return 0;
}