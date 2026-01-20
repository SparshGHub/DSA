#include <bits/stdc++.h>

using namespace std;

void rotateBy1(int arr[], int n){
    for(int i=0;i<n;i++){
        swap(arr[n-i-1], arr[0]);
    }
}

void rotateByN(int arr[], int length, int n){
    //call rotate by 1 'n' times
    while(n--){
        rotateBy1(arr, length);
    }
}

void printArray(int arr[], int n){
    int i=0;
    while(i<n){
        cout<<arr[i]<<" ";
        i++;
    }
}


//WORK IT OUT
// void rotateOrderN(int arr[], int length, int n){
    // int j;
    // for(int i=0;i<length;i=i+n){
        // j=0;
        // while(j<n){
            // swap(arr[i+j],arr[i+j+n]);
            // j++;
        // }
    // }
// }
// 

void reverseArray(int arr[], int l, int r){
    for(int i=l;i<(r+l)/2;i++){
        swap(arr[i], arr[l+r-i-1]);
    }
}

void rotateOrderN(int arr[], int n, int length){
    reverseArray(arr, 0, n);
    reverseArray(arr, n, length);
    reverseArray(arr, 0, length);
}

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    cout<<"Rotate by ? -"<<endl;
    int n;
    cin>>n;
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"before rotation\n";
    printArray(arr, length);

    auto start = std::chrono::high_resolution_clock::now();
    // rotateByN(arr, length, n%length);
    rotateOrderN(arr, n, length);
    //VERY IMPORTANT - THE MOD OPERATION n%length
    cout<<"After rotation by - "<<n<<endl;
    printArray(arr, length);
    cout<<"\n\n";
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " ms" << std::endl;
    return 0;
}