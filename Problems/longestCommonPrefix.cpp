#include<bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        int smol = 200;
        string s = "";
        for(auto i : strs) {
            if(i.length() < smol){
                smol = i.length();
                s = i;
            }
        }
        string maxSub = "";
        for(int i = 1 ; i <= smol ; i++){
            unordered_set<string> * m = new unordered_set<string>();
            for(auto j : strs) m->insert(j.substr(0,i));
            if(m->size() == 1) {
                maxSub = *(m->begin());
                delete(m);
            }
            else break;
        }
        return maxSub;
}

int main(){
    vector<string> s = {"pankaj", "panther", "pants", "pastel", "prlour"};
    // vector<string> a = {"lonsgest"};
    cout<<"\nLongest Common Prefix is - "<<longestCommonPrefix(s)<<endl;
    return 0;
}