//{ Driver Code Starts
import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        
        //taking input using Scanner class
        Scanner sc = new Scanner(System.in);
        
        //taking total testcases
        int t = sc.nextInt();
        while(t > 0){
            
            //taking size of array
            int n = sc.nextInt();
            int array[] = new int[n];
            
            //inserting elements in the array
            for (int i = 0; i < n; ++i)
            {
                array[i] = sc.nextInt();
            }
            
            //creating an object of class Solution
            Solution ob = new Solution();
            
            //calling longestSubsequence() method of class
            //Solution
            System.out.println(ob.longestSubsequence(n,array));
            t--;
        }
    } 
} 
// } Driver Code Ends

//DP SOLUTION ---> TC=O(N*N) AND SC=O(N*N)
class MySolution_LIS{
    private int recursive_approach(int curIdx,int prevIdx,int[] arr){
        int n=arr.length;
        
        //Base Case
        if(curIdx==n){
            return 0;
        }
        
        int take,notTake;
        take=0;
        notTake=0;
        
        //select the current Idx if codition satifies
        if(prevIdx==-1 || arr[prevIdx]<arr[curIdx]){
            take= 1+recursive_approach(curIdx+1,curIdx,arr);
        }
        
        //Don't select the current Idx and proceed 
        notTake = recursive_approach(curIdx+1,prevIdx,arr);
        
        
        return Math.max(take,notTake);
    }
    
    private int memoization_approach(int curIdx,int prevIdx,int[] arr,int[][] t){
        int n=arr.length;
        
        //Base case
        if(curIdx==n){
            return 0;
        }
        
        //Already Processed
        if(prevIdx!=-1 && t[curIdx][prevIdx+1]!=-1){
            return t[curIdx][prevIdx+1];
        }
        
        int take,notTake;
        take=0;
        notTake=0;
        
        //select the current Index if codition satifies
        if(prevIdx==-1 || arr[prevIdx]<arr[curIdx]){
            take= 1+memoization_approach(curIdx+1,curIdx,arr,t);
        }
        
        //Don't select the current Index and proceed 
        notTake = memoization_approach(curIdx+1,prevIdx,arr,t);
        
        
        //storing the processed value
        t[curIdx][prevIdx+1]=Math.max(take,notTake);
        
        return t[curIdx][prevIdx+1];
    }
    
    //ACCEPTABLE SOLUTION - TC=O(N*LOGN)
    //DP+Binary Search
    private int binary_search(int[] arr,int target,int h){
        int l,m;
        
        l=0;
        // System.out.print("h="+h+" ");
        while(l<h){
            m = l+((h-l)>>1);
            
            if(arr[m]>=target){
                h=m;
            }
            else{
                l=m+1;
            }
            
        }
        
        // System.out.println("l="+l);
        
        return l;
    }
    private int LIS_BS(int[] arr){
        int n,Idx;
        n=arr.length;
        Idx=0;
        int[] t=new int[n];
        
        for(int i=0;i<n;i++){
            
            int index= binary_search(t,arr[i],Idx);
            
            
            if(index<Idx){
                t[index]=arr[i];
            }
            else{
                t[Idx]=arr[i];
                Idx++;
                // t[Idx]=arr[i];
            }
            
            // System.out.println("\tindex="+index+ " Idx="+Idx);
        }
        
        return Idx;
    }
    
    
    public int LIS(int[] arr){
        // return recursive_approach(0,-1,arr);
        
        // int n= arr.length;
        // int[][] t= new int[n][n+1];
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n+1;j++){
        //         t[i][j]=-1;
        //     }
        // }
        
        // return memoization_approach(0,-1,arr,t);
        
        return LIS_BS(arr);
        
        
    }
}





class Solution 
{
    
    //Function to find length of longest increasing subsequence.
    static int longestSubsequence(int size, int a[])
    {
        // code here
        MySolution_LIS sol = new MySolution_LIS();
        return sol.LIS(a);
    }
} 