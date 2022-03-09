#include<stdio.h>
void main()
{
    int a1[10],a2[10],b[20],size1,size2,i,j,k,size,temp;
    printf("Enter size of first array:");
    scanf("%d",&size1);
    printf("Enter first array elements:");
    for(i=0;i<size1;i++)
    {
        scanf("%d",&a1[i]);
    }
    for(i=0;i<size1;i++)
    {
        for(j=i+1;j<size1;j++)
        {
            if(a1[i]>a1[j])
            {
                temp=a1[i];
                a1[i]=a1[j];
                a1[j]=temp;
            }
        }

    }
    printf("Enter size of second array:");
    scanf("%d",&size2);
    printf("Enter second array elements:");
    for(i=0;i<size2;i++)
    {
        scanf("%d",&a2[i]);
    }
    for(i=0;i<size2;i++)
    {
        for(j=i+1;j<size2;j++)
        {
            if(a2[i]>a2[j])
            {
                temp=a2[i];
                a2[i]=a2[j];
                a2[j]=temp;
            }
        }
    }
    size=size1+size2;
    for(i=0;i<size1;i++)
        b[i]=a1[i];
    for(i=size1;i<size;i++)
	{	 k=i-size1;
       		 b[i]=a2[k];
	}
  printf("The merged array is \n");
    for(i=0;i<size;i++)
        printf("%d \t",b[i]);

}
