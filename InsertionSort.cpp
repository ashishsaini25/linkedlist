// Sort a linked list using insertion sort.

// We have explained Insertion Sort at Slide 7 of Arrays

// Insertion Sort Wiki has some details on Insertion Sort as well.

// Example :

// Input : 1 -> 3 -> 2

// Return 1 -> 2 -> 3


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;

ListNode* InsertionSortList(ListNode* A) {
    ListNode *temporary=new ListNode(-1);
    temporary->next=A;
    ListNode *curr=A;
    ListNode *prev=temporary;
    ListNode *start=temporary;
    while(curr!=NULL){
        if(curr->next&&(curr->val>curr->next->val)){
            while(prev->next&&prev->next->val<curr->next->val)prev=prev->next;
            ListNode *temp=prev->next;
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev->next->next=temp;
            prev=start;
        }
        else 
        curr=curr->next;
    }
    return temporary->next;
}
