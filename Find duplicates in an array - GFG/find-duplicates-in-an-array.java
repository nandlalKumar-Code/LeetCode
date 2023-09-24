//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.Map.Entry;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            Solution g = new Solution();
            ArrayList<Integer> ans = g.duplicates(a, n);
            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    public static ArrayList<Integer> duplicates(int arr[], int n) {
        // code here
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            int index = arr[i]%n; //As Index change by adding n, so Modulo is required
            arr[index] += n; //Add n to their respective index
        }
        
        //for e.g [2, 3, 1, 2, 3], n=5
        // For i=0, [2, 3, 1+5, 2, 3] = [2, 3, 6, 2, 3]
        //for i=1, [2, 3, 6, 2+5, 3] = [2, 3, 6, 7, 3]
        //for i=2, index = 6%5 = 1, arr[1]+n , [2, 3+5, 6, 7, 3] = [2, 8, 6, 7, 3]
        //for i=3, index = 7%5 = 2, arr[2]+n, [2, 8, 6+5, 7, 3] = [2, 8, 11, 7, 3]
        //for i=4, index = 3%5 = 3, arr[3]+n, [2, 8, 11, 7+5, 3] = [2, 8, 11, 12, 3]
        
        //Modified array after first loop is [2, 8, 11, 12, 3]
        
        
        for(int i=0; i<n; i++){
            // System.out.println("arr["+i+"]="+arr[i]+" n="+n+" :: "+arr[i]/n);
            if(arr[i]/n >=2)
                ans.add(i);  //Add index where arr[i]/2 >= 2 (Means it add n two or more times) 
        }
        
    
        //If ans is empty then add -1
        if(ans.isEmpty())
            ans.add(-1);
        
        return ans;
    }
}
