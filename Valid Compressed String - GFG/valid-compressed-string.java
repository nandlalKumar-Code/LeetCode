//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S = read.readLine();
            String T = read.readLine();

            Solution ob = new Solution();
            System.out.println(ob.checkCompressed(S,T));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    static int checkCompressed(String S, String T) {
        // code here
        int ns=S.length();
        int nt=T.length();
        int num=0;
        
        for(int i=0,j=0;i<nt;i++){
            
            if((T.charAt(i)>='0') && (T.charAt(i)<='9')){
                num=(num*10)+(T.charAt(i)-'0');
                
                //when we encounter last element of T as numeric
                if((i==nt-1) && (num>0)){
                    j+=num;
                    
                    //if j is not ns means some element of S string is left 
                    //or some extra element has been deleted
                    if(j!=ns){
                        return 0;
                    }
                }
                
            }
            //if both string has character at their current place
            else if(num==0){
                if(S.charAt(j)!=T.charAt(i)){
                    return 0;
                }
                j++;
            }
            
            //num is not zero some part we have skip in S string
            else{
                j+=num;
                
                //if j>=ns && i<nt-1 :: j is out index and i has some element to compare
                //second condition :: after skipping the num elements character obtained is not equal
                if(((j>=ns) && (i<nt-1)) || (S.charAt(j)!=T.charAt(i))){
                    return 0;
                }
                
                j++;
                num=0;
            }
            
            
        }
        return 1;
    }
}