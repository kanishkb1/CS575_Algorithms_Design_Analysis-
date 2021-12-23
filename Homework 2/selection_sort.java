/*	Name: Kanishk Barhanpurkar
	B-Number: B00863529
	Email-ID: kbarhan1@binghamton.edu

	Problem: Selection sort+ Selection sort with k elements+ Calculate median
*/

import java.util.Scanner;
import java.util.*;
import java.io.*;	
	
	public class Selectionsort {
	/*Function for selection sort*/
	    public static void SelectionSort(int ar1[],int array)
	    {
	    float median;
	    int temp;
	        for(int i=0;i<array-1;i++)
	        {
	            int x1=i;
	            for(int j=i+1;j<array;j++)
	            {
	                if(ar1[j]<ar1[x1])
	                    
	                {
	                    temp=ar1[x1];
	                    ar1[x1]=ar1[j];
	                    ar1[j]=temp; 
	                }
	            }
	        }
	        Scanner sc=new Scanner(System.in);
	        System.out.println("Sorted elements:");
	        for(int i=0;i<array;i++)
	        {
	            System.out.println(ar1[i]);
	            
	        }
	        //Smallest number (k)
	        System.out.println("Enter k");
	        int k=sc.nextInt();
	        
	        //code for printing the k elements
	        System.out.println("First k elements are:");
	        for(int i=0;i<k;i++)
	        {
	            System.out.println(ar1[i]); 
	        }
	        
	        
	        //Calculation of median for odd and even classes
	        int y1[]=new int[k];
	        for( int i=0;i<k;i++)
	        {
	            y1[i]=ar1[i];
	            
	        }
	        if(k%2==0)
	        {
	            median = (float) ((y1[k/2] + y1[(k/2) - 1])/2.0);
	        }
	        else
	        {
	              median =  y1[k/2];
	              
	        }
	        System.out.println("Median is:" +median);
	        
	}
	public static void main(String[] args) 
	{
	        System.out.println("Number of elements");
	        Scanner sc=new Scanner(System.in);
	        int array=sc.nextInt();
	        int ar1[]=new int[array];
	        System.out.println("Enter the elements");
	        for(int i=0;i<array;i++)
	        {
	           ar1[i]=sc.nextInt();
	        }
	        SelectionSort(ar1, array); 
	        
	    }
	}
