#include <stdio.h>

int parent[7];
int rank[7];

void makeSet(int x)
{
    parent[x] = x;
    rank[x] = 0;
}
int findSet(int x) 
{
    if(x != parent[x])
        parent[x] = findSet(parent[x]);
    return(parent[x]); 
}
void link(int x, int y)
{
    if(rank[x] > rank[y])
        parent[y] = x;
    else
    {
        parent[x] = y;
        if(rank[x] == rank[y])
            rank[y] = rank[y] + 1;
    }
}
void unionSet(int x, int y) 
{
    x = findSet(x);
    y = findSet(y);
    link(x, y);
}
int main()
{
    int i;
    makeSet(0);
    makeSet(1);
    makeSet(2);
    makeSet(3);
    makeSet(4);
    makeSet(5);
    makeSet(6);
    //printf("%d", findSet(1));
    unionSet(0, 1);
    //printf("%d", findSet(0));
    unionSet(1, 2);
    //printf("%d", findSet(2));
    unionSet(3, 4);
    //printf("%d", findSet(3));
    unionSet(5, 6);
    //printf("%d", findSet(5));
    unionSet(4, 5);
    //printf("%d", findSet(3));
    unionSet(2, 6);
    //printf("%d", findSet(5));
    for(i=0;i<7;i++)
    {
        printf("Parent of %d is %d.",i,parent[i]);
        printf("Rank of %d is %d.\n",i,rank[i]);
    }
    return 0;
}