/*Given the head of a singly linked list, reverse the list, and return the reversed list.
Example:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

*/

//Iterative approach

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head,*prev=NULL,*nxt=NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
};
