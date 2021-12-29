#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
  //Variable declaration
  string s1;
  string s2;
  int m;
  int n;
  int i;
  int j;
  int pointer = 0;
  int lcs[50];
  
  //Input 2 string values 
  cout << "Enter String 1 for LCS problem: " ;
  cin >> s1;
  cout << "Enter String 2 for LCS problem: " ;
  cin >> s2;
 
  //Calculating string length for both strings.
  m= s1.length();
  n= s2.length();
 
  int table[m+1][n+1];
  for(i=0;i<=m;i++)
    {
      for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            //initialize row and column ->0
                {
                    table[i][j] = 0;
                }
            //if the length of both strings are not equal
            else if(s1[i-1] != s2[j-1])
                {
                    table[i][j] = (table[i-1][j]>=table[i][j-1]) ? table[i-1][j] : table[i][j-1];
                }
            //if the length of both strings are equal 
            else
                {
                    
                    table[i][j] = table[i-1][j-1] + 1;
                }
            //printing table
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
 
 
  
  i = m;
  j = n;
  while(i!=0 && j!=0)
    {
        if(table[i][j]!=table[i-1][j] && table[i][j]!=table[i][j-1])
            {
                i--;
                j--;
                lcs[pointer] = i;
                pointer++;
            }
        else if(table[i][j]==table[i][j-1])
            {
                j--;
            }
        else
            {
                i--;
            }
    }
  //printing the Longest Common Subsequence string
  for(i=pointer-1;i>=0;i--)
        {
            cout <<s1[lcs[i]];
        }
    cout << endl;
    
}//end of main function