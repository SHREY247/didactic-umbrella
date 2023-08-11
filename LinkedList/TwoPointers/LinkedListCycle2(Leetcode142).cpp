/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following
the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.

Example:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/
/*Complexity
Time: O(N)
Space: O(1)*/

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        int flag = 0;
        while(fast && fast->next){
            slow = slow ->next;
            fast = fast->next->next;
            //If slow and fast pointers ever become equal, cycle surely exists
            if(slow == fast){
                flag = 1;
                break;
            }
        }

        //If flas is 0, no cyce exists return NULL
        if(!flag) return nullptr;


        //slow pointer points to the node where both slow and fast pointers meet
        //Run the loop until slow doesn't become equal to head and jump by 1 node from both the pointers
        //The pointers would meet at first node of the cycle
        while(head != slow){
            head = head->next;
            slow = slow->next; 
        }
        return head;
    }
};
