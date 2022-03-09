#include<stdio.h>
void main()
{
    int a[10],size,sum=0,i;
    printf("Enter howmany numbers do you want to add\t");
    scanf("%d",&size);
    printf("Enter %d numbers \n",size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    printf("The sum of the given numbers is %d",sum);
}
