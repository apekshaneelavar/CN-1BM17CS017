#include<bits/stdc++.h>
using namespace std;


int minDistance(int dist[], bool sptSet[],int V) 
{ 
    int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

void printSolution(int dist[],int V) 
{ 
	cout<<("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < V; i++) 
		cout<<i<<"\t\t"<<dist[i]<<endl; 
} 
void dijkstra(int V,int **graph, int src) 
{ 
	int dist[V]; 
	bool sptSet[V]; 
    for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	dist[src] = 0; 
    for (int count = 0; count < V - 1; count++) 
    { 		
		int u = minDistance(dist, sptSet,V); 	
		sptSet[u] = true; 
		for (int v = 0; v < V; v++) 	
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 
	printSolution(dist,V); 
} 

int main() 
{ 
    int V ;
	cout<<"\nEnter size of graph : ";
	cin>>V;
	int **graph = new int*[V];
	
	for(int i=0;i<V;i++)
		graph[i] = new int[V];
	cout<<"\nEnter graph : \n";
	
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			cin>>graph[i][j];
	dijkstra(V,graph, 0); 
	return 0; 
} 

/*
Enter size of graph : 5

Enter graph : 
0 6 0 1 0
6 0 5 2 2
0 5 0 0 5
1 2 0 0 1
0 2 5 1 0
Vertex 		 Distance from Source
0		0
1		3
2		7
3		1
4		2

*/