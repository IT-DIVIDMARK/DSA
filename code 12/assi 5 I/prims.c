#include<stdio.h>
#include<stdbool.h>
#define INF 999
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
int main()
{
	int no_edge,n,i,total=0;
	int m[10][10];
	int j;
	printf("enter the no. vertices\n");
	scanf("%d",&n);
	createmat(m,n);
	dispmat(m,n);
	int selected[n];
	for(i=0;i<n;i++)
		selected[i]=false;
	no_edge=0;
	selected[0]=true;
	int x;
	int y;
	printf("edge:weight\n");
	while(no_edge<n-1)
	{
		int min = INF;
		x=0;
		y=0;
		for(i=0;i<n;i++)
		{
			if(selected[i])
			{
				for(j=0;j<n;j++)
				{
					if(!selected[j] && m[i][j])
					{
						if(min>m[i][j])
						{
							min=m[i][j];
							x=i;
							y=j;
						}
					}
				}
			}
		}
	printf("%d - %d: %d\n",x,y,m[x][y]);
	total=total+m[x][y];
	selected[y]=true;
	no_edge++;
	}	
printf("total=%d",total);
return 0;
}

