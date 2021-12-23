import java.io.*;
import java.util.Scanner;
import java.util.*;

public class change_part_a
        {

	public static void main(String args[])
            {
              //variable declaration
              int q; //quarters
              int n; //nickels
              int d; //dimes
              int amount; 
              Scanner sc=new Scanner(System.in);
              System.out.println("Enter the value amount");
              amount = sc.nextInt();
              
              do{    
                    //Check for number of pennies
                    if (amount<5)
                        {
                            System.out.println("Number of pennies:"+amount);
                            amount=0;
                        }
                    //Condition for number of nickels
                    else if (amount>=5 && amount <10)
                        {
                            n = amount/5;
                            System.out.println("Number of nickels"+n);
                            amount = amount % 5;
                        }
                    //Condition for number of quarters
                    else if (amount>=10 && amount<25)
                        {
                            d = amount /10;
                            System.out.println("Number of dimes:"+d);  
                            amount = amount % 10;
                        }
                    
                    //Condition for number of quarters
                    else if (amount >=25)
                        {
                             q = amount / 25;
                             System.out.println("Number of quarters:"+q);
                             amount =amount % 25;
                        }
                  }  while(amount>0);
          }
    }



