//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Driver_class
{
    public static void main(String args[])
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int grid[][] = new int[9][9];
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                grid[i][j] = sc.nextInt();
            }
            
            Solution ob = new Solution();
            
            if(ob.SolveSudoku(grid) == true)
                ob.printGrid(grid);
            else
                System.out.print("NO solution exists");
            System.out.println();
            
        }
    }
}




// } Driver Code Ends


//User function Template for Java

class Solution
{
        static boolean isValid(int[][] board,int row_no,int col_no,int value){
        //moving upward
        for(int r=row_no-1,c=col_no;r>=0;r--){
            if(value==board[r][c]){
                return false;
            }
        }

        //moving down
        for(int r=row_no+1,c=col_no;r<9;r++){
            if(value==board[r][c]){
                return false;
            }
        }

        //moving left
        for(int r=row_no,c=col_no-1;c>=0;c--){
            if(value==board[r][c]){
                return false;
            }
        }

        //moving right
        for(int r=row_no,c=col_no+1;c<9;c++){
            if(value==board[r][c]){
                return false;
            }
        }

        //look into small square formed for dupliacy
        int r=row_no-(row_no%3);
        int c=col_no-(col_no%3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[r+i][c+j]==value){
                    return false;
                }
            }
        }

        return true;
    }
    static boolean isSolved(int[][] board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]==0){

                    for(int k=1;k<=9;k++){
                        int ch=k;
                        if(isValid(board,i,j,ch)){

                            board[i][j]=ch;

                            if(isSolved(board)==true){
                                return true;
                            }
                            
                            board[i][j]=0;
                        }
                    }
                    //it means one box is empty 
                    //no suitable candidate is found
                    return false;
                }
            }
        }

        return true;
    }
    //Function to find a solved Sudoku. 
    static boolean SolveSudoku(int grid[][])
    {
        return isSolved(grid);
    }
    
    //Function to print grids of the Sudoku.
    static void printGrid (int grid[][])
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                System.out.printf("%d ",grid[i][j]);
            }
        }
    }
}