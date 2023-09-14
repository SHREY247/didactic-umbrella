/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Complexity
Time complexity:
O(n+m)

Space complexity:
O(1)
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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        //fh and ft represent head and tail of final linked list
        //firstly they point to null
        ListNode *fh=NULL, *ft=NULL;
        if(head1 == NULL) {
            return head2;
        }
        if(head2 == NULL) {
            return head1;
        }
        
         while(head1!=NULL && head2!=NULL){
        if(fh== NULL && ft==NULL){
            if(head1->val>head2->val){
                //Smaller value out of both the values will be pointed firstly by both fh and ft
                fh=head2;
                ft=head2;
                head2=head2->next;
            }
            
            else{
                fh=head1;
                ft=head1;
                head1=head1->next;
            }
        }else{

        /*If value at head1 is lesser, final tail would now point to head1,i.e., we added head1 value in final linked list*/    
        if(head1->val < head2->val){
            ft->next=head1;
            ft=ft->next;
            head1=head1->next;

        
        /*If value at head2 is lesser, final tail would now point to head2,i.e., we added head2 value in final linked list*/     
        }else {
            ft->next=head2;
            ft=ft->next;
            head2=head2->next;
        }   
        }
        
    }
    
    //while breaks when any of the lists starts pointing to NULL
    //If list1 not fully traversed, adding remaining elements into final list
    if(head1!=NULL){
        ft->next=head1;
    }

    //If list2 not fully traversed
    if(head2!=NULL){
        ft->next=head2;
    }
    
    return fh;
    }
};


