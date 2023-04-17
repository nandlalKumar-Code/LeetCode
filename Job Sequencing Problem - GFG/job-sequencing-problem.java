//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Job {
    int id, profit, deadline;
    Job(int x, int y, int z){
        this.id = x;
        this.deadline = y;
        this.profit = z; 
    }
}

class GfG {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        //testcases
		int t = Integer.parseInt(br.readLine().trim());
		while(t-->0){
            String inputLine[] = br.readLine().trim().split(" ");
            
            //size of array
            int n = Integer.parseInt(inputLine[0]);
            Job[] arr = new Job[n];
            inputLine = br.readLine().trim().split(" ");
            
            //adding id, deadline, profit
            for(int i=0, k=0; i<n; i++){
                arr[i] = new Job(Integer.parseInt(inputLine[k++]), Integer.parseInt(inputLine[k++]), Integer.parseInt(inputLine[k++]));
            }
            
            Solution ob = new Solution();
            
            //function call
            int[] res = ob.JobScheduling(arr, n);
            System.out.println (res[0] + " " + res[1]);
        }
    }
}
// } Driver Code Ends

class CustomComp implements Comparator<Integer[]>{
    public int compare(Integer[] x,Integer[] y){
        return y[0]-x[0];
    }
}
class Solution
{
    //Function to find the maximum profit and the number of jobs done.
    int[] JobScheduling(Job arr[], int n)
    {
        // Your code here
        int maxi=0;
        PriorityQueue<Integer[]>maxHeap=new PriorityQueue<Integer[]>(new CustomComp());
        for(int i=0;i<n;i++){
            maxHeap.offer(new Integer[]{arr[i].profit,arr[i].deadline});
            maxi=Math.max(maxi,arr[i].deadline);
        }
        
        int[] visited=new int[n];
        int count=0;
        int totalProfit=0;
        while((maxHeap.isEmpty()==false) && (count<n)){
            int profit=maxHeap.peek()[0];
            int deadline=maxHeap.peek()[1]-1;
            maxHeap.poll();
            
            while(deadline>=0 && visited[deadline]==1){
                deadline--;
            }
            
            if(deadline>=0){
                count++;
                visited[deadline]=1;
                totalProfit+=profit;
            }  
        }
        
        return new int[]{count,totalProfit};
    }
}