//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void recursive_appraoach(int index,int n,int arr[],int k,int runningSum,int maxSum,int &ans){
    
    	if(k==1){
    		maxSum=max(runningSum,maxSum);
    		runningSum=0;
    		for(int i=index;i<n;i++){
    			runningSum+=arr[i];
    		}
    
    		maxSum=max(maxSum,runningSum);
    		ans=min(ans,maxSum);
    	}
    
    	runningSum=0;
    	for(int i=index;i<n;i++){
    		runningSum+=arr[i];
    		maxSum=max(maxSum,runningSum);
    		recursive_appraoach(i+1,n,arr,k-1,runningSum,maxSum,ans);
    	}
    
    	return;
	
    }
    bool checkSub(int arr[],int n,int m,int k){
    	int runningSum=0;
    	int count=1;
    	for(int i=0;i<n;i++){
            if(arr[i]>m) return false;
    		runningSum+=arr[i];
    		if(runningSum>m){
    			count++;
    			runningSum=arr[i];
    		}
    	}
    	if (count <= k)
            return true;
        return false;	
    }

    int binarySearch_approach(int arr[],int n,int k){
    	int sum=0;
    	int maxi=INT_MIN;
    
    	for(int i=0;i<n;i++){
    		sum+=arr[i];
    		maxi=max(maxi,arr[i]);
    	}
    
    	int l=maxi,h=sum,m;
    
    	if(n==k){
    		return l;
    	}
    	if(k==1){
    		return h;
    	}
    
        int ans=0;
    	while(l<=h){
    		m=l+((h-l)>>1);
           
    		bool flage=checkSub(arr,n,m,k);
    	
    		if(flage==true){
    			ans=m;
    			h=m-1;
    		}
    		else{
    			l=m+1;
    		}
    	}
    	return ans;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        //     int ans=INT_MAX;
        // 	recursive_appraoach(0,N,arr,K,0,0,ans);
    
        int ans2=binarySearch_approach(arr,N,K);
        //     int sum=0;
        // 	string str="";
        // 	for(int i=0;i<n;i++){
        // 		sum+=arr[i];
        // 		if(sum>ans2){
        // 			sum=arr[i];
        // 			str+="/ ";
        // 		}
        // 		str+=to_string(arr[i])+" ";
        // 	}	
        // 	return str;
    
    	return ans2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends