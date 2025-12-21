
#include <bits/stdc++.h>

using namespace std;

//Practice 1
void explainPair();
void explainVector();
void explainStack();
void explainQueue();
void explainPriorityQueue();
void explainSet();
void explainUnorderedSet();
void explainMultiset();
void explainMap();
bool comp(pair<int, int> a, pair<int, int> b);

//Practice 2


//THE QUESTION THAT THIS COMPARATOR ASKS WHEN USED IN ANY CONTAINER(VECTOR, PRIORITY QUEUE, LIST ETC) IS WHETHER ELEMENT a SHOULD OCCUR BELOW ELEMENT b, IF YOU RETURN TRUE, a<b, ELSE a>b  
class comparator{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first>b.first) return true;
        else if(a.first == b.first) return b.second > a.second ;
        else return false;
    }
};

void print(priority_queue<pair<int,int>, vector<pair<int, int>>, comparator> a){

    while(!a.empty()){
        pair<int, int> p = a.top();
        cout<<p.first<<" "<<p.second<<endl;
        a.pop();
    }
}

void explainer(){
    // pair<int, string> p;
    // p.first = 12;
    // p.second = "Pankaj";
    // cout<<p.first<<" "<<p.second<<endl;

    // vector<pair<int, int>> v = {{2,1}, {4,2}};


    //PRIORITY QUEUE
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
    pq.push({2, 3});
    pq.push({1, 4});
    pq.push({4, 5});
    pq.push({8, 1});
    pq.push({4, 7});
    pq.push({4, 3});
    pq.push({4, 2});
    pq.push({1, 1});

    print(pq);

}


int main(){
    explainer();

    // int a; 
    // cin>>a;
    // explainPair();
    // explainVector();
    // explainStack();
    // explainQueue();
    // explainPriorityQueue();
    // explainSet();
    // explainUnorderedSet();
    // explainMultiset();
    // explainMap();


    //Sorting in ascending/descending order

    // int a[] = {1, 2, 4, 2, 5, 3, 7};

    // sort(a, a+7); //ascending
    // sort(a, a+7, greater<int>());//descending order 


    // //CUSTOM SORTING IN C++

    // pair<int, int> arr[] = {{1, 2}, {2, 3}, {3,1}, {4,1}, {1,4}};

    // //NOW TO SORT THE ARR CONTAINING PAIRS OF INTEGERS IN A CUSTOM FASHION -
    // //YOU NEED TO WRITE A COMPARATOR
    // for(auto i:arr){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    // sort(arr, arr+5, comp);
    // cout<<endl;
    // for(auto i:arr){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    return 0;
}

bool comp(pair<int, int> a, pair<int, int> b){
    //Basic sorting happens by looking at the second element in the pair in the ascending order
    if(a.second>b.second) return false;
    else if(a.second==b.second){
        //If the second elements are same, then the two are ordered in descending order of the first element
        if(a.first<b.first) return false;
        else return true;
    } 
    return true;
}


void explainUnorderedMap(){
    // IT STORES ELEMENTS IN A RANDOMISED ORDER WITH THE 
    //INSERTION AND DELETION OPERATION WORKING IN O(1) TIME
}

void explainMap(){
    map<int, int> m;
    // map<int, pair<int, int>> m;
    // map<pair<int, int>, int> m;

    //STORES KEY-VALUE PAIRS WITH KEYS IN SORTED ORDER
    m.insert({1,2});
    m.insert({2,2});
    m.insert({3,5});
    m.insert({4,5});
    m.insert({9,2});
    m.insert({5,2});
    m.insert({10,2});

}

void explainMultiset(){
    //WORKS JUST LIKE A SET, BUT CAN STORE MULTIPLE ELEMENTS ALSO
    multiset<int> m;
    m.insert(1);
    m.insert(1);
    m.insert(1);
    m.insert(2);
    m.insert(3);
    m.insert(4);
    m.insert(2);


    for(auto i : m){
        cout<<i<<endl;
    }
    //ERASE OPERATION (DELETES ALL THE OCCURENCES OF THE CHOSEN ELEMENT)
    cout<<endl;
    m.erase(1);
    for(auto i : m){
        cout<<i<<endl;
    }
}

void explainUnorderedSet(){
    unordered_set<int> st;
    
    //STORES UNIQUE ELEMENTS ONLY
    //NO PARTICULAR ORDER OF STORING ELEMENTS

    //INSERTION AND DELETION OPERATIONS HAPPEN IN O(1) TIME

}


