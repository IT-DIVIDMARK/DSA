#include<stdio.h>
#include<stdio.h>
typedef struct node{
int data;
struct node*left;
struct node*right;
}node;

int getLevelUtil(node*node,int data ,int level)
{
if(node==NULL)
return 0;
if(node->data==data)
return level;
 int downlevel=getLevelUtil(node->left,data,level+1);
	if(downlevel!=0)
	return downlevel;
	downlevel=getLevelUtil(node->right,data,level+1);
	return downlevel;
}
int getlevel(node*node,int data){
	return getLevelUtil(node,data,1);
}


node*newnode(int data){
node*temp=(node*)malloc(sizeof(node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
temp->right=NULL;
return temp;
}


int main(){
node*root;
int x;

root=newnode(3);
root->left=newnode(2);
root->right=newnode(5);
root->left->left=newnode(1);
root->left->right=newnode(4);

for(x=1;x<=5;x++){
int level=getlevel(root,x);

if(level)
	printf("level of %d is %d\n",x,getlevel(root,x));
else
	printf("%d is not present in tree \n",x);
}
getchar();
return 0;
}


