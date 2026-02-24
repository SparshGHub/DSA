#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
    stack<char > str;
    for(auto i : s){
        if(str.empty()) {
            str.push(i);
            continue;
        }
        char t = str.top();
        if(i == '(' or i == '{' or i == '[') str.push(i);
        else if(t == '(' and i == ')') str.pop();
        else if(t == '[' and i == ']') str.pop();
        else if(t == '{' and i == '}') str.pop();
        else str.push(i);
    }
    return str.empty();
}

int main() {
    string s1, s2, s3;

    // cin >> s;
    s1 = "()[]{}";
    s2 = "([)]";
    s3 = "{[]}";
    cout << isValid(s1) << endl;
    cout << isValid(s2) << endl;
    cout << isValid(s3) << endl;
    return 0;
}