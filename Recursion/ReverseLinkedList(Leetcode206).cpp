/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
Example:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
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
