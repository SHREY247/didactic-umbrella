/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
Intuition
The code uses a fast and slow pointer approach to detect cycles.

Approach
1: Initialize two pointers, slow and fast, both starting from the head of the linked list.
2: In each iteration, move slow one step ahead and fast two steps ahead.
3: If there is a cycle, slow and fast will eventually meet at some point.
4: If at any point slow and fast are equal, return true (indicating the presence of a cycle).
5: If fast reaches the end of the list (fast == nullptr or fast->next == nullptr), return false (indicating no cycle was found).

Complexity
Time complexity:
O(N)

Space complexity:
O(1)

Code
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
        ListNode *slow = head;
        ListNode * fast = head;

         while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
     
            if(slow==fast){
                return true;
            }
        }
        return false;        
        
    }
};


