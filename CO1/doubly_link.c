#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node*prev;
	int data;
	struct node*next;
};

struct node*header,*temp,*newnode,*ptr,*preptr;
void begin();
void af_pos();
void end();
void del_begin();
void del_af_pos();
void del_end();
void display();
int main()
{
	int c=0,option;
	header=(struct node*)malloc(sizeof(struct node));
	header->next=NULL;
	header->prev=NULL;
	printf("\n**** Doubly Linked List ****\n");
	while(c==0)
	{
		printf("\n**** Main Menu ****\n");
		printf("1. Insert at begining\n");
		printf("2. Insert after a data\n");
		printf("3. Insert at end\n");
		printf("4. Delete from begining\n");
		printf("5. Delete after a data\n");
		printf("6. Delete from end\n");
		printf("7. Display list\n");
	    printf("Enter your option : ");
	    scanf("%d",&option);
		switch(option)
		{
		case 1:begin();
			break;
		case 2:af_pos();
			break;
		case 3:end();
			break;
		case 4:del_begin();
			break;
		case 5:del_af_pos();
			break;
		case 6:del_end();
			break;
		case 7:display();
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
	newnode->prev=header;
	newnode->next=header->next;	
	header->next=newnode;
}

void af_pos()
{
	int dat,val;
	ptr=header;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data of the node after the new node has to be placed : ");
	scanf("%d",&dat);
	printf("Enter the data of the new node : ");
	scanf("%d",&val);
	while(ptr->data!=dat)
	{
		ptr=ptr->next;
	}
	newnode->data=val;
	newnode->next=ptr->next;
	newnode->prev=ptr;
	ptr->next->prev=newnode;
	ptr->next=newnode;	
}

void end()
{
	int val;
	ptr=header;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data of the new node : ");
	scanf("%d",&val);
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	newnode->data=val;
	newnode->next=ptr->next;	
	newnode->prev=ptr;
	ptr->next=newnode;
}

void del_begin()
{
	ptr=header;
	if(header->next==NULL)
	{
		printf("\nUnderflow\n");
	}
	else
	{
		ptr=ptr->next;
		header->next=ptr->next;
		ptr->next->prev=header;
		printf("Data of node deleted : %d\n",ptr->data);
		free(ptr);
	}
}

void del_af_pos()
{
	int val;
	ptr=header;
	if(header->next==NULL)
	{
		printf("\nUnderflow\n");
	}
	else
	{
		printf("Enter the data of the node after which the node has to be deleted : ");
		scanf("%d",&val);
		while(ptr->data!=val)
		{
			ptr=ptr->next;
		}
		temp=ptr->next;
		ptr->next=temp->next;
		temp->next->prev=ptr;
		printf("Data of node deleted : %d\n",temp->data);
		free(temp);		
	}
}

void del_end()
{
	ptr=header;
	if(header->next==NULL)
	{
		printf("\nUnderflow\n");
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->prev->next=ptr->next;
		printf("Data of node deleted : %d\n",ptr->data);
		free(ptr);		
	}
}

void display()
{
	temp=header;
	if(header->next==NULL)
	{
		printf("\nUnderflow\n");
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
			printf("%d\t",temp->data);
		}
		printf("\n");
	}
}

