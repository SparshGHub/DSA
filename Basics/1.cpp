#include <bits/stdc++.h>

using namespace std;

void doSomething(int num){
    cout<<"Inside call by value\n";
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
    cout<<"End call by value\n";
}

void doSomeRef(int &num){
    cout<<num<<endl;
    num+=100;
    cout<<num;
};

int main(){
    // string s1, s2, s3;
    // cin>>s1>>s2;
    // //Getline is used to take input until a newline character is encountered. 
    // getline(cin, s3);
    // cout<<s1<<s2<<endl<<s3<<endl;

    // char a, b, c, d;
    // cin>>a>>b>>c>>d;
    // cout<<a<<b<<c<<d<<endl;
    // int age;
    // cin>>age;
    // if(age>17) cout<<"Adult\n";
    // else cout<<"Not an Adult\n";

    // for(int i=0;i<5;i++){
    //     cout<<"My name is thomas shelby\n";
    // }
    // cout<<"\nBREAK\n";
    // for(int i=0;i<5;++i){
    //     cout<<"My name is thomas shelby\n";
    // }

    //CALL BY VALUE(send a COPY)
    int num = 10;
    cout<<"Number before anything\n";
    cout<<num;
    doSomething(num);
    cout<<"Number after call by value\n";
    cout<<num;

    //CALL BY REFERENCE(send the OG)
    cout<<"Now calling by reference\n";
    doSomeRef(num);
    cout<<"Number after call by reference -> "<<num<<endl;
    return 0;

    map<int, int> m;
    for(int i=0;i<10;i++){
        m.emplace(i);
    }
    for(int i=0;i<10;i++){
        cout<<m[i]<<endl;
    }
    for(int i=0;i<10;i++){
        m.emplace(i,0);
    }
    for(int i=0;i<10;i++){
        cout<<m[i]<<endl;
    }
}