#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node*left;
	struct node*right;
}NODE;
NODE*create_bst(NODE*root)
{
	int i,n,num;
	NODE*newnode,*temp,*parent;
	printf("Enter how many node\n");
	scanf("%d",&n);
	printf("enter the data in a node");
	for(i=0;i<n;i++)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		scanf("%d",&num);
		newnode->data=num;
		newnode->left=newnode->right=NULL;
		if(root==NULL)
		{
			root=newnode;
			continue;
		}
		temp=root;
		while(temp!=NULL)
		{
			parent=temp;
			if(num>temp->data)
				temp=temp->left;
			else
				parent->right=newnode;
		}
		if(num<parent->data)
parent->left=newnode;
else
parent->right=newnode;
	}
	return root ;
}

void preorder(NODE*root)
{
	NODE*temp=root;
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void inorder(NODE*root)
{
	NODE*temp=root;
	if(temp!=NULL) 
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}
}

void postorder(NODE*root)
{
	NODE*temp=root;
	if(temp!=NULL) 
{
	postorder(temp->left);
	postorder(temp->right);
	printf("%d\t",temp->data);
}
}

NODE*search(NODE*root,int key)
{
	NODE*temp=root;
	while(temp!=NULL)
{
	if(temp->data==key)
	return temp;
		else if(key<temp->data)
		temp=temp->left;
	else
		temp=temp->right;
}
return NULL;
}
void main(){
	NODE*root=NULL;
	NODE *t;
	int ch,k;
do
{
printf("1.create \n 2.search \n 3.inorder\n 4.preorder\n 5.postorder\n 6.exit");
printf("enter your choice ");
scanf("%d",&ch);
switch(ch)
{
case 1:
	root=create_bst(root);
	break;
case 2:
	printf("enter a node you want");
	scanf("%d",&k);
	t=search(root,k);
	if(t==NULL)
		printf("not found");
	else
		printf("found");
	break;
case 3:
	inorder(root);
	break;
case 4:
	preorder(root);
	break;
case 5:
	postorder(root);
	break;
case 6:
	exit(0);
}
}while(ch!=6);
}



