// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// For example,

// Given 1->4->3->2->5->2 and x = 3,

// return 1->2->2->4->3->5.
#include <bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
ListNode *Partition(ListNode *A, int X){
      ListNode *left=new ListNode(0);
    ListNode *right=new ListNode(0);
    ListNode *start=A;
    ListNode *lf= left;
    ListNode *rg=right;
    while(start!=NULL){
        if(start->val<x){
            lf->next=start;
            lf=lf->next;
        }
        else {
            rg->next=start;
            rg=rg->next;
        }
        start=start->next;
    }
    lf->next=right->next;
    rg->next=NULL;
    return left->next;
}