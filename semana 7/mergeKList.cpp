
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
    struct cmp {
        bool operator() (const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(auto it: lists){
            ListNode* curr = it;
            while(curr){
                ListNode* temp = curr->next;
                curr->next = NULL;
                pq.push(curr);
                curr = temp;
            }
        }
        ListNode* m = new ListNode(0);
        ListNode* res = m;
        while(!pq.empty()){
            res->next = pq.top();
            res = res->next;
            pq.pop();
        }
        return m->next;
        
    }
};

// int main(){
//     Solution p;
//     vector<ListNode*> list = {{1,4,5},{1,3,4},{2,6}}
// }
