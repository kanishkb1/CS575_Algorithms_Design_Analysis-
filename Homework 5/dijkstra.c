#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int graph[100][100];
int min_function(int x, int y);

//Implementation of Dijkstra's Algorithm
int Dijkstra_implementation(int v)
	{
  
  		int vertex[v+1];
 		for(int i=0;i<v+1;i++)
 			{
    				vertex[i]=0;
  			}
 //variable declaration
  		int vertex_visited[v+1];
  		int shortest_path[v];
		int count = 1;
		int min = 999;
  		int temp = 0;
  
 		printf("\n***Table Generation step***\t");
		for(int i=2;i<=v;i++)
    			{
				printf("V=%d\t",i);}
				printf("\n0\t");
  				vertex_visited[1] = 1;
  				count = 2;
 
  				vertex[1]=1;
  				int D[v+1][v+1]; 				
				int P[v+1][v+1];


  				for(int i=2;i<=v;i++)
 				 {
    					D[1][i-1]= graph[1][i];
  					P[1][i-1] = 1;
    					printf("%d,%d\t",D[1][i-1],P[1][i-1]);
    					if(D[1][i-1]<min)
    						{
     							min = D[1][i-1];
      							temp = i;
    						 }
  				}
  				printf("%d\t",vertex_visited[1]);
  				vertex[temp]=1;
				shortest_path[temp] = min;
  				printf("\n");
  
  
 				 for(int it=2;it<=v;it++)
 					 {
    
   					   printf("%d\t",it-1);
   					   vertex_visited[count] = temp;
    					   count++;  
					   min = 999;
  
  						  for(int dp=1;dp<v;dp++)
  								  {
    						  			if(vertex[dp+1] == 0)
										{
       							D[it][dp]=min_function(D[it-1][dp],D[it-1][vertex_visited[count-1]-1]+graph[vertex_visited[count-1]][dp+1]);
        
        if(min_function(D[it-1][dp],D[it-1][vertex_visited[count-1]-1]+graph[vertex_visited[count-1]][dp+1])==D[it-1][dp])
        { 
          P[it][dp]=P[it-1][dp];
        }
        else
        {  
          P[it][dp]=vertex_visited[count-1];
          
        }
       
          
        if(D[it][dp]<min)
        {
          min = D[it][dp];
          temp = dp+1;
        }
        
        printf("%d,%d\t",D[it][dp],P[it][dp]);
      
      }
      else
      {
        printf("----\t");
      }
      
    }
    for(int m=1;m<=count-1;m++)
      printf("%d,",vertex_visited[m]);
    if(min!=999)
    {
      shortest_path[temp] = min;
    }

    printf("\n");
    vertex[temp]=1;
  }
//print shortesat path
  for(int i=2;i<=v;i++)
  {
    printf("Shortest path from vertex 1 to %d is %d\n",i,shortest_path[i]);
  }
}

//function to calculate the minimum of two weights
int min_function(int x, int y)
	{
  		int min;
  		if(x<=y)
			{
				min = x;
			}
  
  		else
				min = y;
  				return min;
	}

//function for input of graph attributes
int inputgraph(int v)
	{
  		printf("Input: Adjacency matrix: \n");
  		for(int i=1;i<=v;i++)
  			{
  			  for(int j=1;j<=v;j++)
    				{
      					printf("Input: Enter edge from %d to %d",i,j);
      					scanf("%d",&graph[i][j]);
    				}
 			 }
  		Dijkstra_implementation(v);
 		return 0;
	}


//main function
int main()
	{
  		int v;
  		printf("Input: number of vertices : ");
  		scanf("%d",&v);
  		int graph[v+1][v+1];
  		inputgraph(v);

	}
