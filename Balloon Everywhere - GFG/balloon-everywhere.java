//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

// Position this line where user code will be pasted.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String s = br.readLine().trim();
            Solution ob = new Solution();
            int ans = ob.maxInstance(s);
            out.println(ans);
        }
        out.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int maxInstance(String s) {
        // Code here
        Map<Character,Integer>mp=new HashMap<Character,Integer>();
        
        for(int i=0;i<s.length();i++){
            char x=s.charAt(i);
            if((x=='a' )|| x=='b' || x=='l' || x=='o' || x=='n'){
                if(mp.containsKey(x)==true){
                    mp.put(x,mp.get(x)+1);
                }
                else{
                    mp.put(x,1);
                }
            }
            
        }
        
        if((mp.size()!=5)|| (mp.get('l')/2==0) || (mp.get('o')/2==0)){
            return 0;
        }
        
        int mini=Integer.MAX_VALUE;
        for(Map.Entry<Character,Integer> entry:mp.entrySet()){
            if(entry.getKey()=='l' || entry.getKey()=='o') continue;
            
            mini=Math.min(entry.getValue(),mini);
        }
        
        return Math.min(mini,Math.min(mp.get('l')/2,mp.get('o')/2));
        
        
    }
}