#include<stdio.h>
int a[10],frond=-1,rear=-1;
void enqueue()
{
  int data;
  if(((rear+1)%10)==frond)
  {
    printf("Queue is oveflow \n");
  }
  else if(frond==-1)
  {
    frond=0;
    printf("Enter the data to insert\n");
    scanf("%d",&data);
    rear=(rear+1)%10;
    a[rear]=data;
  }
  else
  {
    printf("Enter the data to insert\n");
    scanf("%d",&data);
    rear=(rear+1)%10;
    a[rear]=data;
  }
}
void dequeue()
{
  int item;
  if(frond==-1)
  {
    printf("The queue is under flow\n");
  }
  else if(frond==rear)
  {
    item=a[frond];
    frond=-1;
    rear=-1;
    printf("The deleted item is %d\n",item );
  }
  else
  {
    item=a[frond];
    frond=(frond+1)%10;
    printf("The deleted item is %d\n",item );
  }

}
void display()
{
  int i,f=frond,r=rear;
  if(frond==-1)
  {
    printf("Queue is underflow\n");
  }
  else
  {
    printf("The queue is \n");
    if(f>r)
    {
      while(f>r)
      {
        printf("%d\t",a[f]);
        f=(f+1)%10;
      }
    }
    if(f<=r)
    {
      for(i=f;i<=r;i++)
      {
        printf("%d \t",a[i]);
      }
   }
  }
}
void main()
{
  int d;
  do{
    printf("\n---------------\n");
    printf("\n choose any option \n1.Insertion\n2.Deletion\n3.Display\n4.exit\n");
    scanf("%d",&d);
    printf("---------------\n");
    switch (d)
    {
      case 1:
          enqueue();
          break;
      case 2:
          dequeue();
          break;
      case 3:
          display();
          break;
      case 4:
          printf("Exit point\n");
          break;
        default:
        printf("invalied option");
    }
  }
    while(d!=4);

}
