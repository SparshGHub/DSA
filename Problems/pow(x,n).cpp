#include <bits/stdc++.h>

using namespace std;

double myPow(double x, int n);

int main (int argc, char * argv[]){
    cout<<myPow((double)stoi(argv[1]), stoi(argv[2]));
}
double myPow(double x, int n) {
    if (n == 0) return 1.0;
    
    if (n == INT_MIN) { 
        return 1.0 / (myPow(x, INT_MAX) * x);  
    }

    double y = 1.0;
    long long exp = abs((long long)n);  //This conversion is done to avoid an error for very large negative n

    for (long long i = 0; i < exp; i++) {
        y *= x;
    }

    return (n < 0) ? 1.0 / y : y;
}
