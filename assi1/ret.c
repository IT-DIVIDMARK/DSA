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
        printf("enter the data in a node\n");
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

int count(NODE*root)
{
	static int cnt=0;
	NODE *temp=root;
	if(temp!=NULL)
	{
		cnt++;
		count(temp->left);
		count(temp->right);
	}
	return cnt;
}
int countleaf(NODE*root)
{
	static int leaf=0;
	NODE *temp=root;
	if(temp!=NULL)
	{
		if((temp->left==NULL)&&(temp->right==NULL))
			leaf++;
		countleaf(temp->left);
		countleaf(temp->right);
	}
	return leaf;
}
void main()
{
NODE*root=NULL;
int ch,n,ln;

      
        do
        {
                printf("1.create\n 2.total nodes\n3.totalleafnodes\n4.exit\n");
                printf("enter your choice\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:
                               root=create_bst(root);
                                break;
                        case 2:
                      	  n=count(root);
				printf("totalnodes = %d\n",n);
                                break;
                        case 3:
                                 ln =countleaf(root);
				printf("total leafnodes = %d\n",ln);
                                break;
                        case 4:
                                exit(0);
                }
        }while(ch!=4);
}

