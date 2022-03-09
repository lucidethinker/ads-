#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*link;
};

struct node*header,*temp,*newnode,*ptr,*preptr;
void insert();
void delete();
void display();
int main()
{
	int c=0,option;
	header=(struct node*)malloc(sizeof(struct node));
	header->link=NULL;
	printf("\n**** Linked Queue ****\n");
	while(c==0)
	{
		printf("\n**** Main Menu ****\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display queue\n");
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
		default:printf("Invalid Operator");
		}
		printf("Do you want to continue(0/1) : ");
		scanf("%d",&c);
	}
	return 0;
}

void insert()
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

void delete()
{
	ptr=header;
	if(header->link==NULL)
	{
		printf("\nUnderflow\n");
	}
	else
	{
		ptr=ptr->link;
		header->link=ptr->link;
		printf("Data of node deleted : %d\n",ptr->data);
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


