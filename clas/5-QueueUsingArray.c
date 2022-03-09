#include<stdio.h>
int frond=-1,rear=-1,a[10];
void enqueue()
{
  int data;
  if(rear>=9)
  {
    printf("queue is overflow");
  }
  else if(rear<0)
  {
    printf("Enter data to insert\t");
    scanf("%d",&data);
    frond=0;
    rear=0;
    a[rear]=data;
  }
  else
  {
    printf("Enter data to insert\t");
    scanf("%d",&data);
    rear=rear+1;
    a[rear]=data;
  }
}
void dequeue()
{
  int item;
  if(frond<0 && rear<0)
  {
    printf("Queue is under flow");
  }
  else if (frond==rear)
  {
    item=a[frond];
    frond=-1;
    rear=-1;
    printf("deleted item is %d\n",item );
  }
  else
  {
    item=a[frond];
    frond=frond+1;
    printf("deleted item is %d\n",item );
  }
}
void display()
{
  int i;
  if(frond<0)
  {
    printf("queue is under flow\n");
  }
  else
  {
    printf("The queue is \n");
    for(i=frond;i<=rear;i++)
    {
      printf("%d \t",a[i]);
    }
  }
}
void main()
{
  int d;
  do
  {
    printf("\n---------------\n");
    printf("\n choose any option \n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
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
    printf("Exit point");
    break;
    default:
    printf("invalied option");
    }
  }
    while(d!=4);
}
