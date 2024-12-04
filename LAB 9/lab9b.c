#include<stdio.h>
#include<conio.h>

void dfs(int, int);
int n, i, j, a[10][10], vis[10], parent[10];
int hasCycle = 0;

void main()
{
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
        parent[i] = -1;
    }

    printf("DFS Traversal:\n");

    for(i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            dfs(i, -1);
        }
    }

    int connected = 1;
    for(i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            connected = 0;
            break;
        }
    }

    if(connected)
        printf("\nThe graph is connected.\n");
    else
        printf("\nThe graph is not connected.\n");

    if(hasCycle)
        printf("\nThe graph contains a cycle.\n");
    else
        printf("\nThe graph does not contain a cycle.\n");

    getch();
}

void dfs(int v, int parentVertex)
{
    vis[v] = 1;
    parent[v] = parentVertex;
    printf("%c ", v + 64);

    for(j = 1; j <= n; j++) {
        if(a[v][j] == 1) {
            if(vis[j] == 0) {
                dfs(j, v);
            }
            else if(vis[j] == 1 && j != parentVertex) {
                hasCycle = 1;
            }
        }
    }
}
