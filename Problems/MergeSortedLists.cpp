
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 and !list2) return nullptr;
        ListNode * head = new ListNode();
        ListNode * t1 = list1, * t2 = list2, * t3 = head;
        while(t1 and t2){
            ListNode * x = new ListNode();
            if(t1->val >= t2->val){
                x->val = t2->val;
                t2 = t2->next;
            }
            else{
                x->val = t1->val;
                t1 = t1->next;
            }
            t3->next = x;
            t3 = t3->next;
        }
        while(t1) {
            ListNode * x = new ListNode(t1->val);
            t1 = t1->next;
            t3->next = x;
            t3 = t3->next;
        }
        while(t2){
            ListNode * x = new ListNode(t2->val);
            t2 = t2->next;
            t3->next = x;
            t3 = t3->next;
        }
        ListNode * ans = head->next;
        delete(head);
        return ans;
    }
};

void printList(ListNode * head){
    ListNode * t = head;
    while(t){
        cout<<" "<<t->val<<" "<<endl;
        t = t->next;
    }
}

int main(){
    ListNode * h1 = new ListNode(1);
    h1->next = new ListNode(1);
    h1->next->next = new ListNode(2);
    h1->next->next->next = new ListNode(3);

    ListNode * h2 = new ListNode(2);
    h2->next = new ListNode(2);
    h2->next->next = new ListNode(4);
    h2->next->next->next = new ListNode(9);

    Solution * s = new Solution();
    ListNode * merged = s->mergeTwoLists(h1, h2);
    printList(merged);

    return 0;
}