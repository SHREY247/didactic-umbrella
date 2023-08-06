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
        //Use 2 pointers, slow and fast
        //Initially, slow pointer as well as fast pointer point to head
        //slow pointer hops by just 1 unit while fast pointer hops by 2 units (or nodes)
        //So, when fast pointer would reach the end, slow would be at the mid


        ListNode* slow = head;
        ListNode* fast = head;
        //We are checking for two conditions
        //One, when the number of nodes are odd: In this case termination condition would be: fast->next==NULL 
        //Second, in case of even number of nodes, the termination condition would be fast ==NULL

        //So run the while loop only when fast!= NULL && fast->next!=NULL
        //In this way, we'll handle both the cases in a single loop
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
