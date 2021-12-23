//Problem 2: 0-1 Knapsack Problem (Homework-4)
//Name: Kanishk Barhanpurkar
//B-Number: B00863529


import java.util.*;
import java.util.Scanner;
import java.io.*;

  public class Knapsack{
	  public static void main(String[] args) {
       //variable initialization
       int n;
       int capacity;
       int items[];
       int weight[];
       int value[];
       int table[][];
       int temp;
     
       Scanner input = new Scanner(System.in);
       //inputting values for number of items, capacity of knapsack, weights and values 		
       System.out.println("\nEnter number of items");
       n = input.nextInt();

       System.out.println("\nEnter capacity of knapsacks");
       capacity = input.nextInt();
   
       items = new int[n];
       weight= new int[n+1];
       value= new int[n+1];
     
       System.out.println("\nEnter the weights");
       for (int i = 1; i <= n; i++)
        {
          weight[i] = input.nextInt();
        }
			
      System.out.println("\nEnter the value");
       for (int i = 1; i <= n; i++)
        {
          value[i] = input.nextInt();
        }
		
    // Build table K[][] in bottom up manner	
    // either the result comes from the top
    // (K[i-1][w]) or from (val[i-1] + K[i-1]
   // [w-wt[i-1]]) as in Knapsack table. 
   // If it comes from the latter one/ it means the item is included.

		table= new int[n+1][capacity+1];

		System.out.println("Expected Table for the Knapsack 0/1\n");
		for(int i = 1; i <=n ; i++){
			for(int j=0; j<= capacity; j++){
				if(i == 1){
					if(j >= weight[i]){
						table[i][j] = value[i];
					}
				}
				else
          {
					  table[i][j] = table[i - 1][j];
					    if( j >= weight[i])
                {
						    temp = j - weight[i];
						      table[i][j] = find_max(table[i - 1][temp] + value[i], table[i][j]);
					}
				}				
			}
		}
   //printing the Knapsack 0/1 table in form of table
    for (int i = 1; i <= n ; i++)
	    {
	       for (int j = 0; j <= capacity; j++)
            {
			          System.out.print(table[i][j] + "  ");
		        }
         System.out.println("\n");
     }
	  }
     
  //finding the maximum value for x and y
	static int find_max(int x, int y)  
	  { 
     int max;
     if (x >= y)
	   	  max = x;
     else
  	  	max = y;
	    return max;
	  } 	  
}