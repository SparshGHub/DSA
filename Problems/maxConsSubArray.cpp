#include <bits/stdc++.h>

using namespace std;




//BRUTE FORCE
int lengthOfLongestSubArrayBrute(vector<int> arr, int s){
    int maxLen=0;
    int tSum=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size(); j++){
            tSum=0;
            for(int k=i;k<j;k++){
                tSum+=arr[k];
                if(tSum==s && k-i+1>maxLen) maxLen = k-i+1;
            }
        }
    }
    return maxLen;
}

//SUB-OPTIMAL
int lengthOfLongestSubArraySubOpt(vector<int> arr, int k){
    int maxLen=0;
    int tSum=0;
    for(int i=0;i<arr.size();i++){
        tSum = 0;
        for(int j=i;j<arr.size();j++){
            tSum+=arr[j];
            if(tSum == k && maxLen < j - i + 1) maxLen = j - i + 1; 
        }
    }
    return maxLen;
}


//THIS CODE IS FOR POSITIVES ONLY(WON'T WORK FOR 0s AND NEGATIVES)
int lengthOfLongestSubArrayPositives(int arr[], int k, int size){
    int i=0,j=0, sum=arr[0], maxLength = 0;
    
    while(i<=j && j<size){
        
        if(sum<k){
            j++;
            sum+=arr[j];
        }
        else if(sum == k){
            if (maxLength < j - i + 1) maxLength = j-i+1;
            sum -= arr[i]; 
            i++;
            j++;
            sum+= arr[j];
        }
        else{
            sum-=arr[i++];
        }
    }
    return maxLength;
}


int main(){
    int arr[] = {2, 5, 1, 4, 3, 2, 1, 1, 6, 8};
    int k = 7;
    vector<int> v = {2, 5, 1, 4, 3, -2, 1, 1, 6, 8};
    cout<<"SubOpt Length of longest subarray with sum = "<<k<<" -> "<<lengthOfLongestSubArraySubOpt(v, k)<<"\n\n";

    cout<<"Brute Length of longest subarray with sum = "<<k<<" -> "<<lengthOfLongestSubArrayBrute(v, k)<<"\n\n";
    cout<<"Positives Length of longest subarray with sum = "<<k<<" -> "<<lengthOfLongestSubArrayPositives(arr, k, 10)<<"\n\n";
    // cout<<"Kadane's Length of longest subarray with sum = "<<k<<" -> "<<kadaneAlgo(v, k)<<"\n\n";
}