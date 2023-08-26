//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GfG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            int k = sc.nextInt();
            Solution obj = new Solution();
            System.out.println(obj.longestkSubstr(s, k));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int longestkSubstr(String s, int k) {
        // code here
        int[] ch = new int[26];
        
        int fix,movable,sz,count;
        fix=0;
        movable=0;
        sz=-1;
        count=0;
        
        for(;movable<s.length();movable++){
            
            int idx= (int) (s.charAt(movable)-'a');
            ch[idx]++;
            
            count= ch[idx]==1?count+1:count;
            
            //taking unique characters upto current index gets greater then
            while(count>k){
                idx= s.charAt(fix)-'a';
                ch[idx]--;
                
                if(ch[idx]==0){
                    count--;
                }
                
                fix++;
            }
            
            
            if(count==k){
                sz= Math.max(sz,movable-fix+1);

            }   
        }
        
        return sz;
    }
}