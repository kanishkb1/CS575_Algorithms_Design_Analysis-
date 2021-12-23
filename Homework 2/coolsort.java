/*       ***Name: Kanishk Barhanpurkar***
	 B-Number: B00863529	
	 Email-ID: kbarhan1@binghamton.edu
	 
Problem: CoolSort algorithm
*/

import java.util.*;
import java.util.Scanner;
import java.io.*;

public class CoolSort {

    public static void CoolSort(int sub_arr[], int sub_idx) {
        int i, j, val;
        for (i = 1; i < sub_idx; i++) {
            val = sub_arr[i];
            j = i - 1;
            while (j >= 0 && sub_arr[j] > val) {
                sub_arr[j + 1] = sub_arr[j];
                j--;
            }
            sub_arr[j + 1] = val;
        }
    }

    public static void main(String[] args) {

        // Open Scanner
        Scanner scanner = new Scanner(System.in);

        // Read Values
        System.out.println("Enter the number of elements in the array");
        int num_of_elements = scanner.nextInt();
        int main_arr[] = new int[num_of_elements];

        System.out.println("Enter the " + num_of_elements + " element(s) of the array");
        for (int i = 0; i < num_of_elements; i++) {
            main_arr[i] = scanner.nextInt();
        }

        System.out.println("Enter the number of steps");
        int step_size = scanner.nextInt();
        int step_arr[] = new int[step_size];

        System.out.println("Enter the " + step_size + " element(s) of the step array");
        for (int i = 0; i < step_size; i++) {
            step_arr[i] = scanner.nextInt();
        }

        // Close Scanner
        scanner.close();

        // Initialzing a sub array
        int sub_arr[] = new int[100];
        int step_idx = 0;

        while (step_size > step_idx) {
            int main_idx, sub_idx;
            main_idx = sub_idx = 0;
            int step = step_arr[step_idx];

            for (int i = 0; i < step_size; i++) {
                while (main_idx < num_of_elements) {
                    sub_arr[sub_idx] = main_arr[main_idx];
                    main_idx = main_idx + step;
                    sub_idx++;
                }
            }
            CoolSort(sub_arr, sub_idx);

            sub_idx = 0;
            main_idx = 0;
            for (int i = 0; i <= step_size; i++) {
                while (main_idx < num_of_elements) {
                    main_arr[main_idx] = sub_arr[sub_idx];
                    main_idx = main_idx + step;
                    sub_idx++;
                }
            }
            step_idx++;
        }
        System.out.println("Array is :");
        for (int i = 0; i < num_of_elements; i++) {
            System.out.println(" " + main_arr[i]);
        }
    }
}
