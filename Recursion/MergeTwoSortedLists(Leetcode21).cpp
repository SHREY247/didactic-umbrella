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
        //When both lists point to NULL, return NULL
        if(!list1 && ! list2) return nullptr;
        //If list1 points to NULL, return list2
        if(!list1) return list2;
        //If list2 points to NULL, return list1
        if(!list2) return list1;
        ListNode* head;

        //If value at head of list1 is lesser, that would be the head of sorted list
        if(list1->val < list2->val){
            head = list1;
            //Update list1
            list1 = list1->next;
        }
        //If value at list2 is lesser, update head accordingly
        else{
            head = list2;
            list2= list2->next;
        }

        //Recursive call to remaining list
        head->next = mergeTwoLists(list1 , list2);
        return head;
    }
};
