#include<stdio.h>
#include<stdlib.h>
#define N 4

int front=-1,rear=-1;
int queue[N];

void insert();
void delete();
void display();
void peek();
int main()
{
	int c=0,option;
	printf("\n**** Circular Queue ****\n");
	while(c==0)
	{
		printf("\n**** Main Menu ****\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display queue\n");
		printf("4. Peek\n");
	    printf("Enter your option : ");
	    scanf("%d",&option);
		switch(option)
		{
		case 1:insert();
			break;
		case 2:delete();
			break;
		case 3:display();
			break;
		case 4:peek();
			break;
		default:printf("Invalid Operator");
		}
		printf("Do you want to continue(0/1) : ");
		scanf("%d",&c);
	}
	return 0;
}

void insert()
{
	int val,temp;
	printf("Front = %d",front);
	printf("Rear = %d\n",rear);
	if((front==0) && (rear==N-1))
	{
		printf("Overflow\n");
	}
	else
	{
		printf("Enter the data : ");
		scanf("%d",&val);	
		if((front==-1) && (rear==-1))
		{
			front=rear=0;
			queue[rear]=val;
		}
		else if((front!=0) && (rear==N-1))
		{
			rear=0;
			queue[rear]=val;
		}
		else
		{
			temp=rear+1;
			if(temp!=front)
			{
				rear=rear+1;
				queue[rear]=val;
			}
			else
			{
				printf("Overflow\n");
			}
		}
	}
}

void delete()
{
	int val;
	printf("Front = %d",front);
	printf("Rear = %d\n",rear);
	if(front==-1)
	{
		printf("Underflow\n");
	}
	else
	{
		if(front==rear)
		{
			printf("Data deleted from queue : %d \n",queue[front]);
			val=queue[front];
			front=rear=-1;
		}
		else if(front==N-1)
		{	
			printf("Data deleted from queue : %d \n",queue[front]);
			val=queue[front];
			front=0;
		}
		else
		{
			printf("Data deleted from queue : %d \n",queue[front]);
			val=queue[front];
			front=front+1;
		}
	}
}

void display()
{
	int i;
	printf("Front = %d",front);
	printf("Rear = %d\n",rear);
	if((front==-1)&&(rear==-1))
	{
		printf("Queue Empty\n");
	}
	else
	{
		if(front<rear)
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d\t",queue[i]);
			}
		}
		else if((front==rear))
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d\t",queue[i]);
			}
		}
		else
		{
			for(i=0;i<=rear;i++)
			{
				printf("%d\t",queue[i]);
			}
			for(i=front;i<N;i++)
			{
				printf("%d\t",queue[i]);
			}
		}
		printf("\n");
	}
}
void peek()
{
	if(front==-1)
	{
		printf("Queue Empty\n");
	}
	else
	{
		printf("First Element in the queue : ");
		printf("%d\n",queue[front]);
	}
}
	


