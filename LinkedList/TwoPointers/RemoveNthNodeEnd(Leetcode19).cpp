/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



 //We'll be maintaining 2 pointers 
 //p1 would point to the head
 //p2 would point N units away from head
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * p1 = head;
        ListNode * p2 = head;
        int cnt = 0;

        //Make p2 point n units away from head
        while(cnt < n){
            p2 = p2->next;
            cnt++;
        }   

        //If p2 becomes NULL, nth node from the end is head itself
        if(!p2){
            ListNode * tmp=head;
            head=head->next;
            delete(tmp);

            //return head
            return head;
        } 

        //Increment both p1 and p2 until p2->next is not null
        while(p2->next!=NULL){
            p1=p1->next;
            p2=p2->next;
        }  

        //Store p1->next in tmp
        ListNode * tmp = p1->next;
        //Make appropriate changes
        p1->next=p1->next->next;
        //Delete temp
        delete(tmp);


        return head;
    }


};
