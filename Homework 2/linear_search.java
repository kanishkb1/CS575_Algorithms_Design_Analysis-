



import java.util.Scanner;
	
public class Linear_Search
	{
	public static void main(String args[])
		{
			int s;
			int[] arr;
			int i;
			int c;
			Scanner input = new Scanner(System.in);
			System.out.println("Enter size of array");
			s = input.nextInt();
			arr = new int[s];
			System.out.println("Enter elements of array");
			for(i = 0; i < s ; i ++)
			{
				System.out.println("Enter a["+(i+1)+"]");
				c = input.nextInt();
				arr[i] = c;
			}
			System.out.println(linear_search_function(arr,0,arr.length-1));
		
		}
/* This function is written for finding middle value which helps to divide the array into 2 equal halves */
		public static int linear_search_function(int[] arr, int min, int max){
			if(max>min)
			{
				int mid = (max + min) /2;
				if(mid == arr[mid])
				{
					return mid;
				}
				else if(mid > arr[mid])
				{
					return linear_search_function(arr,(mid + 1),max);
				}
				else
				{
					return linear_search_function(arr, min, (mid - 1));
				}
			}
		System.out.println("Program Execution stopped!!!");	
		return -1;
		}
	}
