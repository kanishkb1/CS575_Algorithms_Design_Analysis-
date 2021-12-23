import java.util.*;
import java.util.Scanner;
import java.io.*;

public class change_part_b{

  public static void main(String args[]){
            int c;
            int k;
            int i;
            int temp;
            int amount;
            int result =1;
            
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the amount:");
            amount = sc.nextInt();

            System.out.println("Enter c:");
            c= sc.nextInt();
            
            if(c<=1) 
            {
            System.out.println("Invalid value of c");
            }

            System.out.println("Enter k");
            k=sc.nextInt();
            
            if(k<1)
            {
            System.out.println("Invalid value of k");
            }

            for (i=1;i<=k;k++)
            {
            result *= c;
            }
            
            System.out.println("Output:\n");
                 for(i=result;i>=1;i=i/c){ 
                    if(amount>=i){
                    temp = amount / i;
                    
                    System.out.println(temp+" Coin of "+i+" denomination ");
                    amount = amount % i;
                }
              }  
}

}