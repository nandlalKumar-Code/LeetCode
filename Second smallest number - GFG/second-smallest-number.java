//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String[] inp=read.readLine().split(" ");
            int S=Integer.parseInt(inp[0]);
            int D=Integer.parseInt(inp[1]);

            Solution ob = new Solution();
            System.out.println(ob.secondSmallest(S,D));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static String secondSmallest(int S, int D){
        // code here
        int[] arr=new int[D];
        for(int i=D-1;i>0;i--){
            int temp=Math.min(9,S-1);
            arr[i]=temp;
            S-=temp;
        }
        if(S>9){
            return "-1";
        }
        arr[0]=S;
        
        for(int i=D-1;i>0;i--){
            if((arr[i]!=0) && (arr[i-1]!=9)){
                arr[i]-=1;
                arr[i-1]+=1;
                
                StringBuilder str=new StringBuilder();
                for(int j=0;j<D;j++){
                    str.append(arr[j]);
                }
                return str.toString();
            }
        }
        return "-1";
    }
}
