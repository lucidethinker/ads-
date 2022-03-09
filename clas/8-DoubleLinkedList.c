#include<stdio.h>
#include<stdlib.h>
struct dlist
{
struct dlist *llink;
int data;
struct dlist *rlink;
};
struct dlist *headernode=NULL;


void InsertionAtFirst()
{
	int a;
	struct dlist *temp, *new;
	printf("Enter a number for insertion \t");
	scanf("%d",&a);
	new=(struct dlist*)malloc(sizeof(struct dlist));
	new->llink=NULL;
	new->data=a;
		if(headernode==NULL)
		{
			new->rlink=NULL;
			headernode=new;
		}
	else
	{
		new->rlink=headernode;
		headernode->llink=new;
		headernode=new;
	}
}


void InsertAtLast()
{
	int a;
	struct dlist  *temp,*temp1, *new;
	printf("Enter a number for insertion \t");
	scanf("%d",&a);
	new=(struct dlist*)malloc(sizeof(struct dlist));
	new->data=a;
	new->rlink=NULL;
	if(headernode==NULL)
	{
		{
			new->llink=NULL;
			headernode=new;
		}
	}
	else
	{
		temp=headernode;
		while(temp!=NULL)
		{
			temp1=temp;
			temp=temp->rlink;

		}
		temp1->rlink=new;
		new->llink=temp1;
	}
}


void InsertInterMediate()
{
	struct dlist *temp, *temp1, *new;
	int key,a,found=0;
	temp=headernode;
	if(headernode==NULL)
	{
		printf("Empty list");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d \t",temp->data);
			temp=temp->rlink;
		}
		printf("\nChoose any key value  (note that the new value insert before this key value )");
		scanf("%d",&key);
		if(key==headernode->data)
		{
			InsertionAtFirst();
		}
		else
		{
			temp=headernode->rlink;
			while(temp!=NULL)
			{
						if(temp->data==key)
						{
							temp1=temp;
							found=1;
						}
						temp=temp->rlink;

			}
			if(found==1)
			{
				printf("Enter a number for insertion \t");
				scanf("%d",&a);
				new=(struct dlist*)malloc(sizeof(struct dlist));
				new->data=a;
				(temp1->llink)->rlink=new;
				new->rlink=temp1;
				new->llink=temp1->llink;
				temp1->llink=new;
			}
			else
			{
				printf("Invalied key");
			}
		}
	}
}


void deleteAtFirst()
{
	if(headernode==NULL)
	{
		printf("Empty list");
	}
	else if(headernode->rlink==NULL)
	{
		headernode=NULL;
	}
	else
	{
		headernode=headernode->rlink;
		headernode->llink==NULL;
	}
}


void deleteAtLast()
{
	struct dlist *temp;
	if(headernode==NULL)
	{
		printf("Empty list");
	}
	else if(headernode->rlink==NULL)
	{
		headernode==NULL;
	}
	else
	{
		temp=headernode;
		while(temp->rlink!=NULL)
		{
			temp=temp->rlink;
		}
		(temp->llink)->rlink=NULL;
		temp=NULL;
	}

}


void deleteInterMediate()
{
	struct dlist *temp, *temp1, *temp3;
	int d, found=0;
	if(headernode==NULL)
		printf("Empty list");
	else
	{
		temp=headernode;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp3=temp;
			temp=temp->rlink;
		}
		printf("\nChoose a key to delete");
		scanf("%d",&d);
		if(headernode->data==d)
		{
			deleteAtFirst();
		}
		else if(temp3->data==d)
		{
			deleteAtLast();
		}
		else
		{
			temp=headernode;
			while(temp!=NULL)
			{
						if(temp->data==d)
						{
							temp1=temp;
							found=1;
						}
						temp=temp->rlink;

			}
			if(found==1)
			{
				(temp1->llink)->rlink=temp1->rlink;
				(temp1->rlink)->llink=temp1->llink;
			}
			else
			{
				printf("Invalied key");
			}
		}
	}

}

void displayForward()
{
	struct dlist *temp;
	if(headernode==NULL)
	{
		printf("Empty list");
	}
	else
	{
		printf("The list is\n");
		temp=headernode;
		while(temp!=NULL)
			{
				printf("%d \t",temp->data);
				temp=temp->rlink;
			}
	}
}


void DisplayReverse()
{
	struct dlist *temp;
	temp=headernode;
	if(headernode==NULL)
	{
		printf("Empty list");
	}
	else
	{
		while(temp->rlink!=NULL)
		{
			temp=temp->rlink;
		}
		printf("The list is\n");
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->llink;

		}
	}
}


void main()
{
    int s=1;
		printf(" \n 1.Insertion at first \n 2.Insertion at last \n 3.Insertion at inter mediate node  \n 4.Delete at first\n 5.Delete At Last \n 6.delete intermediate\n 7.Display Forward\n 8.Display Reverse\n9.exit"
	);
    do
    {
			printf("\n----------");
	    printf("\n Choose any option\t");
	    scanf("%d",&s);
			printf("----------\n");
	    switch(s)
	    {
	        case 1:
	         InsertionAtFirst();
	         break;
	        case 2:
	         InsertAtLast();
	         break;
	        case 3:
	         InsertInterMediate();
	         break;
	        case 4:
	       		deleteAtFirst();
	         break;
					case 5:
						deleteAtLast();
						break;
					case 6:
						deleteInterMediate();
						break;
					case 7:
						displayForward();
						break;
					case 8:
						DisplayReverse();
						break;
					case 9:
							printf("Exit succesfully\n");
						break;
	        default:
	         printf("Indalied option try again");
    	}
    }
    while(s!=9);
}
