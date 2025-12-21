#include <bits/stdc++.h>

using namespace std;

void checkPall(long int a){
    stack<int> s;
    long int b = a;
    while(b>0){
        s.push(b%10);
        b=b/10;
    }
    while(!s.empty()){
        if(s.top()!=a%10) {
            cout<<"Not a Palindrome\n";
            return;
        }
        s.pop();
        a=a/10;
    }
    cout<<"Is a palindrome\n";
    return;
}

void checkArmstrong(long int a){
    // stack <int>s;
    long int b=a;
    long int s=0;
    while(b>0){
        s+=pow((b%10),3);
        b=b/10;
    }
    string result = s==a ? "Yes" : "No";
    cout<<result<<endl; 
}

void printAllDivs(long int a){
    for(long int i=1;i<a/2+1;i++){
        if(a%i==0) cout<<i<<endl;
    }
    cout<<a<<endl;
}

void printAllDivisors(long int a){
    set<int> s;
    for(long int i=1;i<pow(a,0.5)+1;i++){
        if(a%i==0){
            s.insert(i);
            s.insert(a/i);
        }
    }
    for(auto i:s){
        cout<<i<<endl;
    }
}

void checkPrime(long int a){
    if(a==1){
        cout<<"Not Prime\n";
        return;
    }
    for(long int i=2;i<a/2+1;i++){
        if(a%i==0){
            cout<<"Not Prime\n";
            return;
        }
    }
    cout<<"Is Prime\n";
    return;
}

void checkPrimeBetter(long int a){
    if(a==1){
        cout<<"Not Prime\n";
        return;
    }
    for(long int i=2;i<pow(a,0.5);i++){
        if(a%i==0 || a%(a/i)==0){
            cout<<"Not Prime\n";
            return;
        }
    }
    cout<<"Is Prime\n";
    return;
}

void GCD(long int a, long int b){
    long int m = min(a,b);
    long int n = a + b - m;
    long int res=1;
    for(long int i=2;i<m/2+1;i++){
        if(m%i==0 && n%i==0 && i>res){
            res = i;
        }
    }
    long int temp = res;
    res = n%m==0 ? m : temp;
    cout<<"GCD("<<a<<","<<b<<") = "<<res<<endl;
}

int main(){

    long int a;
    cin>>a;
    checkPall(a);
    checkArmstrong(a);
    printAllDivs(a);
    printAllDivisors(a); //Better version with O(sqRoot(n)) time complexity
    checkPrime(a);
    checkPrimeBetter(a);
    long int b;
    cin>>b;
    GCD(a,b);
    return 0;
}
