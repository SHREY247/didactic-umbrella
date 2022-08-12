/*An XOR linked list is a more memory efficient doubly linked list. 
Instead of each node holding next and prev fields, it holds a field named both, 
which is an XOR of the next node and the previous node. Implement an XOR linked list; 
it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.*/

#include<bits/stdc++.h>
using namespace std;
class Node{
	public: int data;
	Node* xnode;
};

Node* Xor(Node* x, Node* y)
{
    return reinterpret_cast<Node*>(
        reinterpret_cast<uintptr_t>(x)
        ^ reinterpret_cast<uintptr_t>(y));
}

//Insert a node at start of XORed linked list
//Mark the newly inserted node as head

void insert(Node** head_ref, int data)
{	
	//Allocate memory for new node
	Node* new_node = new Node();
	new_node -> data = data;
	
	// Since new node is inserted at the
    // start , xnode of new node will always be
    // Xor of current head and NULL
    
     new_node -> xnode = *head_ref;
     // If linkedlist is not empty, then xnode of
    // present head node will be Xor of new node
    // and node next to current head 
    
    if (*head_ref != NULL) {
        // (head_ref)->xnode is Xor of (NULL and next).
        // If we Xor Null with next we get next
        (*head_ref) -> xnode = Xor(new_node, (*head_ref) -> xnode);
        
    }
    
    // Change head
    *head_ref = new_node;
}

// It simply prints contents of doubly linked
// list in forward direction
void printList(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
 
    cout << "The nodes of Linked List are: \n";
 
    // Till condition holds true
    while (curr != NULL) {
        // print current node
        cout << curr -> data << " ";
 
        // get address of next node: curr->xnode is
        // next^prev, so curr->xnode^prev will be
        // next^prev^prev which is next
        next = Xor(prev, curr -> xnode);
 
        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
}

int main()
{
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 100);
    insert(&head, 1000);
    insert(&head, 10000);
 
    // Printing the created list
    printList(head);
 
    return (0);
}
	

