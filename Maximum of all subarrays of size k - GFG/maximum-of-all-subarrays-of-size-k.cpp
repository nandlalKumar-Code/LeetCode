//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        // int ptr1=0,ptr2=0;
        // priority_queue<pair<int,int>>maxHeap;
        // vector<int>ans;
        
        // while(ptr2<n){
        //     if(ptr2-ptr1+1==k){
        //         maxHeap.push({arr[ptr2],ptr2});
        //         while(maxHeap.top().second<ptr1){
        //             maxHeap.pop();
        //         }
        //         ans.push_back(maxHeap.top().first);
                
        //         ptr1++; 
        //     }
        //     else{
        //         maxHeap.push({arr[ptr2],ptr2});
        //     }
        //     ptr2++;
        // }
        // return ans;
        
        //idea of using deque is to maintain largest elements in the front
        //ans smallest element at the end of deque
        deque<int>dq;
        int ptr1=0;
        
        //pushing k elements into the deque
        while(ptr1<k){
            while((!dq.empty()) && (arr[ptr1]>=arr[dq.back()])){
                dq.pop_back();
            }
            dq.push_back(ptr1);
            ptr1++;
        }
        
        vector<int>ans;
        
        while(ptr1<=n){
            ans.push_back(arr[dq.front()]);
            
            if(ptr1==n) break;
            
            while((!dq.empty()) && (dq.front() <= ptr1-k)){ //equal sign as indexing starts from zero
                dq.pop_front();
            }
            
            
            
            while((!dq.empty()) && (arr[ptr1]>=arr[dq.back()])){
                dq.pop_back();
            }
            
            dq.push_back(ptr1);
            ptr1++;
        }
        
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends