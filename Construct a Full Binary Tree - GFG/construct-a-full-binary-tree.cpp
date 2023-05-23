//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  private:
    Node* dfs(int arr1[],int arr2[],int s1,int e1,int s2,int e2){
        
        Node* node= new Node(arr1[s1]);
        int m1,m2,c1,c2;
        
        if(s1+1>e1){
            return node;
        }
        
        c1=s1+1;
        c2=s2+1;
        
        for(;c1<=e1;c1++){
            if(arr2[s2+1]==arr1[c1]){
                break;
            }
        }
        for(;c2<=e2;c2++){
            if(arr1[s1+1]==arr2[c2]){
                break;
            }
        }
        
        node->left= dfs(arr1,arr2,s1+1,c1-1,c2,e2);
        node->right = dfs(arr1,arr2,c1,e1,s2+1,c2-1);
        
        return node;
    }
  public:
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        return dfs(pre,preMirror,0,size-1,0,size-1);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends