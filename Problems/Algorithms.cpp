#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

int removeDup(int arr[], int n){
    int i=0 , j=1;
    while(j<n){
        if(arr[j]!=arr[i]){
            i++;
            arr[i] = arr[j];
            j++;
        }
        else{
            j++;
        }
    }
    for(int k=i+1;k<n;k++){
        arr[k] = 0;
    }
    return i;
}

void rotateBy1(int arr[], int n){
    int temp = arr[n-1];
    for (int i = n-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}


void rotateByN(int arr[], int length, int n){
    //call rotate by 1 'n' times
    while(n--){
        rotateBy1(arr, length);
    }
}

void print(int arr[], int n){
    int i=0;
    while(i<n){
        cout<<arr[i]<<" ";
        i++;
    }
}

void reverseArray(int arr[], int l, int r){
    while(l<r){
        swap(arr[l++], arr[r--]);
    }
}

void rotateOrderN(int arr[], int n, int length){
    reverseArray(arr, 0, n);
    reverseArray(arr, n, length);
    reverseArray(arr, 0, length);
}

int findPositiveAfter(int arr[], int n, int ind){
    for(int i=ind+1;i<n;i++){
        if(arr[i]){
            return i;
        }
    }
    return ind;
}

void move0toEnd(int arr[], int n){
    int ind;
    for(int i=0;i<n-1;i++){
        if(!arr[i]){
            
            ind = findPositiveAfter(arr, n, i);
            
            if(ind == i) return;
            
            else{
                swap(arr[i], arr[ind]);
            }
        }
    }
}

void takeUnion(int arr1[], int arr2[], int n1, int n2, vector<int>& unionArray) {
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        // If arr1[i] is smaller
        if (arr1[i] < arr2[j]) {
            if (unionArray.empty() || unionArray.back() != arr1[i]) {
                unionArray.push_back(arr1[i]);
            }
            i++;
        }
        // If arr2[j] is smaller
        else if (arr1[i] > arr2[j]) {
            if (unionArray.empty() || unionArray.back() != arr2[j]) {
                unionArray.push_back(arr2[j]);
            }
            j++;
        }
        // If arr1[i] == arr2[j], add only one of them
        else {
            if (unionArray.empty() || unionArray.back() != arr1[i]) {
                unionArray.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    // Add remaining elements of arr1
    while (i < n1) {
        if (unionArray.empty() || unionArray.back() != arr1[i]) {
            unionArray.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements of arr2
    while (j < n2) {
        if (unionArray.empty() || unionArray.back() != arr2[j]) {
            unionArray.push_back(arr2[j]);
        }
        j++;
    }
}

void takeIntersection(int a[], int b[], int n1, int n2, vector<int> & intersectionArray){
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a[i]==b[j]){
            if(intersectionArray.empty()){
                intersectionArray.push_back(a[i]);
            }
            else if(intersectionArray.back()!=a[i]){
                intersectionArray.push_back(a[i]);
            }
            i++;
            j++;
        }
        else if(a[i]>b[j]) j++;
        else if(a[i]<b[j]) i++;
    }
}

void printVector(const vector<int>& unionArray) {
    for (int x : unionArray) {
        cout << x << " ";
    }
    cout << endl;
}

void findMissingNumbers(int arr[], int l, vector<int> & missingNumbers){
    int i=0;
    while(i<l-1){
        if(arr[i+1]-arr[i]!=1) missingNumbers.push_back(arr[i]+1);
        i++;
    }
}

int maxConsecutive1(int arr[], int l){
    int m = 0;
    int currM = 0;
    for(int i=0;i<l;i++){
        if(arr[i]){
            currM+=1;
            if(currM>m) m = currM;
        }
        else currM = 0;
    }
    return m;
}


void unitCountElementXOR(int arr[], int n){
    int x = 0;
    for(int i=0;i<n;i++){
        x^=arr[i];
    }
    cout<<endl<<"Element that appears only once when others appear twice : "<<x<<endl;
}

void unitCountElement(int arr[], int n){
    unordered_map<int, int> m;
    //better to use unordered map because sorted order of elements isn;t a requirement
    // for(int i=0;i<n;i++){
    //     m.emplace(i,0);
    // }
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto i : m){
        cout<<((i.second == 1) ? to_string(i.first) : "");
    }

}

//BRUTE FORCE
int lengthOfLongestSubArrayBrute(vector<int> arr, int s){
    int maxLen=0;
    int tSum=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size(); j++){
            tSum=0;
            for(int k=i;k<j;k++){
                tSum+=arr[k];
                if(tSum==s && k-i+1>maxLen) maxLen = k-i+1;
            }
        }
    }
    return maxLen;
}

//SUB-OPTIMAL
int lengthOfLongestSubArraySubOpt(vector<int> arr, int k){
    int maxLen=0;
    int tSum=0;
    for(int i=0;i<arr.size();i++){
        tSum = 0;
        for(int j=i;j<arr.size();j++){
            tSum+=arr[j];
            if(tSum == k && maxLen < j - i + 1) maxLen = j - i + 1; 
        }
    }
    return maxLen;
}


//THIS CODE IS FOR POSITIVES ONLY(WON'T WORK FOR 0s AND NEGATIVES)
int lengthOfLongestSubArrayPositives(int arr[], int k, int size){
    int i=0,j=0, sum=arr[0], maxLength = 0;
    
    while(i<=j && j<size){
        
        if(sum<k){
            j++;
            sum+=arr[j];
        }
        else if(sum == k){
            if (maxLength < j - i + 1) maxLength = j-i+1;
            sum -= arr[i]; 
            i++;
            j++;
            sum+= arr[j];
        }
        else{
            sum-=arr[i++];
        }
    }
    return maxLength;
}

bool checkTwoSum(int arr[], int size, int target) {
    unordered_set<int> seen;
    for (int i = 0; i < size; i++) {
        if (seen.count(target - arr[i])) return true;
        seen.insert(arr[i]);
    }
    return false;
}


#define H 1
#define T 0


void guess(const vector<int>& observations, float phA, float phB, float l, float r) {
    
    float p = 0.5;  // prior belief

    for (int i : observations) {

        if (i == 1) { // Head
            p = (p * phA) / ((p * phA) + ((1 - p) * phB));

            if (p >= r) {
                cout << "Coin A\np = " << p;
                return;
            }
            else if (p <= l) {
                cout << "Coin B\np = " << p;
                return;
            }
            else {
                cout << "More observations needed (HEAD), p = " << p << endl;
            }
        }

        else { // Tail
            p = (p * (1 - phA)) / ((p * (1 - phA)) + (1 - p) * (1 - phB));

            if (p >= r) {
                cout << "Coin A\np = " << p;
                return;
            }
            else if (p <= l) {
                cout << "Coin B\np = " << p;
                return;
            }
            else {
                cout << "More observations needed (TAIL), p = " << p << endl;
            }
        }
    }
}

// int main(){
//     float phA = 2.0f/3.0f;
//     float phB = 1.0f/3.0f;
//     float lowerLimit = 0.3;
//     float upperLimit = 0.8;
//     vector<int> observations = {H, H, H, H, H, T, H, H, T, H, T};
//     guess(observations, phA, phB, lowerLimit, upperLimit);
// }

vector<int> kadaneAlgo(vector<int> v) {
    int maxSum = INT_MIN, sum = 0;
    int start = 0, s = 0, end = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i];

        if (sum > maxSum) {
            maxSum = sum;
            start = s;
            end = i;
        }

        if (sum < 0) {
            sum = 0;
            s = i + 1;
        }
    }

    return {maxSum, start, end};
}


int majorityElement(vector<int> arr){
    unordered_map<int, int> countArr ;

    for(auto i : arr) countArr[i]++;
    
    // for(auto i : countArr) cout<<i<<endl;
    
    for(auto i : countArr) if (i.second > arr.size()/2) return i.first;
    return -1;
}

int optimalMajorityElement(vector<int> arr){
    int el;
    int count=0;
    for(int i = 0;i<arr.size();i++){
        if(count == 0) {
            el = arr[i];
            count = 1;
        }
        else if(el == arr[i])count++;
        else count--;
    }
    int c=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == el) c++;
    }
    return (c>= arr.size()/2) ? el : -1;
}

// int main(){
//     vector<int> arr ={2, 2, 3, 3, 1, 2, 2};
//     int m = majorityElement(arr);
//     cout<<"Majority Element here - "<<((m != -1) ? m : 0)<<endl;
//     cout<<"Optimal Majority Element here - "<<optimalMajorityElement(arr);

//}
//SORT A GIVEN ARRAY CONTAINING ONLY 0s, 1s, 2s

//SUBOPTIMAL
void sort012(vector<int> & v){
    int a = 0 , b = 0, c = 0;
    for(auto i : v){
        if( i==0 ) a++;
        else if( i==1 )b++;
        else c++;
    }
    int i=0;
    while(a--) v[i++] = 0;
    while(b--) v[i++] = 1;
    while(c--) v[i++] = 2;
}

//OPTIMAL
void DutchNationalFlag(vector<int> & v){
    int low=0, mid=0, high = v.size()-1;
    while(low<=mid and mid<=high){
        if(v[mid] == 0) swap(v[low++], v[mid++]);
        else if(v[mid] == 1) mid++;
        else swap(v[high--], v[mid]);
    }
}

//OPTIMAL
int maxProfit(vector<int> a){
    int maxProfit=0;
    int m = a[0];
    for(auto i : a){
        m = min(m, i);
        maxProfit = max(maxProfit, i - m);
    }
    return maxProfit;
}

