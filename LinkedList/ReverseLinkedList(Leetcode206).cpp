/*Given the head of a singly linked list, reverse the list, and return the reversed list.
Example:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

*/

//Iterative approach

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //curr points to the head of the linked list
        //prev is used to point to the head of the linked list that has already been reversed
        //Therefore, initially prev is initialized to 0
        ListNode *curr=head,*prev=NULL,*tmp=NULL;
        //Run the loop till curr is not null
        while(curr){
            //Store the next node's address in tmp so that you don't loose the track of remaining list
            tmp=curr->next;
            //Make curr_next point to prev (Reversing)
            curr->next=prev;
            //Update prev, the new prev would be equal to curr
            prev=curr;
            //Update curr, the new curr would be head of linked list to be reversed
            curr=tmp;
        }

        //Return the head of updated linked list which would be equal to head
        return prev;
    }
};
