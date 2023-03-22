//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
  
        
        int t = Integer.parseInt(br.readLine()); 

        while(t > 0){
            
            String input_line1[] = br.readLine().trim().split("\\s+");
            int X = Integer.parseInt(input_line1[0]);
            int Y = Integer.parseInt(input_line1[1]);
            
            String S = br.readLine(); 
            
            Solution ob = new Solution();
		
            System.out.println(ob.solve(X,Y,S)); 

            t--;
        }
    } 
} 
// } Driver Code Ends


//User function Template for Java

class Solution 
{ 
    static long removeFunc(int X,int Y,char ch1,char ch2,String s){
        int cnt1=0,cnt2=0,n=s.length();
        Stack<Character>st1=new Stack<Character>();
        Stack<Character>st2=new Stack<Character>();
        
        //performing for "pr"/"rp" substring
        st1.push(s.charAt(0));
        for(int i=1;i<n;i++){
            if((st1.empty()==false) && (s.charAt(i)==ch2) && (st1.peek()==ch1)){
                cnt1++;
                st1.pop();
            }
            else{
                st1.push(s.charAt(i));
            }
        }
        
        //performing for "rp"/"pr" substring using stack 1
        st2.push(st1.peek());
        st1.pop();
        
        while(st1.empty()==false){
            if((st2.empty()==false) && (st1.peek()==ch2) && (st2.peek()==ch1)){
                cnt2++;
                st2.pop();
            }
            else{
                st2.push(st1.peek());
            }
            st1.pop();
        }
        
        if(ch1=='p'){
            return 1L*X*cnt1+1L*Y*cnt2;
        }
        else{
            return 1L*X*cnt2+1L*Y*cnt1;
        }
    }
    static long solve(int X,int Y, String S)
	{    
	    // code here
	    if(X>Y) return removeFunc(X,Y,'p','r',S);
	    else return removeFunc(X,Y,'r','p',S);
        
	}
}

