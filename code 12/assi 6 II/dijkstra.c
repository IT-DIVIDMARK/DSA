#include<stdio.h>

void dijkstra(int v, int n, int cost[10][10]) 
{
    int i, j, u, w, count, min;
    int dist[10], visited[10] = {0};

    visited[v] = 1;

    for (i = 0; i < n; i++)
        dist[i] = cost[v][i];

    count = 1;

    while (count < n) 
    {
        min = 999;

        for (i = 0; i < n; i++)
            if (visited[i] == 0 && dist[i] < min) 
            {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for (w = 0; w < n; w++)
            if (dist[u] + cost[u][w] < dist[w])
                dist[w] = dist[u] + cost[u][w];

        count++;
    }

    printf("\nShortest distances from vertex %d are: \n", v);
    
    for (i = 0; i < n; i++)
        printf("%d\t", dist[i]);
}

int main() 
{
    int v, n,i,j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int cost[10][10];

    printf("Enter the cost matrix:\n");
    for ( i = 0; i < n; i++)
       for ( j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    dijkstra(v, n, cost);

    return 0;
}
