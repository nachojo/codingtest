//DFS와 BFS 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_V 1001
using namespace std;
vector<int> vec[MAX_V];
queue<int> q;
int n, m, v;
bool visited[MAX_V], visited1[MAX_V];
void DFS(int vertex)
{
  cout << vertex << " ";
  for (int i = 0; i < vec[vertex].size(); i++)
  {
    int curr = vec[vertex][i];
    if (!visited[curr - 1])
    {
      visited[curr - 1] = true;
      DFS(curr);
    }
  }
}
void BFS()
{

  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    cout << x << " ";
    for (int i = 0; i < vec[x].size(); i++)
    {
      int nx = vec[x][i];
      if (!visited1[nx - 1])
      {
        visited1[nx - 1] = true;
        q.push(nx);
      }
    }
  }
}
int main()
{
  cin >> n >> m >> v;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  //정렬
  for (int i = 1; i <= n; i++)
    sort(vec[i].begin(), vec[i].end());

  for (int i = 0; i < n; i++)
    visited[i] = false;
  visited[v - 1] = true;
  DFS(v);

  cout << endl;
  for (int i = 0; i < n; i++)
    visited1[i] = false;
  q.push(v);
  visited1[v - 1] = true;
  BFS();
}
