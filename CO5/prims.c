#include<stdio.h>
#include<stdbool.h> 
#define infinity 1000
//#define v 5

int graph[20][20];
int v;
/*int graph[v][v] = {
      	 {0, 9, 75, 0, 0},
 	 {9, 0, 95, 19, 42},
 	 {75, 95, 0, 51, 66},
 	 {0, 19, 51, 0, 31},
 	 {0, 42, 66, 31, 0}};
	*/
/*void display(){
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			printf("%d",graph[i][j]);
		}
	}
}*/

void mst(bool span[]){

	int edge_count=0,total=0,x,y;
	
  	span[0]=1;
  	printf("\nEdge : Weight\n");
  	while(edge_count<v-1){
  		int cost=infinity;
  		for(int i=0;i<v;i++){
  			if(span[i]){
  				for(int j=0;j<v;j++){
  					if(!span[j] && graph[i][j]){
  						if(graph[i][j] < cost){
  							cost=graph[i][j];
  							x=i;
  							y=j;
  						}
  					}
  				}
  			}
  		}
  		printf("%d - %d : %d\n", x, y, graph[x][y]);
  		total+=graph[x][y];
   		span[y]=1;
    		edge_count++;
  	}
  	printf("\nTotal Cost=%d\n",total);
}

void main(){
	printf("\nEnter the number of vertices ");
	scanf("%d",&v);
	printf("\nEnter the Adjacency Matrix \n");
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			printf("Enter the edge weight of %d to %d ",i,j);
			scanf("%d",&graph[i][j]);
		}
	}
	
	for(int i=0;i<v;i++){
		graph[i][i]=0;	
	}
	
	bool span[v];	
	for(int i=0;i<v;i++){
  		span[i]=0;
  	}
	
	mst(span);
	
}
