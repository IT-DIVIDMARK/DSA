#include<stdio.h>
typedef struct node
{
	int vertex;
	struct node *next;
}NODE;
void createmat(int m[10][10],int n)
{
	int i,j;
	char ans;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			m[i][j]=0;
			if(i != j)
			{
				printf("is there an edge between %d and %d(1/0)\n",i+1,j+1);
				scanf("%d",&m[i][j]);
			}
		}
	}
}
void dispmat(int m[10][10],int n)
{
	int i,j;
	char ans;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%5d",m[i][j]);
			printf("\n");
		}
	}
}
void main()
{
	int m[10][10],n;
	printf("\n enter the number of vertices");
	scanf("%d",&n);
	createmat(m,n);
	dispmat(m,n);
}
