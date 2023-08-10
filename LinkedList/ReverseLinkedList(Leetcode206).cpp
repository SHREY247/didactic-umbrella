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


//Recursive approach:

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
