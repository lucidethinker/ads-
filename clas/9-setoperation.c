#include<stdio.h>

char alphabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; //universal set
char setA[3] = {'a','b','c'}; //To store the elements of setA 
char setB[3] = {'c','d','f'}; //To store the elements of setB
int vA[26],vB[26]; //To store the BitVector form of setA (VA) and setB (VB)
int result[26]; //To result the BitVector form of the set operations

void initilize()
{
	int i;
	for(i=0;i<26;i++)
	{
		vA[i]=0;
		vB[i]=0;
		result[i]=0;
	}
}
void bitVector(char ary[], int v[], int sze)
{
    //ary can be setA or setB
    //v can be vA or vB
	int i,j;
	for(i=0;i<sze;i++)
	{
		for(j=0;j<26;j++)
		{
			if(ary[i]==alphabet[j])
				v[j]=1;
		}
	}
}
void setunion(int vA[], int vB[])
{
    int i;
    for(i=0;i<26;i++)
        result[i] = vA[i] | vB[i];
}
void setintersection(int vA[], int vB[])
{
    int i;
    for(i=0;i<26;i++)
        result[i] = vA[i] & vB[i];
}
void setcomplement(int v[])
{
    int i;
    for(i=0;i<26;i++)
    {
        if(v[i]==0)
            result[i]=1;
        else
            result[i]=0;
    }
}
void setdifference(int vA[], int vB[])
{
    setcomplement(vB);
    setintersection(vA, result);
}
void display(int ary[])
{
	int i;
	for(i=0;i<26;i++)
		printf("%d ",ary[i]);
	printf("\n");
}
int main()
{
	int i, sa=3, sb=3;

	initilize(); //function call to initialize
    //call to form bitVector representation of setA and setB
	bitVector(setA, vA, sa);
	bitVector(setB, vB, sb);
	display(vA);
	display(vB);
	//call set operations
    	setunion(vA, vB);
    	display(result);
    	setintersection(vA, vB);
    	display(result);
    	setcomplement(vA);
    	display(result);
    	setdifference(vA, vB);
    	display(result);
    
	return(0);
}