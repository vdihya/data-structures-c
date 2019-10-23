#include<stdio.h>
int adjlist[10][10],stack[100],queue[100],visited[10];
int front =0; int rear = -1;
int top = -1;
int n;

int main()
{
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    int choice;
    while(1)
    {
    printf("\n1) Create an adjacency list for the graph\n2) BFS\n3) DFS\n4) Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: createlist(); break;
        case 2:
            {
                int i,v;
                for(i=0;i<n;i++)
                    {visited[i] = 0;}
                printf("enter starting vertex: ");
                scanf("%d",&v);
                bfs(v);
            }
            break;
        case 3:
            {
                int i,v;
                for(i=0;i<n;i++)
                {visited[i]=0;}
                printf("enter starting vertex: ");
                scanf("%d",&v);
                dfs(v);

            }
            break;
        case 4: exit(0);
        default: printf("Invalid choice, try again: ");
    }
    }
}
void createlist()
{
    	int i,j,x;

    	for(i=0;i<n;i++)
    	{
     		for(j=0;j<n;j++)
       		{
	 		if(i==j)
	    			adjlist[i][j]=0;
	 		else
{
	 			printf("\n%d to %d",i,j);
	  			printf("\npress 1: connected\npress 0:not connected\nEnter:");
	 			scanf("%d",&x);
	 			adjlist[i][j]=x;
	 		}
       		}
    	}

}

void bfs(int vertex)
{

    if(visited[vertex]==0)
    {
        printf("%d",vertex);
        visited[vertex]=1;
    }
    int i;
    for(i=0;i<n;i++)
    {
        if(adjlist[vertex][i]==1 && visited[i]==0)
            queue[++rear] = i;
    }
    if(front<=rear)
    {
     bfs(queue[front++]);
    }
}

void dfs(int vertex)
{
    if(visited[vertex] == 0)
    {
        visited[vertex] = 1;
        printf("%d",vertex);
        stack[++top] = vertex;

    }
    int i; int v =0;
    for(i=0;i<n;i++)
    {
        if(adjlist[vertex][i]==1)
         {
            dfs(i);
            v = 1;
         }
    }
    if(v==0 && top>=-1)
        dfs(stack[top--]);
}

