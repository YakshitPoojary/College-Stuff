#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

const int N = 1001; struct Graph
{
int adjacencyMatrix[1001][1001]; int visited[1001];
};

struct Queue
{
int index; int Q[1001];
};

void bfs(struct Graph* g, int node)
{
struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); memset(q -> Q, 0, sizeof(q -> Q));

q -> index = 0;
q -> Q[q -> index] = node; g -> visited[node] = 1; int itr = 0;

while(1)
{
printf("%d ", q -> Q[q -> index]); for(int i = 1; i <= 1000; i++)
{
if(g -> adjacencyMatrix[q-> Q[q -> index]][i] == 1 && g -> visited[i] == 0)
{
g -> visited[i] = 1; itr++;
q -> Q[q -> index + itr] = i;
}
}

if(itr == 0) break;
else
{
q -> index++; itr--;
}
}
}

void dfs(struct Graph* g, int node)
{
g -> visited[node] = 1; printf("%d ", node);

for(int i = 1; i <= 1000; i++)
{
if(g -> visited[i] == 0 && g -> adjacencyMatrix[node][i] == 1)
{
dfs(g, i);
}
}
}

int main()
{

printf("Enter Number of Nodes: "); int n; scanf("%d", &n);
struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph)); memset(g -> adjacencyMatrix, 0, sizeof(g -> adjacencyMatrix));

for(int i = 1; i <= n; i++)
{
for(int j = 1; j <= n; j++)
{
if(g -> adjacencyMatrix[i][j] == 0 && i != j)
{
printf("Press 1 if there is an edge between node %d and node %d, else press 0: ", i, j);
int x; scanf("%d", &x);
g -> adjacencyMatrix[i][j] = g -> adjacencyMatrix[j][i] =
x;
}
}
}

start:

printf("Please Enter the Node Number where You want to start traversal: ");
int x; scanf("%d", &x);

memset(g -> visited, 0, sizeof(g -> visited));

printf("The Breadth First Traversal: "); bfs(g, x); printf("\n");
memset(g -> visited, 0, sizeof(g -> visited)); printf("The Depth first Traversal: ");
dfs(g, x); printf("\n");

printf("Do You Want to Add a new Node? "); scanf("%d", &x);

if(x == 1)
{
n++;
printf("The new Node is %d\n", n);

for(int i = 1; i < n; i++)
{
if(g -> adjacencyMatrix[i][n] == 0)
{
printf("Press 1 if there is an edge between node %d and node %d, else press 0: ", i, n);
int x; scanf("%d", &x);
g -> adjacencyMatrix[i][n] = g -> adjacencyMatrix[n][i] =
x;
}
}
}

if(x == 1) goto start;
}