void explainSet(){

    //ALL OPERATIONS TAKE LOG(N) TIME

    //STORES ELEMENTS IN SORTED ORDER AND ONLY STORES UNIQUE ELEMENTS
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(1);
    s.insert(5);
    s.insert(2);

    //OPERATIONS IN A SET
    auto it = s.find(2);
    auto n = s.find(1211);
    //returns the location of the number 2 in the set
    //If the number you are looking for is not present in the set,
    //then the iterator is placed at a position after the ending of the set

    auto it1 = s.find(1);
    auto it2 = s.find(3);
    s.erase(it1, it2);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    //LOWER BOUND & UPPER BOUND

    for (auto i : s )
    {
        cout<<i<<endl;
    }
    
    auto i1 = s.lower_bound(2); //finding the smallest element >=2
    auto i2 = s.upper_bound(3); //finding the smallest element >3

    cout<<" lower - "<<*i1<<endl<<" Upper - "<<*i2;
};

void explainPriorityQueue(){

    //MAX HEAP
    priority_queue<int>pq;
    pq.push(1);//[1]
    pq.push(3);//[3,1]
    pq.push(7);//[7,3,1]
    pq.push(4);//[7,4,3,1]
    pq.push(2);//[7,4,3,2,1]

    cout<<pq.top()<<endl;


    //MINIMUM HEAP USING PRIORITY QUEUE
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(1);//[1]
    pq1.push(3);//[1,3]
    pq1.push(7);//[1,3,7]
    pq1.push(4);//[1,3,4,7]
    pq1.push(2);//[1,2,3,4,7]

    //PUSH AND POP OPERATIONS TAKE log(n) time
}

void explainQueue(){
    queue<int> q;
    for(int i=0;i<5;i++){
        q.push(i+1);
    }

    //UNLIKE STACK, THE QUEUE HAS TWO VIEWING OPERATIONS
    cout<<q.back()<<endl<<q.front();
    // q.front();

    q.back()+=1;
    cout<<q.back();
}

void explainStack(){
    stack<int> s;
    for(int i=1;i<5;i++){
        s.push(i);
    }
    s.emplace(5);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    cout<<s.empty(); //boolean answer

}

void explainVector(){
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
        //v.emplace_back(i);
        //EMPLACE BACK IS FASTER
    }

    //HOW TO CREATE A VECTOR OF PAIRS
    vector<pair<int, int>> vPair;
    vPair.push_back({1, 2});
    vPair.emplace_back(1, 2);

    // for(auto i : vPair){
    //     cout<<" "<<i.first<<" "<<i.second;
    // }

    // //COPYING VECTOR
    // vector<int> v2(v); //creates another copy of v

    // //STANDARD VECTOR
    // vector<int> v3(5, 12);//creates a vector containing 5 instances of 12


    // //ITERATOR
    // vector<int>::iterator it = v.begin();
    // //allowed operations-  
    // //it++, it = it + 2;

    // for(vector<int>::iterator it = v.begin();it!=v.end();it++){
    //     cout<<" "<<*it<<" ";
    // }

    // //OR

    // for(auto it : v){
    //     cout<<it<<" ";
    // }

    //OPERATIONS IN A VECTOR

    //insertions
    vector<int> va(5, 0); //creates [0,0,0,0,0]
    va.insert(va.begin()+3, 1); //creates [0,0,0,1,0,0]
    va.insert(va.begin()+1, 4, 1); //creates [0,1,1,1,1,0,0,1,0,0]
    for(auto it : va){
        cout<<it<<" ";
    }
    cout<<endl;

    //YOU CAN ALSO COPY PARTICULAR SECTIONS OF A VECTOR INTO ANOTHER VECTOR
    vector<int> vb(5, 100);
    vb.insert(vb.begin()+2, va.begin()+1, va.begin()+4);
    // vb = [100, 100, 100, 100, 100]
    // After copying - vb = [100,100,1,1,1,100,100]
    for(auto it : vb){
        cout<<it<<" ";
    }

    cout<<endl;


    //deletions
    // va.erase(va.begin()+1); //deletes the element at the specified location
    va.erase(va.begin(), va.begin()+4); //deletes the range of elements -> va.begin(), va.begin()+1, va.begin()+2 and va.begin()+3
    for(auto it : va){
        cout<<it<<" ";
    }
}

void explainPair(){
    pair<int, int> p = {1, 3};

    cout<<p.first<<" "<<p.second<<endl;

    //NESTED PAIR
    pair<int, pair<int, int>> pp = {1, {2, 3}};

    cout<<pp.first<<" "<<pp.second.first<<" "<<pp.second.second<<endl;

    //ARRAY OF PAIRS
    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}};

    cout<<arr[0].first<<" "<<arr[0].second<<" "<<endl;

}