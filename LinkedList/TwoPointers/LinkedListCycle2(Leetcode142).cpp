/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following
the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.

Example:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/
# Approach
1: Let the length of linear part of linked list be l1
2: Let the part of cycle part of linked list be l2
3: Let the distance between first node of the cycle and the node where slow and fast pointer become equal be x
4: Using the fact, distance travelled by fast pointer = 2* dist travelled by slow pointer
5: l1 + (a)l2 + x = 2* (l1 + b.l2 + d)
6: On solving the equation we get, l1+x is a multiple of l2
7: This means (l1 + x) % l2 ==0
8: The point where this condition is getting satisfied is the first node of the cycle, because at the time head reaches first node of the cycle it would have taken l1 steps and also the pointer at the meeting point is also moving at same speed so, it would also have taken l1 steps. From the 7th point we know that, (l1+x) is a multiple of l2, and slow pointer starts from x, therefore they would meet at the first node only where (l1 + x) would be surely divisible by l2.
They can't meet before because head can't enter the cycle before taking l1 steps.
    
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
