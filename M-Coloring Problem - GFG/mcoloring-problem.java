//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int tc = scan.nextInt();

        while (tc-- > 0) {
            int N = scan.nextInt();
            int M = scan.nextInt();
            int E = scan.nextInt();

            boolean graph[][] = new boolean[N][N];

            for (int i = 0; i < E; i++) {
                int u = scan.nextInt() - 1;
                int v = scan.nextInt() - 1;
                graph[u][v] = true;
                graph[v][u] = true;
            }

            System.out.println(new solve().graphColoring(graph, M, N) ? 1 : 0);
        }
    }
}

// } Driver Code Ends


class solve {
    // Function to determine if graph can be coloured with at most M colours
    // such
    // that no two adjacent vertices of graph are coloured with same colour.
    public boolean graphColoring(boolean graph[][], int m, int n) {
        // Your code here
        int[] color=new int[n];
        return recursive_approach(0,graph,color,m,n);
    }
    
    private boolean isSafe(int node,int c,boolean[][] graph,int[] color){
        int n=graph.length;
        
        for(int i=0;i<n;i++){
            if(graph[node][i]==true && color[i]==c) return false;
        }
        
        return true;
    }
    
    private boolean recursive_approach(int node,boolean[][] graph,int[] color,int m,int n){
        if(node==n){
            return true;
        }
        for(int c=1;c<=m;c++){
            if(isSafe(node,c,graph,color)==true){
                color[node]=c;
                if(recursive_approach(node+1,graph,color,m,n)==true){
                    return true;
                }
                color[node]=0;
            }
        }
        
        return false;
    }
}