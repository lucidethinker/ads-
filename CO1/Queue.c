#include<stdio.h>
#define N 5

int queue[N];
int front=-1,rear=-1;
void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main()
{
	int option,val;
	do{
		printf("\n**** Main Menu ****\n");
		printf("1. Insert an element\n");
		printf("2. Delete an elemnet\n");
		printf("3. Peek(top in queue)\n");
		printf("4.Display queue\n");
		printf("5.Exit\n");
	    printf("Enter your option : ");
	    scanf("%d",&option);
		switch(option)
		{
		case 1:insert();
			break;
		case 2:val=delete_element();
			if(val!=-1)
			{
				printf("\nThe number deleted is %d\n", val);
			}
			break;
		case 3:val=peek();
			if(val!=-1)
			{
				printf("\nThe first value in queue is : %d\n", val);
			}
			break;
		case 4:display();
			break;
		default:printf("Invalid Operator");
		}
	}while(option!=5);
	return 0;
}

void insert()
{	
	int num;
	printf("\nEnter the number to be inserted in to the queue : ");
	scanf("%d",&num);
	if(rear==N-1)
	{
		printf("\n Overflow ");
	}
	else if((front==-1) && (rear==-1))
	{
		front=rear=0;
		queue[rear]=num;
	}
	else
	{
		rear++;
		queue[rear]=num;
	}
}

int delete_element()
{
	int val;
	if((front==-1)|| (front>rear))
	{
		printf("\n Underflow ");
		return -1;
	}
	else
	{
		val=queue[front];
		front++;
		if(front>rear)
		{
			front=rear=-1;
		}
		return val;
	}
}

int peek()
{
	if((front==-1)|| (front>rear))
	{
		printf("\n Queue Empty ");
		return -1;
	}
	else
	{
		return queue[front];
	}
}

void display()
{
	int i;
	if((front==-1)|| (front>rear))
	{
		printf("\n Queue Empty ");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
		printf("\n");
	}
}

