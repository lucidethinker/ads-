#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*link;
};

struct node*header,*temp,*newnode,*ptr,*preptr;
void push();
void pop();
void display();
int main()
{
	int c=0,option;
	header=(struct node*)malloc(sizeof(struct node));
	header->link=NULL;
	while(c!=1)
	{
		printf("\n**** Main Menu ****\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display stack\n");
	    printf("Enter your option : ");
	    scanf("%d",&option);
		switch(option)
		{
		case 1:push();
			break;
		case 2:pop();
			break;
		case 3:display();
			break;
		default:printf("Invalid Operator");
		}
		printf("Do you want to continue(0/1) : ");
		scanf("%d",&c);
	}
	return 0;
}

void push()
{
	int val;
	ptr=header;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d",&val);
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	newnode->data=val;
	newnode->link=ptr->link;	
	ptr->link=newnode;
}

void pop()
{
	ptr=header;
	if(header->link==NULL)
	{
		printf("\nUnderflow\n");
	}
	else
	{
		while(ptr->link!=NULL)
		{
			preptr=ptr;
			ptr=ptr->link;
		}
		preptr->link=ptr->link;
		printf("Data of data deleted : %d\n",ptr->data);
		free(ptr);		
	}
}

void display()
{
	temp=header;
	if(header->link==NULL)
	{
		printf("\nUnderflow\n");
	}
	while(temp->link!=NULL)
	{
		temp=temp->link;
		printf("%d\t",temp->data);
	}
	printf("\n");
}

