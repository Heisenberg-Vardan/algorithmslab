#include<iostream>
using namespace std;

void get_matrix(int n, int W[20][20])
{
  cout << "Enter adjacency matrix ";
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin >> W[i][j];
}

void BFS(int n, int W[20][20])
{
    int source;
    int visited[20];
    int queue[20];
    int front = 0, rear = -1, u ,v;

    for(int i=1;i<=n;i++)
        visited[i]=0;

    cout << " Enter the source node: ";
    cin >> source;
    visited[source]=1;

    queue[++rear] = source;
    while(front <= rear)
    {
      u = queue[front++];

      for(v=1; v<=n; v++)
      {
        if(W[u][v] && !visited[v])
        {
          queue[++rear] = v;
          visited[v] = 1;
        }
      }
    }

    for(int i=1; i<=n; i++)
    {
      if(visited[i])
        cout << "Node " << i <<" is reachable. " << endl;
      else
        cout << "Node " << i <<" is not reachable. " <<endl;
    }

}

int main()
{
  int n,W[20][20];

  cout << " Enter number of vertices: ";
  cin >> n;

  get_matrix(n, W);
  BFS(n,W);
  
}


