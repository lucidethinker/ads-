#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*link;
};

struct node*header,*temp,*newnode;
void begin();
void count();
void search();
void display();
int main()
{
	int c=0,option;
	header=(struct node*)malloc(sizeof(struct node));
	header->link=NULL;
	while(c!=1)
	{
		printf("\n**** Main Menu ****\n");
		printf("1. Insert an element\n");
		printf("2. Count of nodes\n");
		printf("3. Search\n");
		printf("4. Display list\n");
		printf("5.Exit\n");
	    printf("Enter your option : ");
	    scanf("%d",&option);
		switch(option)
		{
		case 1:begin();
			break;
		case 2:count();
			break;
		case 3:search();
			break;
		case 4:display();
			break;
		default:printf("Invalid Operator");
		}
		printf("Do you want to continue(0/1) : ");
		scanf("%d",&c);
	}
	return 0;
}

void begin()
{
	int val;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d",&val);
	newnode->data=val;
	newnode->link=header->link;	
	header->link=newnode;
}

void count()
{
	temp=header;
	int count=0;
	while(temp->link!=NULL)
	{	
		count++;
		temp=temp->link;
		printf("%d\t",temp->data);
	}
	printf("\nNumber of nodes in list is : %d\n",count);
}

void search()
{
	temp=header;
	int key,pos=0,flag=0;
	printf("Enter the value to be searched : ");
	scanf("%d",&key);
	while(temp->link!=NULL)
	{
		temp=temp->link;
		pos=pos+1;
		if(temp->data==key)
		{
			printf("%d found at %d\n",key,pos);
			flag=flag+1;
			break;
		}
	}
	if(flag==0)	
	{
		printf("Data not found in list\n");
	}
}

void display()
{
	temp=header;
	if(header->link==NULL)
	{
		printf("\nUnderflow\n");
	}
	else
	{
		while(temp->link!=NULL)
		{
		temp=temp->link;
		printf("%d\t",temp->data);
		}
		printf("\n");
	}
}

