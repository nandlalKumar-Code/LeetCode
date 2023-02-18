//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String input[] = read.readLine().trim().split("\\s+");
            int N = Integer.parseInt(input[0]);
            int M = Integer.parseInt(input[1]);
            String arr = read.readLine().trim();

            Solution ob = new Solution();
            out.println(ob.appleSequence(N, M, arr));
        }
        out.close();
    }
}


// } Driver Code Ends
//User function Template for Java


class Solution{
    public static int appleSequence(int n, int m, String arr){
        //code here
        int cur,prev,count=m,maxi=0;
        cur=0;
        prev=0;
        
        while(cur<n){
            
            if(arr.charAt(cur)!='A'){
                count--;
                if(count<0){
                    while(arr.charAt(prev)!='O'){
                        prev++;
                    }
                    prev+=1;
                    count++;
               
                }
            }
            
            maxi=Math.max(cur-prev+1,maxi);
            cur++;
        }
        
        return maxi;
    }
}


//{ Driver Code Starts.

// } Driver Code Ends