//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node*reverse(Node*head)
    {
        Node*newhead=NULL;
        while(head!=NULL)
        {
            Node*curr=head->next;
            head->next=newhead;
            newhead=head;
            head=curr;
        }
        return newhead;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* new_head = reverse(head);
        Node* current = new_head, *prev = NULL, *current1 = new_head;
        
        int carry = 0;
        while(current != NULL){
            int sum = 0;
            if(prev == NULL){
                sum = current->data + 1;
            }else{
                sum = current->data + carry;
            }
            
            carry = sum/10;
            current->data = sum%10;
            prev = current;
            current = current->next;
            
        }
        
        if(carry == 1){
            Node* new_node = new Node(1);
            prev->next = new_node;
        }
        return reverse(current1);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends