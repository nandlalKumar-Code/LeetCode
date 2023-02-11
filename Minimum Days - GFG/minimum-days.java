//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int N;
            N = Integer.parseInt(br.readLine());
            
            
            String S;
            S = br.readLine();
            
            
            int[] P = IntArray.input(br, N);
            
            Solution obj = new Solution();
            int res = obj.getMinimumDays(N, S, P);
            
            out.println(res);
            
        }
        out.close();
    }
}

// } Driver Code Ends


class Solution {
    public static int getMinimumDays(int N, String S, int[] P) {
        // code here
        int match=0;
        char[] arr=S.toCharArray();
        for(int i=0;i<N;i++){
            if(i+1<N && arr[i]==arr[i+1]){
                match++;
            }
        }
        
        if(match==0) return 0;
        
        for(int i=0;i<N;i++){
            int index=P[i];
            
            if(index+1<N && arr[index+1]==arr[index]){
                match--;
            }
            
            if(index-1>=0 && arr[index-1]==arr[index]){
                match--;
            }
            
            arr[index]='?';
            
            if(match==0) return i+1;
        }
        
        return 0;
        
        
        
    }
}
        
