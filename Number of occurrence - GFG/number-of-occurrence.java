//{ Driver Code Starts
//Initial Template for Java



import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int x = Integer.parseInt(inputLine[1]);
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().count(arr, n, x);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java



class Solution {
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
    int count(int[] arr, int n, int x) {
        // code here
        int lb= lowerBound(arr,n,x);
	    
	    if(lb==n) return 0;
	    
	    int ub= upperBound(arr,n,x);
	    
	    
	    return ub-lb+1;
    }
}