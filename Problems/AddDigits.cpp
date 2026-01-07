#include <bits/stdc++.h>

using namespace std;

void add(string a, string b){
    
    if(b.size() == 0){
        cout<<a;
        return;
    } 
    if(a.size() == 0){
        cout<<b;
        return;
    }
    if(a.size() == 1 and b.size() == 1) {
        cout<<(int)a[0] + (int)b[0] - 96;
        return;
    }

    int number = 0, carry = 0;
    int i = a.size()-1, j = b.size()-1;
    vector<int> digit1, digit2;
    
    for(auto i : a) digit1.push_back((int)i - 48);
    for(auto i : b) digit2.push_back((int)i - 48);
    
    int c = 0;

    while(i >= 0 and j >= 0){
        number += (((digit1[i] + digit2[j]) + carry)%10)*pow(10, c++);
        // number *= 10;
        carry = digit1[i] + digit2[j] > 10 ? 1 : 0;
        i--;
        j--;
    }

    int bigger = a.size() > b.size() ? a.size() : b.size();

    if(i>=0){
        number += digit1[i]*pow(10,c++);
        i--;
    }
    if(j>=0){
        number += digit2[j]*pow(10, c++);
        j--;
    }

    cout<<"number : "<<number<<endl;
}


int main(){
    string a = "2";
    string b = "2";
    add(a, b);
    // cout<<(int)'0';
}