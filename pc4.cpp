//Escriba una función para eliminar elementos duplicados de una lista enlazadas no ordenada.
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *removeDuplicates(ListNode *head){

    if(head == nullptr)
        return head;
    
    unordered_set<int> st;
    ListNode *prev, *curr;
    curr = head;
    while (curr != nullptr)
    {
        auto it = st.find(curr->val);
        if(it == st.end()){
            st.insert(curr->val);
            prev->next = curr->next;
        }

        // if(!st.count(curr->val)){
        //     st.insert(curr->val);
        //     prev->next = curr->next;
        // }
        else{
            prev = curr;
        }

        curr = curr->next;
    }    
    return head;
}

void printList(ListNode *head) 
{ 
    while (head != NULL) 
    { 
        cout << head->val << endl; 
        head = head->next; 
    } 
} 
int main(){

    ListNode *lt = new ListNode(8);
    lt->next = new ListNode(12); 
    lt->next->next = new ListNode(11); 
    lt->next->next->next = new ListNode(11); 
    lt->next->next->next->next = new ListNode(12); 
    lt->next->next->next->next->next = new ListNode(11); 
    lt->next->next->next->next->next->next =  new ListNode(10);

    ListNode *lt2 = removeDuplicates(lt);
    printList(lt2);
       


    return 0;
}