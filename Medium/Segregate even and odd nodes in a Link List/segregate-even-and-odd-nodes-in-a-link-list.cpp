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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
         Node *oddh=NULL, *evenh=NULL, *oddt=NULL, *event=NULL;
        while(head!=NULL){
            if(head->data%2==0){
                if(evenh==NULL){
                    evenh=head;
                    event=head;
                    head=head->next;
                }else{
                    event->next=head;
                    event=event->next;
                    head=head->next;
                }
            }else{
                if(oddh==NULL){
                    oddh=oddt=head;
                    head=head->next;
                }else{
                    oddt->next=head;
                    oddt=oddt->next;
                    head=head->next;
                }
            }
        }
        
        if(oddh==NULL){
            return evenh;
        }
        
        if(evenh==NULL){
            return oddh;
        }
        oddt->next=NULL;
        event->next=oddh;
        // event->next=NULL;
        // oddt->next=evenh;
        
        return evenh;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends