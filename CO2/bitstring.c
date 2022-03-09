#include<stdio.h>
#include<stdlib.h>

int u[20],a[20],b[20],a_[20],b_[20],uni[20],in[20],dif[20],i=0,j,flag=0,k=0,n,m,o,c=0;

void unio();
void inter();
void diff();
void main(){
	printf("Enter the size of universal set :");
	scanf("%d",&n);
	printf("Enter the size of set a :");
	scanf("%d",&m);
	printf("Enter the size of set b :");
	scanf("%d",&o);
	printf("Enter the universal set :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&u[i]);
	}
	printf("Enter the set a :");
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the set b :");
	for(i=0;i<o;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(u[i]==a[j])
			{
				flag=1;
				break;
			}
			else
			{
				flag=0;
			}
		}
		if(flag==1)
		{
			a_[k]=1;
			k++;
		}
		else
		{
			a_[k]=0;
			k++;
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<o;j++)
		{
			if(u[i]==b[j])
			{
				flag=1;
				break;
			}
			else
			{
				flag=0;
			}
		}
		if(flag==1)
		{
			b_[k]=1;
			k++;
		}
		else
		{
			b_[k]=0;
			k++;
		}
	}
	printf("Bitstring of a :");
	for(i=0;i<n;i++)
	{
		printf("%d",a_[i]);
	}
	printf("\nBitstring of b :");
	for(i=0;i<n;i++)
	{
		printf("%d",b_[i]);
	}
	do
	{
		printf("\n1. UNION \n");
		printf("2. INTERSECTION\n");
		printf("3. DIFFERENCE\n");
		printf("4. Exit\n");
		printf("Enter your Option :\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:unio();
					break;
			case 2:inter();
					break;
			case 3:diff();
					break;
			case 4:printf("\nExiting");
					break;
			default:printf("Invalid operator");
		}
	}while(c!=4);
}
void unio()
{
	i=0;
	while(i<n)
	{
		uni[i]=a_[i]|b_[i];
		i++;
	}
	printf("Union of a and b :");
	for(i=0;i<n;i++)
	{
		printf("%d",uni[i]);
	}
}
void inter()
{
	i=0;
	while(i<n)
	{
		in[i]=a_[i]&b_[i];
		i++;
	}
	printf("Intersection of a and b :");
	for(i=0;i<n;i++)
	{
		printf("%d",in[i]);
	}
}
void diff()
{
	for(i=0;i<n;i++)
	{
		if(b_[i]==1)
		{
			b_[i]=0;
		}
		else
		{
			b_[i]=1;
		}
	}
	printf("Complement of b :");
	for(i=0;i<n;i++)
	{
		printf("%d",b_[i]);
	}
	i=0;
	while(i<n)
	{
		dif[i]=a_[i]&b_[i];
		i++;
	}
	printf("\nDifference of a and b :");
	for(i=0;i<n;i++)
	{
		printf("%d",dif[i]);
	}
}


