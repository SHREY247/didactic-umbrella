/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //If list1 points to null return list2
        if(!list1) return list2;
        //If list2 points to NULL return list1
        if(!list2) return list1;

        //head points to the effective head which would be the smaller of the two heads
        ListNode* head;
        //tail points to the tail of the sorted list
        ListNode* tail;
        //p1 and p2 point to the heads of the two linked lists
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        //If value at p1 is less than value at p2, the sorted list would start from p1, so make head point and tail point to p1
        if(p1->val < p2->val){
            head = p1;
            tail = p1;
            //Update the p1 
            p1 = p1->next;
        }
        //Similarly, handle the case if value at p2 is lesser
        else{
            head = p2;
            tail = p2;
            p2 = p2->next;
        }

        //Run a loop until any of p1 or p2 is not NULL
        while(p1 && p2){
            //If value at p1 is lesser, the next of tail would be p1
            if(p1->val < p2->val){
                tail->next = p1;
                //Update p1
                p1 = p1->next;
            }

            else{
                //If value at p2 is lesser, update next of tail accordingly
                tail->next = p2;
                //Update p2
                p2 = p2->next;
            }
            //Update the tail for either of the cases
            tail = tail->next;
        }

        //Now, if p1 is not exhausted yet, insert the elements of list1 in the sorted linked list
        if(p1) tail->next = p1;
        //If p2 is not exhausted yet, insert the elements of list2 in the sorted linked list
        if(p2) tail->next = p2;

        //Return the effective linked list starting from head
        return head;
    }
};
