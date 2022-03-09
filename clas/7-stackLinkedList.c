#include<stdio.h>
#include<stdlib.h>
struct list
{
  int data;
  struct list *link;
};
struct list *headernode=NULL;
void push()
{
  int d;
  struct list *new, *temp;
  printf("Enter a data to insert \t");
  scanf("%d",&d);
  if(headernode==NULL)
  {
    new=(struct list*)malloc(sizeof(struct list));
    new->data=d;
    new->link=NULL;
    headernode=new;
  }
  else
  {
    temp=headernode;
    while(temp->link!=NULL)
    {
      temp=temp->link;
    }
    new=(struct list*)malloc(sizeof(struct list));
    new->data=d;
    new->link=NULL;
    temp->link=new;
  }
}

void pop()
{
  struct list *temp, *temp1;
  if(headernode==NULL)
  {
    printf("The stack is empty");
  }
  else if(headernode->link==NULL)
  {
    headernode=NULL;
    printf("Deleted succesfull\n");
  }
  else
  {
    temp=headernode;
    while(temp->link!=NULL)
    {
      temp1=temp;
      temp=temp->link;
    }
    temp1->link=NULL;
    printf("Deleted succesfull\n");
  }
}

void display()
{
  struct list *temp;
  if(headernode==NULL)
  {
    printf("The stack is empty");
  }
  else
  {
    printf("The stack is:\t");
    temp=headernode;
    while(temp!=NULL)
    {
      printf("%d\t",temp->data);
      temp=temp->link;
    }

  }
}
void main()
{
  int d;
  do{
    printf("\n---------\n");
    printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\nChoose any option \t");
    scanf("%d",&d);
    printf("---------\n");
    switch (d)
     {
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Exit point\n");
        break;
      default:
      printf("Indalied option\n");
    }
  }
  while(d!=4);
}
