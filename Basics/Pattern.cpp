#include<iostream>

using namespace std;

void printStar(int num){
    for(int i=0;i<num;i++){
        cout<<"*";
    }
}

void printSpace(int num){
    for(int i=0;i<num;i++){
        cout<<" ";
    }
}

void pattern(int rows){
    int count=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<=i;j++){
            cout<<count++<<" ";
        }
        cout<<endl;
    }
}

void pattern1(int rows){
    bool b = 1;
    for(int i=0;i<rows;i++){
        if(i%2==0) b = 1;
        else b = 0 ; 
        for(int j=0;j<=i;j++){
            cout<<b<<" ";
            b = !b;
        }
        cout<<endl;
        // b=!b;
    }
}

void printFromTo(int a, int b){
    for(int i=a;i<=b;i++){
        cout<<" "<<i<<" ";
    }
}

void printRevFromTo(int a, int b){
    for(int i=a;i>=b;i--){
        cout<<" "<<i<<" ";
    }
}

void finalPattern(int rows){
    for(int i=1;i<=rows;i++){
        // int range = rows-i+1;
        printRevFromTo(rows, rows-i+1);
        for(int j=1;j<=2*(rows-i)-1;j++){
            cout<<" "<<rows-i+1<<" ";
        }

        if(rows-i+1==1) printFromTo(rows-i+2, rows);
        else printFromTo(rows-i+1, rows);
        cout<<endl;
    }

    for(int i=1;i<rows;i++){
        printRevFromTo(rows, i+1);
        for(int j=1; j<=2*i-1; j++){
            cout<<" "<<i+1<<" ";
        }
        printFromTo(i+1, rows);
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        printStar(i);
        printSpace(2*(n-i)+1);
        // printSpace(n-i);
        
        printStar(i);
        cout<<endl;
        cout<<endl;
    }
    pattern(n);
    for(int i=0;i<n;i++){
        printSpace(n-i-1);
        printStar(2*i+1);
        cout<<endl;
    }
    pattern1(n);
    cout<<endl;
    finalPattern(n);
    return 0;
}
