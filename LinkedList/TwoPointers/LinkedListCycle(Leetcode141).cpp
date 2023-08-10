/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //2 pointers slow and fast, initially pointing to the head node
        //slow is incremented by 1 unit and fast is incremented by 2 units
        ListNode *slow = head;
        ListNode * fast = head;

        //Run the loop until fast or fast->next points to NULL
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            //If slow and fast pointer point to the same node, a cycle would surely be there, hence return true
            if(slow==fast){
                return true;
            }
        }
        return false;        
    }
};
