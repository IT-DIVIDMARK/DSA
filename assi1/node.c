#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
        struct node *right;
}NODE;
NODE create_bst(NODE *root)
{
        int i,n,num;
        NODE *newnode,*temp,*parent;
        printf("enter node \n");
        scanf("%d",&n);
        printf("enter data \n");
        for(i=0;i<n;i++)
        {
                newnode = (NODE *)malloc(sizeof(NODE));
                scanf("%d",&num);
                newnode->data=num;
                newnode->left=newnode->right=NULL;
                if(root == NULL)
                {
                        root = newnode;
                        continue;
                }
                temp=root;
                while(temp!=NULL)
                {
                        parent = temp;
                        if(num< temp->data)
                                temp=temp->left;
                        else
                                temp=temp->right;
                }
                if(num< parent->data)
                        parent->left=newnode;
                else
                        parent->right=newnode;
        }
        return root;
}

void preorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{
		printf("%d",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void inorder(NODE *root)
{
	NODE *temp =root;
	if(temp1 = NULL)
	{
		inorder(temp->left);
		printf("%d",temp->data);
		inorder(temp->right);
	}
}
void postorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d",temp->data);			
	}
}
NODE *search(NODe *root,int key)
{
	NODE *temp=root;
	while(temp!=NULL)
	{
		if(temp->data==key)
			return temp;
		else if(key < temp->data)
			temp=temp->left;
		else
			temp=temp->right;
	}
}
void main()
{
	int ch;
	do
	{
		printf("1.create\n 2.search\n3.insert\n4.inorder\n5.preorder\n6.postorder\n7.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create_bst(root);
				break;
                        case 2:
                                search(toot);
                                break;
                        case 3:
                                insert(toot);
                                break;
                        case 4:
                                inorder(root);
                                break;
                        case 5:
                                preorder(root);
                                break;
                        case 6:
                                postorder(root);
                                break;
			case 7:
				exit(0);
		}
	}while(ch!=7);
}
