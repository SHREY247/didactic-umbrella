/*Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
Example:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.*/

/*Complexity
Time: O(N)
Space: O(1)

Approach
1: Maintain 2 pointers, slow and fast, both initially pointing to head
2: The slow pointer is incremented by 1 and fast one is incremented by 2 until fast and fast-> next are not null
3: When fast pointer reaches null, slow pointer will be pointing to middle element
4: Return slow*/

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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
