import java.util.Scanner;
public class prims_implementation
{
	public static void main(String[] args) 
	{
 
  //variable declaration
	int w[][]=new int[10][10];
	int n;
  int i;
  int j;
  int s;
  int k=0;
	int min;  
	int sum=0;
	int u=0;
  int v=0;
	int flag=0;
	int sol[]=new int[10];
 
  //input values
  Scanner sc=new Scanner(System.in);
   
	System.out.println("Enter the number of vertices in the graph");
	n=sc.nextInt();
 
	for(i=1;i<=n;i++)
  sol[i]=0;
  System.out.println("Enter the weighted graph for Prims Algorithm");
	
  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  w[i][j]=sc.nextInt();
  
	
  System.out.println("Enter the source vertex where we have to calculate the minimum spanning tree:");
	s=sc.nextInt();
	sol[s]=1;
	k=1;
	
  while (k<=n-1)
	{
		min=99;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		if(sol[i]==1&&sol[j]==0)
		if(i!=j&&min>w[i][j])
		{
			min=w[i][j];
			u=i;
			v=j;	
		}
   
		sol[v]=1;
		sum=sum+min;
		k++;
   
		System.out.println("Vertex from " + u +" to "+ v +" = "+min);
	}
 
	for(i=1;i<=n;i++)
	if(sol[i]==0)
		flag=1;
	if(flag==1)
  {
		System.out.println("No spanning tree");
  } 
	else
  {
		System.out.println("The cost of minimum spanning tree is "+sum);
  }
	sc.close();
	}
}