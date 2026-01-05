#include <bits/stdc++.h>

using namespace std;

int nCount = 5;
void printName(string name){
    if(nCount==0) return;

    cout<<name<<endl;
    nCount--;
    printName(name);
}

void printNameBackTrack(string name){
    if(nCount==0) return;
    nCount--;
    printNameBackTrack(name);
    cout<<name<<endl;
}

void printFromNto1(int n){
    if(n==0) return;
    cout<<n<<endl;
    printFromNto1(n-1);
}

void printFrom1toN(int n){
    if(n==0) return;
    printFrom1toN(n-1);
    cout<<n<<endl;
}

int sum(int n){
    if(n==0) return 0;
    return n + sum(n-1);
}

int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}

bool checkPal(string s){    
    if(s.length()==1) return true;
    if(s[0]!=s[s.length()-1]) return false;
    return checkPal(s.substr(1,s.length()-2));
}

int fibonacci(int n){
    if(n==1) return 0;
    else if(n==2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

void takeInput(vector<int> &v, int n){
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
}

int findMax(vector<int> v){
    int m = 0;
    for(auto i : v){
        if(i>m) m = i;
    }
    return m;
}

void fillCount(vector<int> input, vector<int> &v){
    for(auto i:input){
        v[i]++;
    }
}

void printVector(vector<int> v){
    for(auto i : v){
        cout<<" "<<i<<endl;
    }
}

void fillMap(vector<int> v, map<int , int> &m){
    for(auto i : v){
        m[i]++;
    }
}

void printMap(map<int, int> m){
    for(auto i : m){
        cout<<"Count of "<<i.first<<" -> "<<i.second<<endl;
    }
}

int main(){
    // printName("sparsh");
    int n;
    cin>>n;
    // // printNameBackTrack("siddharth");
    // printFrom1toN(n);
    // printFromNto1(n);
    // cout<<sum(n)<<endl;
    // cout<<"Factorial "<<n<<" = "<<factorial(n);
    // string s;
    // cin>>s;
    // cout<<checkPal(s)<<endl;
    // cout<<"Fibonacci "<<fibonacci(n);


    cout<<"Enter "<<n<<" elements\n";
    vector<int> input;
    takeInput(input,n);
    int m = findMax(input);
    vector<int> v(m+1,0);

    printVector(v);
    fillCount(input, v);
    printVector(input);
    cout<<"Here is the corresponding count vector\n";
    printVector(v);

    //Another way to create the count vector - Hashmap - better(uses lesser memory)
    map<int, int> countMap;
    fillMap(input, countMap);
    printMap(countMap);
    //A better way to make use of this is to store it in an unordered map
    return 0;
}