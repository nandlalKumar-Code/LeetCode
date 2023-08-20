//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:
    //TC--> O(logN)
    int lowerBound(int arr[],int n,int x){
        int l,r,m;
        l=0;
        r=n-1;
        
        while(l<r){
            m = l+((r-l)>>1);
            
            if(arr[m]<x){
                l=m+1;
            }
            else{
                r=m;
            }
            
        }
        if(l==r && arr[l]!=x){
            return n;
        }
        return l;
        
    }
    
    //TC --> O(logN)
    int upperBound(int arr[],int n,int x){
        int l,r,m;
        
        l=0;
        r=n-1;
        
        while(l<r){
            m = l+((r-l)>>1)+1;
            
            if(arr[m]>x){
                r=m-1;
            }
            else{
                l=m;
            }
        }
        
        return l;
    }
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    //find the first occurrence of X
	    //find the last occurrence of X
	    
	    int lb= lowerBound(arr,n,x);
	    
	    if(lb==n) return 0;
	    
	    int ub= upperBound(arr,n,x);
	    
	    
	    return ub-lb+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends