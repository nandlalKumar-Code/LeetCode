//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            String s; 
            s = br.readLine();
            
            Solution obj = new Solution();
            String res = obj.removePair(s);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static String removePair(String s) {
        Stack<Character>st=new Stack<>();
        for(int i=0;i<s.length();i++){
            if((st.empty()==false) && (st.peek()==s.charAt(i))){
                st.pop();
            }
            else{
                st.push(s.charAt(i));
            }
        }
        
        StringBuffer sb=new StringBuffer();
        while(st.empty()==false){
            sb.append(st.peek());
            st.pop();
        }
        sb.reverse();
        String str= new String(sb.toString());
        
        if(str.length()==0){
            return new String("-1");
        }
        else{
            return str;
        }
        
    }
}
        
