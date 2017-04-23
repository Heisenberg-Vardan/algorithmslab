#include <iostream>
using namespace std;

void get_matrix(int n, int W[20][20])
{
	cout << "Enter the matrix: "<< endl;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> W[i][j];
}

void kruskal(int n, int W[20][20])
{
	int min, min_cost = 0;
	int parent[20];
	int numberOfEdges = 1;
	int u,v, a, b;

	for(int i=0; i<n; i++)
		parent[i] = 0;

	while(numberOfEdges < n)
	{
		min = 999;
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(W[i][j] < min)
				{
					min = W[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}

		while(parent[u])
			u = parent[u];
		while(parent[v])
			v = parent[v];

		if(u != v)
		{
			cout <<"Number of edges : " << numberOfEdges++ << endl;
			cout << a << "->" << b << " = " << min << endl;
			min_cost += min;
			parent[v] = u;
		}

		W[a][b] = W[b][a] = 999;

	}

	cout << "Minimum cost = " <<  min_cost << endl;


}

int main()
{
	int n, W[20][20];

	cout << "Enter the numer of vertices: " ;
	cin >> n;

	get_matrix(n,W);
	kruskal(n,W);

	return 0;
}