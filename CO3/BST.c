#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree*left;
    struct tree*right;
};
struct tree *p,*s,*t;
void preorder(struct tree *node)
{
	if(node!=NULL)
	{
		printf("%d ",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
void postorder(struct tree *node)
{
	if(node!=NULL)
	{
		postorder(node->left);
		postorder(node->right);
        printf("%d ",node->data);
	}
}
void inorder(struct tree *node)
{
	if(node!=NULL)
	{
		inorder(node->left);
        printf("%d ",node->data);
		inorder(node->right);
	}
}
void search(struct tree *node,int x){
    if(node==NULL){
        printf("Tree empty");
    }
    else{
        if(x<node->data){
            search(node->left,x);
        }
        if(x>node->data){
            search(node->right,x);
        }
        if(x==node->data){
            printf("\nData found %d",node->data);
        }
    }
}
void min(struct tree *node){
    while(node->left!=NULL){
        node=node->left;
    }
    printf("\nMinimum Node in the tree %d",node->data);
}
void max(struct tree *node){
    while(node->right!=NULL){
        node=node->right;
    }
    printf("\nMaximum node in the tree %d",node->data);
}
void inordersuccessor(struct tree *node,int x)
{
    struct tree *temp=node,*n;
	if(temp->data==x){
        if(temp->right!=NULL)
        {
            temp=temp->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            printf("\nInorder Successor of %d is %d",x,temp->data);
        }
        else{
            printf("%d",temp->data);
            printf("\n%d",p->data);
            printf("\n%d",s->data);
            if(x<p->data)
            printf("\nInorder Successor of %d is %d",x,p->data);
            else if(x<s->data)
            printf("\nInorder Successor of %d is %d",x,s->data);
            else
            printf("\nInorder Successor of %d is %d",x,t->data);
        }
    }
    else if(temp->data<x){
        if(t==NULL){
            t=temp->right;
        }
        n=temp->right;
        if(n->data!=x){
            s=temp;
        }
        if(temp->right!=NULL)
        {
            p=temp;
            temp=temp->right;
            inordersuccessor(temp,x);
        }
    }
    else{
        if(t==NULL){
            t=temp->left;
        }
        n=temp->left;
        if(n->data!=x){
            s=temp;
        }
        if(temp->left!=NULL)
        {
            p=temp;
            temp=temp->left;
            inordersuccessor(temp,x);
        }
    }
}
void main(){
    int n,i,item,x,c=1,option;
    struct tree *root,*p,*q;
    printf("Enter the no of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p=(struct tree *)malloc(sizeof(struct tree));
        printf("Enter the data of the node : ");
        scanf("%d",&item);
        p->data=item;
        p->left=NULL;
        p->right=NULL;
        if(i==0){
            root=p;
        }
        else{
            q=root;
            while(1){
                if(p->data>q->data){
                    if(q->right==NULL){
                        q->right=p;
                        break;
                    }
                    else{
                        q=q->right;
                    }
                }
                else{
                    if(q->left==NULL){
                        q->left=p;
                        break;
                    }
                    else{
                        q=q->left;
                    }
                }
            }
        }
    }
    printf("\n**** Binary Search Tree Operation****\n");
	while(c==1)
	{
		printf("\n**** Main Menu ****\n");
		printf("1. Search\n");
		printf("2. Preorder\n");
		printf("3. Inorder\n");
		printf("4. Postorder\n");
		printf("5. Minimum value\n");
		printf("6. Maximum value\n");
		printf("7. Inorder Successor\n");
	    printf("\nEnter your option : ");
	    scanf("%d",&option);
		switch(option)
		{
			case 1: printf("\nEnter the data to be searched: ");
				scanf("%d",&x);
				search(root,x);
				break;
			case 2: preorder(root);
				break;
			case 3: inorder(root);
				break;
			case 4: postorder(root);
				break;
			case 5: min(root);
				break;
			case 6: max(root);
				break;
			case 7: printf("\nEnter the data to find successor: ");
				scanf("%d",&x);
				inordersuccessor(root,x);
				break;
			default: printf("\nInvalid Option");
		}
		printf("\nDo you want to continue(0/1) : ");
		scanf("%d",&c);
	}
}

