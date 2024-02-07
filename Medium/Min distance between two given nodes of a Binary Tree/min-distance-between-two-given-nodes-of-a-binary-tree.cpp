//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
   void fun(unordered_map<Node*,pair<Node*,int>>&m, Node* root,int x)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left)
        {
            m[root->left]={root,x};
            fun(m,root->left,x+1);
        }
        if(root->right)
        {
            m[root->right]={root,x};
            fun(m,root->right,x+1);
        }
    }
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        unordered_map<Node*,pair<Node*,int>> m;
        m[root]={NULL,0};
        fun(m,root,1);
        int ha,hb,hc;
        Node *na,*nb,*nc;
        for(auto it:m)
        {
            if(it.first->data == a)
            {
                ha=it.second.second;
                na=it.first;
            }
            if(it.first->data == b)
            {
                hb=it.second.second;
                nb=it.first;
            }
        }
        unordered_set<Node*> s;
        while(m.find(na)!=m.end())
        {
            s.insert(na);
            na=m[na].first;
        }
        while(m.find(nb)!=m.end())
        {
            if(s.find(nb)!=s.end())
            {
                hc=m[nb].second;
                break;
            }
            else
            {
                nb=m[nb].first;
            }
        }
        return ha-hc+hb-hc;
    }


};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends