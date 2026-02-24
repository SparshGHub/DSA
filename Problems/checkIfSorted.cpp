#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> & nums);
void print(vector<int> & nums);

int main(){
    vector<int> m = {3, 5, 5, 1 };
    cout<<check(m);
}

void print(vector<int> & nums){
    cout<<endl;
    for(auto i : nums){
        cout<<" "<<i<<" ";
    }
    cout<<endl;
}

bool check(vector<int>& arr) {
    vector<int> nums(arr);
        int ind=0;
        int n = nums.size();
        bool a = true, b = true;
        int d = 0;
        for(; d < n - 1 ; d++){
            if(nums[d+1] >= nums[d]) continue;
            else break;
        }
        int c = 0;
        for(; c < n -1 ; c++){
            if(nums[c+1] <= nums[c]) continue;
            else break;
        }
        cout<<"a : "<<a<<" b : "<<b<<endl;
        if(c == n - 1 or d == n - 1) return true;
        
        for(int i = 0 ; i < n - 1 ; i++){
            if(nums[i+1] < nums[i]){
                ind = i;
                break;
            }  
        }
        
        cout<<ind;
        for(int i = 0; i < (ind+1)/2 ; i++){
            swap(nums[i], nums[ind - i]);
        }
        
        print(nums);
        
        for(int i = ind+1 ; i< ind + (n-ind)/2  ; i++){
            swap(nums[i], nums[n - i - 1]);
        }
        
        print(nums);
        
        for(int i = 0 ; i < n/2 ; i++){
            swap(nums[i], nums[n - i - 1]);
        }
        
        print(nums);
        
        for(int i = 0 ; i < n - 1; i++){
            if(nums[i + 1] < nums[i]) return false;
        }
        
        return true;
    }