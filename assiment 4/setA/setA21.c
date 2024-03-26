#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int vertex;
	struct node*next;
}NODE;
NODE*list[10];
int n;
void createmat(int m[10][10], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            m[i][j] = 0;
            if (i != j)
            {
                printf("\n Is there an edge between %d and %d (1/0) : ", i + 1, j + 1);
                scanf("%d", &m[i][j]);
            }
        }
    }
}
void dispmat(int m[10][10], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d", m[i][j]);
        }
        printf("\n");
    }
}
void createlist(int m[10][10], int n)
{
    int i, j;
    NODE *temp, *newnode;
    for (i = 0; i < n; i++)
    {
        list[i] = NULL; 
        for (j = 0; j < n; j++)
        {
            if (m[i][j] == 1)
            {
                newnode = (NODE *)malloc(sizeof(NODE));
                newnode->vertex = j + 1;
                newnode->next = NULL;
                if (list[i] == NULL)
                {
                    list[i] = temp = newnode;
                }
                else
                {
                    temp->next = newnode;
                    temp = newnode;
                }
            }
        }
    }
}
void displist(int n)
{
    NODE *temp;
    int i;
    printf("The Adjacency List is :\n");
    for (i = 0; i < n; i++)
    {
        printf("V%d->", i + 1);
        temp = list[i];
        while (temp)
        {
            printf("V%d->", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void degree (int m[10][10],int n)
{
int v,in,out,total;
for( v=0;v<n;v++){

 	for(int i=0;i<n;i++)
	{
		int =int m[i][v];
		out=out m[i][v];
	}

}
}
void main(){
	int m[10][10];
	printf("\n enter the no of vertices\n");
	scanf("%d",&n);
	createmat(m,n);
	dispmat(m,n);
	createmat(m,n);
	displist(n);
	degree(m,n);
}
