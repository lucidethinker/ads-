#include<stdio.h>
#define N 5

int stack[N];
int top=-1;
void push();
void pop();
void final();
void display();

int main()
{
	int i,n;
	char a;
	do{
	    printf("Enter the operator no : ");
	    scanf("%d",&n);
		switch(n)
		{
		case 1:push();
			break;
		case 2:pop();
			break;
		case 3:final();
			break;
		case 4:display();
			break;
		default:printf("Invalid Operator");
		}
		printf("\nDo you want to continue?\n");
		scanf("%s",&a);
	}while((a=='Y')||(a=='y'));
	return 0;
}

void push()
{	
	printf("Push\n");
	int v;
	if(top==N-1)
	{
		printf("Overflow");
	}
	else
	{
		top++;
		printf("Enter the value : ");
		scanf("%d",&v);
		stack[top]=v;
		printf("\nValue pushed to stack\n");
	}
}

void pop()
{
	printf("Pop\n");
	int item;
	if(top==-1)
	{
		printf("Underflow");
	}
	else
	{
		item=stack[top];
		printf("\nValue %d popped from the stack\n",item);
		top--;
	}
}

void final()
{
	printf("Last\n");
	if(top==-1)
	{
		printf("Stack doesn't exist ");
	}
	else
	{
		printf("%d",stack[top]);	
	}
}

void display()
{
	printf("Display\n");
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);	
	}
}

