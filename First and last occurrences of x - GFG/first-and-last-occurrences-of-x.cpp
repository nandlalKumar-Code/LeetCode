//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int>v(2,-1);
    
        int l=0,r=n-1;
        
        //first occureence
        while(l<=r){
            int mid=l+(r-l)/2;
          
            if(arr[mid]==x){
                v[0]=mid;
                r=mid-1;
            }
    
            else if(arr[mid]>x){
                r=mid-1;
            }
            
            else{
                l=mid+1;
            }
        }
        
        if(v[0]==-1)
                return v;
        
        l=0;
        r=n-1;
        
        while(l<=r){
            int mid=l+(r-l)/2;
          
            if(arr[mid]==x){
                v[1]=mid;
                l=mid+1;
            }
    
            else if(arr[mid]>x){
                r=mid-1;
            }
            
            else{
                l=mid+1;
            }
        }
       return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends