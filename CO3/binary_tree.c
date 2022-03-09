#include<stdio.h>
#include<stdlib.h>

struct tree
{
	struct tree*left;
	int data;
	struct tree*right;
};

struct tree *create()
{
	int item;
	struct tree *node;
	node=(struct tree *)malloc(sizeof(struct tree));
	printf("\nEnter the data (insert 0 if no child) :");
	scanf("%d",&item);
	if(item==0)
	{
		return NULL;
	}
	node->data=item;
	printf("Enter the left child of %d ",node->data);
	node->left=create();
	printf("Enter the right child of %d ",node->data);
	node->right=create();
	return node;
}

void preorder(struct tree *node)
{
	if(node!=NULL)
	{
		printf("%d",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(struct tree *node)
{
	if(node!=NULL)
	{
		inorder(node->left);
		printf("%d",node->data);
		inorder(node->right);
	}
}
void postorder(struct tree *node)
{
	if(node!=NULL)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d",node->data);
	}
}


int main()
{
	struct tree *root;
	root=create();
	printf("\nPreorder traversal of the node : ");
	preorder(root);
	printf("\nInorder traversal of the node : ");
	inorder(root);
	printf("\nPostorder traversal of the node : ");
	postorder(root);
	return 0;
}