//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int r,c,row,col,count;
 		r=0,c=0,row=n,col=m,count=0;
 		
 		while(r<row && c<col){
 		    
 		    //visit upper row
 		    for(int i=c;i<col;i++){
 		     //   cout<<a[r][i]<<" ";
 		        count+=1;
 		        if(count==k) return a[r][i];
 		    }
 		    r+=1;
 		    
 		    //visit rightmost col
 		    for(int i=r;i<row;i++){
 		     //   cout<<a[i][col-1]<<" ";
 		        count+=1;
 		        if(count==k) return a[i][col-1];
 		    }
 		    col-=1;
 		    
 		    //visit bottom row 
 		    for(int i=col-1;i>=c;i--){
 		     //   cout<<a[row-1][i]<<" ";
 		        count+=1;
 		        if(count==k) return a[row-1][i];
 		    }
 		    row-=1;
 		    
 		    //visit leftmost col
 		    for(int i=row-1;i>=r;i--){
 		     //   cout<<a[i][c]<<" ";
 		        count+=1;
 		        if(count==k) return a[i][c];
 		    }
 		    c+=1;
 		}
 		
 		return 0;
 		
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends