//{ Driver Code Starts
//Initial Template for Java
import java.util.*;
import java.io.*;
class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());
            Solution ob = new Solution();

            System.out.println(ob.nthFibonacci(n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

//User function Template for Java
class Solution {
    static int nthFibonacci(int n){
        // code here
        int a,b,mod;
        a=0;
        b=1;
        mod=1000000007;
        
        if(n==0) return n;
        
        for(int i=2;i<=n;i++){
            int c=((a%mod)+(b%mod))%mod;
            a=b;
            b=c;
        }
        return b;
    }
}