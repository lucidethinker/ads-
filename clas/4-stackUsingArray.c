#include<stdio.h>
int top=-1,a[10];

void push()
{
    int data;
    if(top>=9)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Enter data to insert:");
        scanf("%d",&data);
        top=top+1;
        a[top]=data;
    }
}
void pop()
{
    int item;
    if(top<0)
    {
        printf("The stack is empty");
    }
    else
    {
        item=a[top];
        top=top-1;
        printf("The poped item is %d",item);
    }

}
void display()
{
    int i;
    if(top<0)
    {
      printf("Stack is empty ");
    }
    else
    {
      printf("The stack is \n");
      for(i=top;i>=0;i--)
      {
          printf("%d \n",a[i]);
      }
    }
}
void main()
{
    int d;
    do
    {
        printf("\nchoose a option \n 1.push \n 2.pop \n 3.display \n 4.exit \n");
        scanf("%d",&d);
        switch(d)
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
              printf("exit point");
              break;
            default:
            printf("Choose a valied option");
        }
    }
    while(d!=4);
}
