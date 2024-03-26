#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define INF 9999999
typedef struct edge
{
	int src,dest,weight;
}Edge;
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
                        printf("\t");
                }
                printf("\n");
        }
}
int compare(const void *a,const void *b)
{
	Edge *edge1=(Edge *)a;
        Edge *edge2=(Edge *)b;
	return edge1->weight-edge2->weight;
}

void kruskal(int n,int graph[10][10])
{
	Edge result[n];
	int e=0;
	int i=0;
	int u,v,j,x,y;
	int totalweight=0;
	Edge edges[(n *(n-1))/2];
	for(u=0;u<n;u++)
	{
		for(v=u+1;v<n;v++)
		{
			if(graph[u][v]!=0)
			{
				edges[i].src=u;
				edges[i].dest=v;
				edges[i].weight=graph[u][v];
				i++;
			}
		}
	}
qsort(edges,i,sizeof(Edge),compare);
int parent[n];
	for(j=0;j<n;j++)
	{
		parent[j]=-1;	
	}
	i=0;
	while(e<n-1 && i<((n *(n-1))/2))
	{
		Edge next_edges=edges[i++];
		int x=find(parent,next_edges.src);
		int y=find(parent,next_edges.src);
		if(x!=y)
		{
			result[e++]=next_edges;
			totalweight+=next_edges.weight;
			unionset(parent,x,y);
		}
	}
	printf("EDge:weight \n");
	for(i=0;i<e;++i)
		printf("%d - %d:%d \n",result[i].src,result[i].dest,result[i].weight);
	printf("total weight for minimum spanning tree: %d \n",totalweight);	
}
int main()
{
	int n;
	printf("enter the no. vertices\n");
	scanf("%d",&n);
	int m[10][10];
	createmat(m,n);
	dispmat(m,n);
	kruskal(n,m);
	return 0;
}

