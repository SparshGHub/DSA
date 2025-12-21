// LIST OF ALL THE USEFUL STRING METHODS IN CPP STL

#include <bits/stdc++.h>

using namespace std;

int main(){
    //SUBSTRINGS CAN BE REFERRED TO USING THE .substr(index, lengthToGo) METHOD
    string s1 = "34214114123124";
    string subs1A = s1.substr(0, 6); // 342141
    string subs1B = s1.substr(5); // 4123124

    //THE .find(substring) METHOD CAN BE USED TO FIND THE INDEX OF FIRST OCCURENCE OF A PARTICULAR SUBTRING IN ANOTHER STRING
    string A = "MYnameIS anothony Anthgy Anthony Gonsalv Anthony Gonsalves";
    int index = A.find("Anthony Gonsalves");
    cout<<subs1A<<endl<<subs1B<<endl<<A<<endl<<index;

    //THE .rfind(subtring) METHOD CAN BE USED TO FIND THE INDEX OF LAST OCCURENCE OF A PARTICULAR SUBTRING IN ANOTHER STRING
    string C = "IS";
    int index1 = A.rfind(C);
    cout<<"index 1  : "<<index1<<"\nREVERSE : ";
    reverse(A.begin(), A.end());
    int i = 0, j = A.size()-1;
    while(i<j){
        swap(A[i++], A[j--]);
        // i++;
        // j--;
    }
    cout<<endl<<A;

    // A.insert(C, 32);ss


    return 0;

}