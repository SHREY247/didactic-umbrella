/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
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
    //Function to get middle element using slow and fast pointers
    ListNode * getMid(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
;    }
    
    //Function to reverse the linked list
    ListNode* reverse(ListNode* p){
        if(!p || !p->next){
            return p;
        }
        ListNode* temp = p->next;
        ListNode* head = reverse(temp);
        p->next = nullptr;
        temp->next = p;
        return head;
    }

    
    bool isPalindrome(ListNode* head) {
        //Fetch the middle element of the linked list
        ListNode * mid = getMid(head);
        //Reverse second half of the linked list starting from the middle element
        ListNode * t = reverse(mid);
        ListNode * h = head;

        //Run a loop until h and t are not pointing to NULL
        while(h && t){
            if(h->val!=t->val){
                return false;
            }

            //Update h and t
            h = h->next;
            t = t->next;
        }

        return true;                
    }
};
