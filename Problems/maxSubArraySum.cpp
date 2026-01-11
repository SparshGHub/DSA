#include <bits/stdc++.h>

using namespace std;

vector<int> kadaneAlgo(vector<int> v){
    int maxi = INT_MIN;
    int sum=0;
    int start=-1;
    int end=-1;
    for(int i=0;i<v.size();i++){
        sum += v[i];
        if(sum > maxi){
            maxi = sum;
            end = i;
        } 
        if(sum < 0){
            sum=0;
            start = i+1;
        }
    }
    vector<int> ans;
    ans.push_back(maxi);
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}

void outPut(vector <int> arr, vector <int> ans ){
    cout<<"MaximumSum of SubArray is - "<<ans[0]<<"\n\n";
    cout<<"And the subArray is - \n\n";
    while(ans[1]<=ans[2]){
        cout<<arr[ans[1]++]<<" ";
    }
}

int main(){
    vector<int> vec = {1, 4, 6, -3, -5, -2, 1, 3 ,5, -1};
    vector<int> v;
    int c;
    cin>>c;
    int temp;
    while(c--){
        cin>>temp;
        v.push_back(temp);
    }
    
    outPut(vec, kadaneAlgo(vec));

}