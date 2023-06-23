//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
Node* find_mid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge_list(Node* p1, Node* p2) {
    if (p1 == NULL || p2 == NULL) {
        return ((p1 == NULL) ? p2 : p1);
    }
    Node* ans = new Node(0);
    Node* curr = ans;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            curr->next = p1;
            p1 = p1->next;
        } else {
            curr->next = p2;
            p2 = p2->next;
        }
        curr = curr->next;
    }
    if (p1 != NULL || p2 != NULL) {
        curr->next = (p1 == NULL) ? p2 : p1;
    }
    return ans->next;
}

void sort(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    Node* mid = find_mid(*head);
    Node* newhead = mid->next;
    mid->next = NULL;
    Node* first_half = *head;
    Node* second_half = newhead;
    sort(&first_half);
    sort(&second_half);
    *head = merge_list(first_half, second_half);
}