vector<int> rearrangeEqualAlternateSigns(vector<int>& arr) {
    vector<int> pos, neg;
    for (int x : arr) {
        if (x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }

    vector<int> ans(arr.size());
    int i = 0, p = 0, n = 0;
    bool turnPos = true;

    while (i < arr.size()) {
        if (turnPos && p < pos.size()) ans[i++] = pos[p++];
        else if (!turnPos && n < neg.size()) ans[i++] = neg[n++];
        turnPos = !turnPos;
    }
    return ans;
}

//    vector<int> arr = {1, 3, -2, 6, -78, -5, -45, 3, -5, -56, -45, 4, -5, 11};

void rearrangeUnequalAlternateSigns(vector<int>& arr) {
    vector<int> pos, neg;

    for (int x : arr) {
        if (x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }

    vector<int> ans(arr.size());
    int p = 0, n = 0, i = 0;

    // fill alternating until one runs out
    while (p < pos.size() && n < neg.size()) {
        ans[i++] = pos[p++];
        ans[i++] = neg[n++];
    }

    // append remaining positives
    while (p < pos.size()) ans[i++] = pos[p++];

    // append remaining negatives
    while (n < neg.size()) ans[i++] = neg[n++];

    arr = ans;
}



// int main(){
//     vector<int> arr = {1, 3, -2, 6, -78, -5, -45, 3, -5, -56, -45, 4, -5, 11};
//     // vector<int> arr = {1, 3, -2, 6, -78, -5, 45, 3, -5, -56, -45, 4, 5, -11};
//     cout<<"CURRENT ARRAY\n";
//     printArray(arr);
//     cout<<"REARRANGING IN ALTERNATIVE ORDER\n";
//     // arr = rearrangeEqualAlternateSigns(arr);
//     rearrangeUnequalAlternateSigns(arr);
//     printArray(arr);
//     return 0;
//}

double myPow(double x, int n);

// int main (int argc, char * argv[]){
//     cout<<myPow((double)stoi(argv[1]), stoi(argv[2]));
//}

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

// int main(){
//     vector<int> m = {3, 5, 5, 1 };
//     cout<<check(m);
//}

bool check(vector<int>& arr) {
    vector<int> nums(arr);
        int ind=0;
        int n = nums.size();
        bool a = true, b = true;
        int d = 0;
        for(; d < n - 1 ; d++){
            if(nums[d+1] >= nums[d]) continue;
            else break;
        }
        int c = 0;
        for(; c < n -1 ; c++){
            if(nums[c+1] <= nums[c]) continue;
            else break;
        }
        cout<<"a : "<<a<<" b : "<<b<<endl;
        if(c == n - 1 or d == n - 1) return true;
        
        for(int i = 0 ; i < n - 1 ; i++){
            if(nums[i+1] < nums[i]){
                ind = i;
                break;
            }  
        }
        
        cout<<ind;
        for(int i = 0; i < (ind+1)/2 ; i++){
            swap(nums[i], nums[ind - i]);
        }
        
        // printVector(nums);
        
        for(int i = ind+1 ; i< ind + (n-ind)/2  ; i++){
            swap(nums[i], nums[n - i - 1]);
        }
        
        // printVector(nums);
        
        for(int i = 0 ; i < n/2 ; i++){
            swap(nums[i], nums[n - i - 1]);
        }
        
        // printVector(nums);
        
        for(int i = 0 ; i < n - 1; i++){
            if(nums[i + 1] < nums[i]) return false;
        }
        
        return true;
    }

#define SUCCESS 1 
#define FAILURE 0

bool nthRootOfM(int , long m);
bool copyOfTheAboveFunction(long m, int n);
long binaryExponentiation(long m, int n);


bool nthRootOfM(int n, long m){
    long begin = 1;
    long current = 1;
    int count = 1;
    if(m == 1) {
        cout<<m<<" raised to 1/"<<n<<" is "<<current<<endl;
        return true;
    }
    if(n == 1){
        cout<<m<<" raised to 1/"<<n<<" is "<<m<<endl;
        return true;
    }
    while(current <= m ){
        while(count <= n){
            if(current == m && count == n) {
                cout<<m<<" raised to 1/"<<n<<" is "<<begin<<endl;
                return true;
            }
            current *= begin;
            if(current > m) break;
            count++;
        }
        begin++;
        current = begin;
        count = 1;
    }
    cout<<"Integer Value Not found\n";
    return false;
}

long binaryExponentiation(long x, int n) {
    long result = 1;
    while (n > 0) {
        if (n & 1) result *= x;
        x *= x;
        n >>= 1;
    }
    return result;
}

bool copyOfTheAboveFunction(long m, int n) {
    if (m == 1 || n == 1) {
        cout << n << "th root of " << m << " is " << m << endl;
        return SUCCESS;
    }

    long low = 1, high = m;
    while (low <= high) {
        long mid = (low + high) / 2;
        long val = binaryExponentiation(mid, n);

        if (val == m) {
            cout << n << "th root of " << m << " is " << mid << endl;
            return SUCCESS;
        }

        if (val > m) high = mid - 1;
        else low = mid + 1;
    }

    cout << "Integer Value Not Found\n";
    return FAILURE;
}



// int main(){
//     long m;
//     int n;
//     cout<<"Enter m and n"<<endl;
//     cin>>m>>n;
//     bool status = copyOfTheAboveFunction(m, n);
//     cout<<"STATUS : "<<status;
// }

int smallestYWithCommonDigit(int x){
    int m = 9;
    if(x%10 == 0) return x;
    while(x>0){
        m = min(m, x%10);
        x = x/10;
    }
    return m;
}

// int main(){
//     int t;
//     cin>>t;
//     int x;
//     while(t--){
//         cin>>x;
//         cout<<smallestYWithCommonDigit(x);
//     }
//     return 0;
// }

void maximumNumberOfPeaks(vector<int> v, int k){
    int n = v.size();
    int l = 0, r = 0;
    int count = 0;
    int maxPeaks = 0;
    bool canTake = false;
    while(l < n){
        if(v[l] == 0){
            if(!canTake) count++;
            if(count == k){
                maxPeaks++;
                count = 0;
                canTake = 1;
            } 
            else if(canTake && count == 1){
                canTake == 0;
                count = 0;
            }
            // else count++;
        }
        if(canTake) canTake = false;
        l++;
    }
    cout<<endl<<maxPeaks<<endl;
}


struct Node{
    int val;
    struct Node * next;
    Node(int x) : val(x), next(NULL){}
    Node() : next(NULL){}
};

Node * createLinkedList(vector<int> arr){
    Node * head = new Node(arr[0]);
    Node * temp = head;
    for(auto it = arr.begin()+1;it<arr.end();it++){
        Node * x = new Node(*it);
        temp->next = x;
        temp = temp->next;
    }
    return head;
}

void printLinkedList(Node * head){
    Node * temp = head;
    while(temp->next){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<temp->val;
    cout<<"\n";
}
Node * returnLast(Node * head){
    Node * temp = head;
    while(temp->next){
        temp = temp->next;
    }
    return temp;
}

void createLoop(Node * last, Node * randomNode){
    last->next = randomNode;
    cout<<"\nLoop created\n b/w last node and "<<randomNode->val<<endl;
}

Node * findRandomMiddle(Node * head, int size){
    int min = 1, max = size;

    // Seed the random number generator
    std::srand(std::time(0));  // Use current time as the seed

    // Generate a random integer in the range [min, max]
    int random_number = min + (std::rand() % (max - min + 1));

    Node * temp = head;
    while(min<random_number){
        temp = temp->next;
        min++;
    }
    return temp;
}

void findFirstNodeInLoop(Node * head){
    if(!head || !head->next) cout<<"\nNULL\n";

    Node * slow = head, * fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast ) {
            break;
        }
    }

    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    if(slow==fast){
        cout<<"Loop between last node and -> "<<slow->val;
        return;
    }
    cout<<"\nNULL\n";
}

//FIND THE NUMBER OF INTEGER PAIRS WHOSE SUM IS LESS THAN SOME TARGET

int numIntPairs(int arr[], int n, int target) {
    int l = 0, r = n - 1;
    int count = 0;

    while (l < r) {
        if (arr[l] + arr[r] < target) {
            count += (r - l);
            l++;
        } else {
            r--;
        }
    }

    return count;
}


void merge(int arr[], int l , int m, int h){
    int p1 = l, p2 = m+1;
    int arrCopy[h-l+1];
    int count=0;
    while (p1 <= m && p2 <= h) {
        if(arr[p1] <= arr[p2]) {
            arrCopy[count++] = arr[p1++];
        } 
        else{
            arrCopy[count++] = arr[p2++];
        }
    }

    while (p1 <= m) {
        arrCopy[count++] = arr[p1++];
    }

    while (p2 <= h) {
        arrCopy[count++] = arr[p2++];
    }

    for (int i = 0; i < count; i++) {
        arr[l + i] = arrCopy[i];
    }

}

void mergeSort(int arr[], int low, int high){
    int m = (low+high)/2;
    if(low>=high) return;
    mergeSort(arr, low, m);
    mergeSort(arr, m+1, high);
    merge(arr, low, m, high);
}

vector<int> subarraySum(vector<int> &arr, int target) {
    int n = arr.size();
    int l = 0, r = 0, sum = arr[0];

    while (r < n) {
        if (sum == target) {
            return {l + 1, r + 1}; // 1-based
        }

        if (sum < target) {
            r++;
            if (r < n) sum += arr[r];
        } else {
            sum -= arr[l];
            l++;
            if (l > r && l < n) {
                r = l;
                sum = arr[l];
            }
        }
    }

    return {}; // not found
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

int findMax(vector<int> v){
    int m = 0;
    for(auto i : v){
        if(i>m) m = i;
    }
    return m;
}

double logarithm(int a, int b) {

    if (a <= 0) {
        throw invalid_argument("Logarithm of non-positive numbers is not defined.");
    }

    if (b <= 1) {
        throw invalid_argument("Logarithm base must be greater than 1.");
    }

    return log(a) / log(b);
}

double exponentiation(int a, int b) {

    if (a == 0) {
        cout << "0 raised to any power is 0." << endl;
    }

    if (b < 0) {
        throw invalid_argument("Negative exponent results in a fraction.");
    }

    return pow(a, b);
}

double squareRoot(int a) {

    if (a < 0) {
        throw invalid_argument("Square root of negative numbers is not defined.");
    }

    return sqrt(a);
}

bool checkPrime(long x){

    for(long int i=2;i<=sqrt(x);i++){
    
        if(x%i==0 ){
            // cout<<"\nNO\n";
            return false;
        }
    }

    return true;
}

vector<int> findFactors(long num) {
    vector<int> factors;

    for (long i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            factors.push_back(i);
            if (num / i != i)
                factors.push_back(num / i);
        }
    }

    sort(factors.begin(), factors.end());
    return factors;
}
