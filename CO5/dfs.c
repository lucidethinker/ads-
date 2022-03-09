#include<stdio.h>
void dfs(int);
int g[10][10],visited[10], n;
void main() 
{
int i, j;
printf ("enter the number of vertices:");
scanf ("%d", &n);
printf ("\n enter the adjacnecy matrix:");
for(i = 0; i < n; ++i)
{   
for(j = 0; j < n; ++j)     
{
printf("\n edge exist between vertices %d-%d :", i, j);    
scanf("%d", &g[i][j]);
}
}
for(i = 0; i < n; ++i) 
{    
visited[i] = 0; 
}
dfs(0);
}
void dfs(int i) 
{
int j;
printf ("\n %d", i);
visited[i] = 1;
for (j = 0; j < n; j++)
{    
if(!visited[j] && g[i][j] == 1)     
{	
dfs(j);      
}  
}
}



