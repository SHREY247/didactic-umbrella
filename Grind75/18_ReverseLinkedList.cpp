/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
  Intuition
The code can be implemented using both iterative and recursive approaches, but here iterative solution would be more efficient than the recursive one

Approach(Iterative)
1: Initialize curr to the head of the linked list, prev to NULL, and tmp to NULL.
2: Traverse through the linked list using a while loop.
Inside the loop:
a) Store the address of the next node in tmp.
b) Reverse the link of the current node (curr) to point to the prev.
c) Update prev to be the current node (curr).
d) Move curr to the next node (tmp).
e) After the loop, prev will be pointing to the new head of the reversed list. Return prev.

Time complexity
O(N)

Space complexity
O(1)

Code for Iterative Approach:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //prev is used to point to the head of the linked list that has already been reversed
        //Therefore, initially prev is initialized to NULL
        ListNode *curr=head,*prev=NULL,*tmp=NULL;
        //Run the loop till curr is not null
        while(curr){
            tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
};
Code for Recursive Approach:
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
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //Base case: Only 1 node left in the list so every single node is reverse of itself
        //Also, handle the case of empty linled list
        if(  (head==NULL) || (head->next == NULL)){
            return head;
        } 

        //tmp tracks the node next to the head
        ListNode* tmp = head->next;
        //Delink the head from the list and make it point to NULL
        head->next=NULL;
        //Call reverse function on the remaining linked list that starts from tmp
        ListNode *p = reverseList(tmp);
        //Link back the earlier node that we had delinked 
        tmp->next=head;

        //Return the linked list with head node as p
        return p;
    }
};
